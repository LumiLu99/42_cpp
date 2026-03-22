/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:33:50 by yelu              #+#    #+#             */
/*   Updated: 2026/03/20 02:52:42 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

template <typename T>
Array<T>::Array() : _arr(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	if (n > 0)
		_arr = new T[n]();
	else
		_arr = NULL;
}

template <typename T>
Array<T>::Array(const Array& other) : _arr(NULL), _size(0)
{
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		if (this->_arr)
			delete[] this->_arr;
		
		this->_size = other._size;

		if (this->_size > 0)
		{
			this->_arr = new T[this->_size]();
			for (unsigned int i = 0; i < this->_size; i++)
				this->_arr[i] = other._arr[i];
		}
		else
		{
			this->_arr = NULL;
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	if (this->_arr)
		delete[] this->_arr;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw Array<T>::OutOfBoundsException();
	return _arr[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= size)
		throw Array<T>::OutOfBoundsException();
	return _arr[index];
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return "Error: Index out of bounds!!\n";
}

