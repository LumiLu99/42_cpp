/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 16:26:50 by yelu              #+#    #+#             */
/*   Updated: 2026/10/30 11:26:05 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <deque>
#include <vector>
#include <limits>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <sys/time.h>
#include <iomanip>

class PmergeMe
{
	private:
		std::deque<int>		_deque;
		std::vector<int>	_vector;
		double				_dequeTime;
		double				_vectorTime;

		void				sortData();

		// bool countingComp(std::vector<int>::iterator a, std::vector<int>::iterator b);
		int		parsePositiveInteger(const std::string &argv);

		// Vector
		void	mergeInsertSort_vect(std::vector<int>& vec, int pairLevel);

		// Deque
		void	mergeInsertSort_deq(std::deque<int>& vec, int pairLevel);
		void	sortChunks_deq(std::deque<int>& deq, int pairLevel);
		// bool	countingComp_deq(std::deque<int>::iterator a, std::deque<int>::iterator b);
		void	swapGroups_deq(std::deque<int>::iterator groupA, std::deque<int>::iterator groupB, int pairLevel);
		void	buildChains_deq(std::deque<int>& deq, std::deque<std::deque<int>::iterator>& mainChain, std::deque<std::deque<int>::iterator>& pend, int numGroups, int pairLevel);
		void	jacobsthalInsert_deq(std::deque<int>& vec, std::deque<std::deque<int>::iterator>& mainChain, std::deque<std::deque<int>::iterator>& pend, int pairLevel);
		void 	reconstructSortedDeque(std::deque<int>& vec, std::deque<std::deque<int>::iterator>& mainChain, int pairLevel);


	public:

		static int	_compCount;
		
		PmergeMe();
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	run();
};

void	printDeque(const std::deque<int> &deq);
void	printVector(const std::vector<int> &vec);
