/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 16:26:57 by yelu              #+#    #+#             */
/*   Updated: 2026/09/05 18:30:01 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
        PmergeMe sorter(argc, argv);
        sorter.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n";
        return (1);
    }
    return (0);
}