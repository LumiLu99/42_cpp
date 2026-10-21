/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 16:26:53 by yelu              #+#    #+#             */
/*   Updated: 2026/09/05 18:37:00 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int PmergeMe::_compCount = 0;

PmergeMe::PmergeMe() : _deque(),
						_vector(),
						_dequeTime(0.0),
						_vectorTime(0.0)
						{}

PmergeMe::PmergeMe(int argc, char**argv)
{
	PmergeMe::_compCount = 0;
	if (argc < 2)
		throw (std::invalid_argument("Usage: ./PmergeMe <positive numbers>"));
	_vector.reserve(argc - 1);
	for (int i = 1; i < argc; i++)
	{
		std::stringstream ss(argv[i]);
		std::string token;
		while (ss >> token)
		{

			int num = parsePositiveInteger(token);
			if (std::find(_vector.begin(), _vector.end(), num) != _vector.end())
				throw (std::invalid_argument("Error: Duplicate number detected"));
			_deque.push_back(num);
			_vector.push_back(num); 
		}
	}
	if (_vector.empty())
		throw (std::invalid_argument("No valid input provided"));
	std::cout << "Before: ";
	printVector(_vector);
	// std::cout << "Deque: ";
	// printDeque(_deque);
}

PmergeMe::PmergeMe(const PmergeMe &other) : _deque(other._deque),
											_vector(other._vector),
											_dequeTime(other._dequeTime),
											_vectorTime(other._vectorTime)
											{}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_deque = other._deque;
		_vector = other._vector;
		_dequeTime = other._dequeTime;
		_vectorTime = other._vectorTime;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::countingComp(int a, int b)
{
	PmergeMe::_compCount++;
	return (a < b);
}

static int F(int n)
{
	int sum = 0;
	for (int k = 1; k <= n; ++k) {
		double value = (3.0 / 4.0) * k;
		sum += static_cast<int>(ceil(log2(value)));
	}
	return (sum);
}

int PmergeMe::parsePositiveInteger(const std::string &argv)
{
	if (argv.empty())
		throw (std::invalid_argument("Argument is empty"));
	if (argv.length() > 10)
		throw (std::invalid_argument("Please enter only positive digits less than INT_MAX (e.g: ./RPN \"8 9\")"));
	for (size_t i = 0; i < argv.length(); i++)
	{
		if (!std::isdigit(argv[i]))
			throw (std::invalid_argument("Please enter only positive digits less than INT_MAX (e.g: ./RPN \"8 9\")"));
	}
	long num = std::strtol(argv.c_str(), NULL, 10);
	if (num < 0 || num > std::numeric_limits<int>::max())
		throw (std::invalid_argument("Please enter only positive digits less than INT_MAX (e.g: ./RPN \"8 9\")"));
	return (static_cast<int>(num));
}

void PmergeMe::run()
{
	int n = _vector.size();
	PmergeMe::_compCount = 0;

	sortData();

	std::cout << "After:  ";
	printVector(_vector);

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vector.size()
	          << " elements with std::vector : " << _vectorTime << " us\n";
	std::cout << "Time to process a range of " << _deque.size()
	          << " elements with std::deque  : " << _dequeTime << " us\n";

	int limit = F(n);
	std::cout << "Comparisons used: " << PmergeMe::_compCount << "\n";
	std::cout << "Max allowed F(" << n << "): " << limit << "\n";
	if (PmergeMe::_compCount > limit)
		std::cerr << "EXCEEDED LIMIT. Failed this project.\n";
	else
		std::cout << "Within limit\n";
}

void	PmergeMe::sortData()
{
	struct timeval start, end;

	gettimeofday(&start, NULL);
	_vector = mergeInsertSort_vect(_vector);
	gettimeofday(&end, NULL);
	_vectorTime = static_cast<double>(end.tv_sec - start.tv_sec) * 1000000.0 + static_cast<double>(end.tv_usec - start.tv_usec);

	gettimeofday(&start, NULL);
	_deque = mergeInsertSort_deq(_deque);
	gettimeofday(&end, NULL);
	_dequeTime = static_cast<double>(end.tv_sec - start.tv_sec) * 1000000.0 + static_cast<double>(end.tv_usec - start.tv_usec);
}

// VECTOR

static std::vector<std::pair<int,int> > sortPairs_vect(std::vector<std::pair<int,int> > &pairs, const std::vector<int> &winners)
{
	std::vector<std::pair<int,int> > sortedPairs;
	for (size_t i = 0; i < winners.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].second == winners[i])
			{
				sortedPairs.push_back(pairs[j]);
				pairs.erase(pairs.begin() + j);
				break;
			}
		}
	}
	return (sortedPairs);
}

std::vector<std::pair<int,int> > PmergeMe::makePairs_vect(std::vector<int> &vec, int &leftovers, bool &hasLeftovers)
{
	std::vector<std::pair<int,int> > pairs;
	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		int a = vec[i];
		int b = vec[i + 1];
		if (a > b)
		{
			std::swap(a, b);
			_compCount++;
		}
		pairs.push_back(std::make_pair(a, b));
	}
	if (vec.size() % 2 != 0)
	{
		leftovers = vec.back();
		hasLeftovers = true;
	}
	return (pairs);
}

void	PmergeMe::buildChains_vect(std::vector<std::pair<int,int> > &pairs, std::vector<int> &winners, std::vector<int> &mainChain, std::vector<int> &pend)
{
	mainChain.push_back(pairs[0].first);
	for (size_t i = 0; i < winners.size(); i++)
	{
		mainChain.push_back(winners[i]);
	}
	for (size_t i = 1; i < pairs.size(); i++)
	{
		pend.push_back(pairs[i].first);
	}
}

void	PmergeMe::jacobsthalInsert_vect(std::vector<int> &mainChain, std::vector<int> &pend, std::vector<std::pair<int,int> > &pairs, int leftovers, bool hasLeftovers)
{
	std::vector<int> jacob;
	jacob.push_back(3);
	jacob.push_back(5);
	while (jacob.back() < static_cast<int>(pend.size()))
	{
		int n = jacob.size();
		jacob.push_back(jacob[n-1] + 2 * jacob[n-2]);
	}
	int prev = 0;
	for (size_t k = 0; k < jacob.size(); k++)
	{
		int curr = std::min(jacob[k], static_cast<int>(pend.size()));

		for (int j = curr - 1; j >= prev; j--)
		{
			int pairedWinner = pairs[j + 1].second;
			std::vector<int>::iterator bound = std::find(
				mainChain.begin(), mainChain.end(), pairedWinner
			);

			std::vector<int>::iterator pos = std::lower_bound(
				mainChain.begin(), bound, pend[j], countingComp
			);
			mainChain.insert(pos, pend[j]);
		}
		prev = curr;
		if (prev >= static_cast<int>(pend.size()))
			break;
	}
	if (hasLeftovers)
	{
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftovers, countingComp);
		mainChain.insert(pos, leftovers);
	}
}

std::vector<int> PmergeMe::mergeInsertSort_vect(std::vector<int> vec)
{
	if (vec.size() <= 1)
		return (vec);
	int		leftovers = 0;
	bool	hasLeftovers = false;
	std::vector<std::pair<int,int> > pairs = makePairs_vect(vec, leftovers, hasLeftovers);
	std::vector<int> winners;
	for (size_t i = 0; i < pairs.size(); i++)
		winners.push_back(pairs[i].second);
	winners = mergeInsertSort_vect(winners);
	pairs = sortPairs_vect(pairs, winners);
	std::vector<int> mainChain;
	std::vector<int> pend;
	buildChains_vect(pairs, winners, mainChain, pend);
	jacobsthalInsert_vect(mainChain, pend, pairs, leftovers, hasLeftovers);
	return (mainChain);
}

// DEQUE SORT

static std::deque<std::pair<int,int> > sortPairs_deq(const std::deque<std::pair<int,int> > &pairs, const std::deque<int> &winners)
{
	std::deque<std::pair<int,int> > sortedPairs;
	for (size_t i = 0; i < winners.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].second == winners[i])
			{
				sortedPairs.push_back(pairs[j]);
				break;
			}
		}
	}
	return (sortedPairs);
}

std::deque<std::pair<int,int> > PmergeMe::makePairs_deq(std::deque<int> &deq, int &leftovers, bool &hasLeftovers)
{
	std::deque<std::pair<int,int> > pairs;
	for (size_t i = 0; i + 1 < deq.size(); i += 2)
	{
		int a = deq[i];
		int b = deq[i + 1];
		if (a > b)
		{
			std::swap(a, b);
		}
		pairs.push_back(std::make_pair(a, b));
	}
	if (deq.size() % 2 != 0)
	{
		leftovers = deq.back();
		hasLeftovers = true;
	}
	return (pairs);
}

void	PmergeMe::buildChains_deq(std::deque<std::pair<int,int> > &pairs, std::deque<int> &winners, std::deque<int> &mainChain, std::deque<int> &pend)
{
	mainChain.push_back(pairs[0].first);
	for (size_t i = 0; i < winners.size(); i++)
	{
		mainChain.push_back(winners[i]);
	}
	for (size_t i = 1; i < pairs.size(); i++)
	{
		pend.push_back(pairs[i].first);
	}
}

void	PmergeMe::jacobsthalInsert_deq(std::deque<int> &mainChain, std::deque<int> &pend, std::deque<std::pair<int,int> > &pairs, int leftovers, bool hasLeftovers)
{
	std::vector<int> jacob;
	jacob.push_back(3);
	jacob.push_back(5);
	while (jacob.back() < static_cast<int>(pend.size()))
	{
		int n = jacob.size();
		jacob.push_back(jacob[n-1] + 2 * jacob[n-2]);
	}
	int prev = 0;
	for (size_t k = 0; k < jacob.size(); k++)
	{
		int curr = std::min(jacob[k], static_cast<int>(pend.size()));

		for (int j = curr - 1; j >= prev; j--)
		{
			int pairedWinner = pairs[j + 1].second;
			std::deque<int>::iterator bound = std::find(
				mainChain.begin(), mainChain.end(), pairedWinner
			);

			std::deque<int>::iterator pos = std::lower_bound(
				mainChain.begin(), bound, pend[j]
			);
			mainChain.insert(pos, pend[j]);
		}
		prev = curr;
		if (prev >= static_cast<int>(pend.size()))
			break;
	}
	if (hasLeftovers)
	{
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftovers);
		mainChain.insert(pos, leftovers);
	}
}

std::deque<int> PmergeMe::mergeInsertSort_deq(std::deque<int> deq)
{
	if (deq.size() <= 1)
		return (deq);
	int		leftovers = 0;
	bool	hasLeftovers = false;
	std::deque<std::pair<int,int> > pairs = makePairs_deq(deq, leftovers, hasLeftovers);
	std::deque<int> winners;
	for (size_t i = 0; i < pairs.size(); i++)
		winners.push_back(pairs[i].second);
	winners = mergeInsertSort_deq(winners);
	pairs = sortPairs_deq(pairs, winners);
	std::deque<int> mainChain;
	std::deque<int> pend;
	buildChains_deq(pairs, winners, mainChain, pend);
	jacobsthalInsert_deq(mainChain, pend, pairs, leftovers, hasLeftovers);
	return (mainChain);
}

void	printVector(const std::vector<int> &vec)
{
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
}

void	printDeque(const std::deque<int> &deq)
{
	for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
}



//   The rule: insert from the larger bound first, while the chain is still short.

// int binarySearch(const std::vector<int> &chain, int target, int boundIndex)
// {
// 	int left = 0;
// 	int right = boundIndex - 1;

// 	while (left <= right)
// 	{
// 		int mid = left + (right - left) / 2;
// 		PmergeMe::_compCount++;
// 		if (chain[mid] < target)
// 			left = mid + 1;
// 		else
// 			right = mid - 1;
// 	}
// 	return (left);
// }
