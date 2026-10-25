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

static int F(int n)
{
	int sum = 0;
	for (int k = 1; k <= n; ++k) {
		double value = (3.0 / 4.0) * k;
		sum += static_cast<int>(ceil(log2(value)));
	}
	return (sum);
}

PmergeMe::~PmergeMe() {}

static bool countingComp(std::vector<int>::iterator a, std::vector<int>::iterator b)
{
	PmergeMe::_compCount++;
	return (*a < *b);
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

	std::cout << "Vector After:  ";
	printVector(_vector);
	std::cout << "Deque After: ";
	printDeque(_deque);

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
	mergeInsertSort_vect(_vector, 1);
	gettimeofday(&end, NULL);
	_vectorTime = static_cast<double>(end.tv_sec - start.tv_sec) * 1000000.0 + static_cast<double>(end.tv_usec - start.tv_usec);

	gettimeofday(&start, NULL);
	mergeInsertSort_deq(_deque, 1);
	gettimeofday(&end, NULL);
	_dequeTime = static_cast<double>(end.tv_sec - start.tv_sec) * 1000000.0 + static_cast<double>(end.tv_usec - start.tv_usec);
}

static void swapGroups(std::vector<int>::iterator groupA, std::vector<int>::iterator groupB, int pairLevel)
{
	for (int i = 0; i < pairLevel; i++)
	{
		std::iter_swap(groupA + i, groupB + i);
	}
}

static void sortChunks(std::vector<int>& vec, int pairLevel)
{
	int step = 2 * pairLevel;
	int numGroups = vec.size() / pairLevel;
	int numPairs =  numGroups / 2;

	for (int i = 0; i < numPairs; i++)
	{
		std::vector<int>::iterator groupA = vec.begin() + (i * step);
		std::vector<int>::iterator groupB = groupA + pairLevel;

		// The winner of a group is the last element (group + pairLevel - 1)
		std::vector<int>::iterator winnerA = groupA + (pairLevel - 1);
		std::vector<int>::iterator winnerB = groupB + (pairLevel - 1);

		// Knuth comparison: if winnder A > winnerB, swap the two groups
		if (countingComp(winnerB, winnerA))
		{
			swapGroups(groupA, groupB, pairLevel);
		}
	}
}

static void buildChains(std::vector<int>& vec, 	std::vector<std::vector<int>::iterator>& mainChain, std::vector<std::vector<int>::iterator>& pend, int numGroups, int pairLevel)
{
	mainChain.push_back(vec.begin() + 1 * pairLevel - 1);
	mainChain.push_back(vec.begin() + 2 * pairLevel - 1);
	for (int i = 3; i <= numGroups; i++)
	{
		if (i % 2 == 1)
			pend.push_back(vec.begin() + i * pairLevel - 1);
		else
			mainChain.push_back(vec.begin() + i * pairLevel - 1);
	}
}

static void jacobsthalInsert(std::vector<int>& vec, std::vector<std::vector<int>::iterator>& mainChain, std::vector<std::vector<int>::iterator>& pend, int pairLevel)
{
		int numGroups = vec.size() / pairLevel;
        int lastB = pend.size() + 1;
        int prevJ = 1;
        int currJ = 3;

        while (prevJ < lastB)
        {
            int startB = std::min(currJ, lastB);
            for (int b = startB; b > prevJ; --b)
            {
                 std::vector<int>::iterator itemToInsert = pend[b - 2];

                // Find where partner a_b currently sits in mainChain
                std::vector<std::vector<int>::iterator>::iterator bound = mainChain.end();
                int partnerChunk = 2 * b;
                if (partnerChunk <= numGroups)
                {
                    std::vector<int>::iterator partnerLeader = vec.begin() + partnerChunk * pairLevel - 1;
                    bound = std::find(mainChain.begin(), mainChain.end(), partnerLeader);
                }

                // Binary search in [begin, bound) and insert
                std::vector<std::vector<int>::iterator>::iterator pos =
                	std::upper_bound(mainChain.begin(), bound, itemToInsert, countingComp);
                mainChain.insert(pos, itemToInsert);
            }
            int nextJ = currJ + 2 * prevJ;
            prevJ = currJ;
            currJ = nextJ;
        }
}

static void reconstructSortedVector(std::vector<int>& vec, std::vector<std::vector<int>::iterator>& mainChain, int pairLevel)
{
	std::vector<int> temp;
	temp.reserve(vec.size());
	for (size_t i = 0; i < mainChain.size(); i++)
	{
		std::vector<int>::iterator chunkStart = mainChain[i] - (pairLevel - 1);
		for (int j = 0; j < pairLevel; j++)
		{
			temp.push_back(*(chunkStart + j));
		}
	}
	std::copy(temp.begin(), temp.end(), vec.begin());
}

