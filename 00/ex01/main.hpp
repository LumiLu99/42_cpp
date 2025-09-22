/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 21:34:56 by yelu              #+#    #+#             */
/*   Updated: 2025/09/16 15:02:22 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PB_HPP
#define PB_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

enum Command
{
	ADD,
	SEARCH,
	EXIT,
	INVALID
};



#endif