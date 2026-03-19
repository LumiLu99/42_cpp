/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 21:25:35 by yelu              #+#    #+#             */
/*   Updated: 2026/03/18 22:14:48 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void )
{
    int a = 7;
    int b = 2;

    std::cout << "\n\n==  int ==\n";
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";
    
    std::cout << "\n\n==  string ==\n";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    double e = 95.2;
    double f = 25.4;
    
    std::cout << "\n\n==  double ==\n";
    ::swap(e, f);
    std::cout << "e = " << e << ", f = " << f << "\n";
    std::cout << "min(e, f) = " << ::min(e, f) << "\n";
    std::cout << "max(e, f) = " << ::max(e, f) << "\n";

    char aa = 'a';
    char bb = 'b';
    ::swap(aa, bb);

    std::cout << "\n\n== char ==\n";
    std::cout << "aa = " << aa << ", bb = " << bb << "\n";
    std::cout << "min(aa, bb) = " << ::min(aa, bb) << "\n";
    std::cout << "max(aa, bb) = " << ::max(aa, bb) << "\n";
    return 0;
}