void PmergeMe::mergeInsertSort_vect(std::vector<int>& vec, int pairLevel)
{
	int numGroups = vec.size() / pairLevel;
	if (numGroups < 2)
		return ;
	sortChunks(vec, pairLevel);
	mergeInsertSort_vect(vec, (pairLevel * 2));
	std::vector<std::vector<int>::iterator> mainChain;
	std::vector<std::vector<int>::iterator> pend;
	buildChains(vec, mainChain, pend, numGroups, pairLevel);
	jacobsthalInsert(vec, mainChain, pend, pairLevel);
	reconstructSortedVector(vec, mainChain, pairLevel);
}

// DEQUE

static bool countingComp_deq(std::deque<int>::iterator a, std::deque<int>::iterator b)
{
	return (*a < *b);
}

void PmergeMe::mergeInsertSort_deq(std::deque<int>& deq, int pairLevel)
{
	int numGroups = deq.size() / pairLevel;
	if (numGroups < 2)
		return ;
	sortChunks_deq(deq, pairLevel);
	mergeInsertSort_deq(deq, (pairLevel * 2));
	std::deque<std::deque<int>::iterator> mainChain;
	std::deque<std::deque<int>::iterator> pend;
	buildChains_deq(deq, mainChain, pend, numGroups, pairLevel);
	jacobsthalInsert_deq(deq, mainChain, pend, pairLevel);
	reconstructSortedDeque(deq, mainChain, pairLevel);
}

void PmergeMe::buildChains_deq(std::deque<int>& deq, std::deque<std::deque<int>::iterator>& mainChain, std::deque<std::deque<int>::iterator>& pend, int numGroups, int pairLevel)
{
	mainChain.push_back(deq.begin() + 1 * pairLevel - 1);
	mainChain.push_back(deq.begin() + 2 * pairLevel - 1);
	for (int i = 3; i <= numGroups; i++)
	{
		if (i % 2 == 1)
			pend.push_back(deq.begin() + i * pairLevel - 1);
		else
			mainChain.push_back(deq.begin() + i * pairLevel - 1);
	}
}

void PmergeMe::jacobsthalInsert_deq(std::deque<int>& vec, std::deque<std::deque<int>::iterator>& mainChain, std::deque<std::deque<int>::iterator>& pend, int pairLevel)
{
		int numGroups = vec.size() / pairLevel;
        int lastB = pend.size() + 1;
        int prevJ = 1;
        int currJ = 3;

        while (prevJ < lastB)
        {
            int startB = std::min(currJ, lastB);
            for (int b = startB; b > prevJ; --b)
            {
                 std::deque<int>::iterator itemToInsert = pend[b - 2];

                // Find where partner a_b currently sits in mainChain
                std::deque<std::deque<int>::iterator>::iterator bound = mainChain.end();
                int partnerChunk = 2 * b;
                if (partnerChunk <= numGroups)
                {
                    std::deque<int>::iterator partnerLeader = vec.begin() + partnerChunk * pairLevel - 1;
                    bound = std::find(mainChain.begin(), mainChain.end(), partnerLeader);
                }

                // Binary search in [begin, bound) and insert
                std::deque<std::deque<int>::iterator>::iterator pos =
                	std::upper_bound(mainChain.begin(), bound, itemToInsert, countingComp_deq);
                mainChain.insert(pos, itemToInsert);
            }
            int nextJ = currJ + 2 * prevJ;
            prevJ = currJ;
            currJ = nextJ;
        }
}

void PmergeMe::reconstructSortedDeque(std::deque<int>& vec, std::deque<std::deque<int>::iterator>& mainChain, int pairLevel)
{
	std::deque<int> temp;
	for (size_t i = 0; i < mainChain.size(); i++)
	{
		std::deque<int>::iterator chunkStart = mainChain[i] - (pairLevel - 1);
		for (int j = 0; j < pairLevel; j++)
		{
			temp.push_back(*(chunkStart + j));
		}
	}
	std::copy(temp.begin(), temp.end(), vec.begin());
}

void PmergeMe::swapGroups_deq(std::deque<int>::iterator groupA, std::deque<int>::iterator groupB, int pairLevel)
{
	for (int i = 0; i < pairLevel; i++)
	{
		std::iter_swap(groupA + i, groupB + i);
	}
}

void PmergeMe::sortChunks_deq(std::deque<int>& deq, int pairLevel)
{
	int step = 2 * pairLevel;
	int numGroups = deq.size() / pairLevel;
	int numPairs =  numGroups / 2;

	for (int i = 0; i < numPairs; i++)
	{
		std::deque<int>::iterator groupA = deq.begin() + (i * step);
		std::deque<int>::iterator groupB = groupA + pairLevel;

		// The winner of a group is the last element (group + pairLevel - 1)
		std::deque<int>::iterator winnerA = groupA + (pairLevel - 1);
		std::deque<int>::iterator winnerB = groupB + (pairLevel - 1);

		// Knuth comparison: if winnder A > winnerB, swap the two groups
		if (countingComp_deq(winnerB, winnerA))
		{
			swapGroups_deq(groupA, groupB, pairLevel);
		}
	}
}


// PRINTING

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
