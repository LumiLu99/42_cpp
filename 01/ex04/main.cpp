/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 00:31:14 by yelu              #+#    #+#             */
/*   Updated: 2025/12/01 09:08:17 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
        return (1);
    }
    else
    {
        std::string inFile = argv[1];
        std::string outFile = inFile + ".replace";
        std::string s1 = argv[2];
        std::string s2 = argv[3];

        std::ifstream ifs(inFile.c_str());
        if (!ifs.is_open())
        {
            std::cerr << "Error opening " << inFile << "\n";
            return (1); 
        }
        std::ofstream ofs(outFile.c_str());
        if (!ofs.is_open())
        {
            std::cerr << "Error creating " << outFile << "\n";
            ifs.close();
            return (1);
        }
        std::stringstream buffer;
        buffer << ifs.rdbuf();
        std::string text = buffer.str();
        if (s1.empty())
            ofs << text;
        else
        {
            size_t pos = 0;
            while ((pos = text.find(s1, pos)) != std::string::npos)
            {
                text.erase(pos, s1.length());
                text.insert(pos, s2);
                pos += s2.length();
            }
            ofs << text;
        }
    }
}
