/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:01:09 by yelu              #+#    #+#             */
/*   Updated: 2026/07/27 21:50:03 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// stack member function empty, size, push, pop, top

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {}
		// Explicitly call the parent's copy constructor logic by inheriting from std::stack
		MutantStack(const MutantStack<T> &other) : std::stack<T>(other) {}
		
		MutantStack<T>& operator=(const MutantStack<T> &other)
		{
			if (this != &other)
			{
				std::stack<T>::operator=(other);
			}
			return (*this);
		}
		
		~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
		const_iterator begin() const {return this->c.begin();}
		const_iterator end() const {return this->c.end();}

		reverse_iterator rbein() {return this->c.rbegin();}
		reverse_iterator rend() {return this->c.rend();}
		const_reverse_iterator rbegin() const {return this->c.rbegin();}
		const_reverse_iterator rend() const {return this->c.rend();}
};

#endif