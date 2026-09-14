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

class PmergeMe
{
	private:
		std::deque<int>		_deque;
		std::vector<int>	_vector;
		double				_dequeTime;
		double				_vectorTime;

		void				sortDeque();
		void				sortVector();

		static bool 						countingComp(int a, int b);
		int									parsePositiveInteger(const std::string &argv);
		std::vector<int>					mergeInsertSort(std::vector<int> vec);
		std::vector<std::pair<int,int> >	makePairs(std::vector<int> &vec, int &leftovers, bool &hasLeftovers);
		void								buildChains(std::vector<std::pair<int,int> > &pairs,
											std::vector<int> &winners,
											std::vector<int> &mainChain,
											std::vector<int> &pend);
		void								jacobsthalInsert(std::vector<int> &mainChain,
											std::vector<int> &pend,
											std::vector<std::pair<int,int> > &pairs,
											int leftovers, bool hasLeftovers);


	public:

		static int	_compCount;
	
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &other);
		PmergeMe operator=(const PmergeMe &other);
		~PmergeMe();

		void	run();
};

void	printDeque(const std::deque<int> &deq);
void	printVector(const std::vector<int> &vec);
