/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 16:26:50 by yelu              #+#    #+#             */
/*   Updated: 2026/09/05 18:21:45 by yelu             ###   ########.fr       */
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

		static bool 						countingComp(int a, int b);
		int									parsePositiveInteger(const std::string &argv);
		
		// Vector
		std::vector<std::pair<int,int> >	makePairs_vect(std::vector<int> &vec, int &leftovers, bool &hasLeftovers);
		std::vector<int>					mergeInsertSort_vect(std::vector<int> vec);
		void								buildChains_vect(std::vector<std::pair<int,int> > &pairs,
											std::vector<int> &winners,
											std::vector<int> &mainChain,
											std::vector<int> &pend);
		void								jacobsthalInsert_vect(std::vector<int> &mainChain,
											std::vector<int> &pend,
											std::vector<std::pair<int,int> > &pairs,
											int leftovers, bool hasLeftovers);

		// Deque
		std::deque<std::pair<int,int> >		makePairs_deq(std::deque<int> &deq, int &leftovers, bool &hasLeftovers);
		std::deque<int>						mergeInsertSort_deq(std::deque<int> deq);
		void								buildChains_deq(std::deque<std::pair<int,int> > &pairs,
											std::deque<int> &winners,
											std::deque<int> &mainChain,
											std::deque<int> &pend);
		void								jacobsthalInsert_deq(std::deque<int> &mainChain,
											std::deque<int> &pend,
											std::deque<std::pair<int,int> > &pairs,
											int leftovers, bool hasLeftovers);


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
