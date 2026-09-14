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
			_deque.push_back(num);
			_vector.push_back(num); 
		}
	}
	if (_vector.empty())
		throw (std::invalid_argument("No valid input provided"));
	std::cout << "Before vector: ";
	printVector(_vector);
	// std::cout << "Deque: ";
	// printDeque(_deque);
}

// PmergeMe::PmergeMe(const PmergeMe &other)
// {
	
// }

// PmergeMe PmergeMe::operator=(const PmergeMe &other)
// {
	
// }

PmergeMe::~PmergeMe()
{
	
}

bool PmergeMe::countingComp(int a, int b)
{
	PmergeMe::_compCount++;
	return a < b;
}

static int F(int n)
{
	int sum = 0;
	for (int k = 1; k <= n; ++k) {
		double value = (3.0 / 4.0) * k;
		sum += static_cast<int>(ceil(log2(value)));
	}
	return sum;
}

int PmergeMe::parsePositiveInteger(const std::string &argv)
{
	if (argv.empty())
		throw (std::invalid_argument("Argument is empty"));
	if (argv.length() > 10)
		throw (std::invalid_argument("Please enter only positive digits less than INT_MAX and exclude any signs"));
	for (size_t i = 0; i < argv.length(); i++)
	{
		if (!std::isdigit(argv[i]))
			throw (std::invalid_argument("Please enter only positive digits less than INT_MAX and exclude any signs"));
	}
	long num = std::strtol(argv.c_str(), NULL, 10);
	if (num < 0 || num > std::numeric_limits<int>::max())
		throw (std::invalid_argument("Please enter only positive digits less than INT_MAX and exclude any signs"));
	return (static_cast<int>(num));
}

void PmergeMe::run()
{
	int n = _vector.size();
	PmergeMe::_compCount = 0;

	sortVector();

	int limit = F(n);
	std::cout << "Comparisons used: " << PmergeMe::_compCount << "\n";
	std::cout << "Max allowed F(" << n << "): " << limit << "\n";
	if (PmergeMe::_compCount > limit)
		std::cerr << "❌ EXCEEDED LIMIT\n";
	else
		std::cout << "✅ Within limit\n";
	std::cout << "After vector: ";
	printVector(_vector);
}

void	PmergeMe::sortVector()
{
	_vector = mergeInsertSort(_vector);
}

static bool comparePairBySecond(const std::pair<int,int> &a, const std::pair<int,int> &b)
{
	return (a.second < b.second);
}

std::vector<int> PmergeMe::mergeInsertSort(std::vector<int> vec)
{
	if (vec.size() <= 1)
		return (vec);
	int		leftovers;
	bool	hasLeftovers = false;
	std::vector<std::pair<int,int> > pairs = makePairs(vec, leftovers, hasLeftovers);
	std::vector<int> winners;
	for (size_t i = 0; i < pairs.size(); i++)
		winners.push_back(pairs[i].second);
	winners = mergeInsertSort(winners);
	std::sort(pairs.begin(), pairs.end(), comparePairBySecond);
	std::vector<int> mainChain;
	std::vector<int> pend;
	buildChains(pairs, winners, mainChain, pend);
	jacobsthalInsert(mainChain, pend, pairs, leftovers, hasLeftovers);
	return (mainChain);
}

void	PmergeMe::buildChains(std::vector<std::pair<int,int> > &pairs, std::vector<int> &winners, std::vector<int> &mainChain, std::vector<int> &pend)
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

void	PmergeMe::jacobsthalInsert(std::vector<int> &mainChain, std::vector<int> &pend, std::vector<std::pair<int,int> > &pairs, int leftovers, bool hasLeftovers)
{
	std::vector<int> jacob;
	jacob.push_back(3);
	jacob.push_back(5);
	while (jacob.back() < (int)pend.size())
	{
		int n = jacob.size();
		jacob.push_back(jacob[n-1] + 2 * jacob[n-2]);
	}
	int prev = 0;
	for (size_t k = 0; k < jacob.size(); k++)
	{
		// cap at pend size
		int curr = std::min(jacob[k], (int)pend.size());

		// insert backwards within this group
		for (int j = curr - 1; j >= prev; j--)
		{
			// find paired winner's position (upper bound for binary search)
			int pairedWinner = pairs[j + 1].second;
			std::vector<int>::iterator bound = std::find(
				mainChain.begin(), mainChain.end(), pairedWinner
			);

			// binary search only up to paired winner
			std::vector<int>::iterator pos = std::lower_bound(
				mainChain.begin(), bound, pend[j], countingComp
			);
			mainChain.insert(pos, pend[j]);
		}

		prev = curr;
		if (prev >= (int)pend.size())
			break;
	}
	if (hasLeftovers)
	{
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftovers, countingComp);
		mainChain.insert(pos,leftovers);
	}
}


std::vector<std::pair<int,int> > PmergeMe::makePairs(std::vector<int> &vec, int &leftovers, bool &hasLeftovers)
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