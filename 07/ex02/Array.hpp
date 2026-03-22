/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:33:00 by yelu              #+#    #+#             */
/*   Updated: 2026/03/20 02:47:35 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <ctime>

template <typename T>
class Array
{
	private:
		T* _arr;
		size_t _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		unsigned int size() const;
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
	
		class OutOfBoundsException : public std::exception
		{
			public:
				const char *what() const throw();
		};
	};



#include "Array.tpp"

#endif