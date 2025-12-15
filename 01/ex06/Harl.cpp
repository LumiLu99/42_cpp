/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:10:13 by yelu              #+#    #+#             */
/*   Updated: 2025/12/06 17:40:44 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

enum Level
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    NONE
};

static Level getLevel(std::string level)
{
    if (level == "DEBUG")
        return DEBUG;
    else if (level == "INFO")
        return INFO;
    else if (level == "WARNING")
        return WARNING;
    else if (level == "ERROR")
        return ERROR;
    else
        return NONE;
}

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my \
                7XL-double-cheese-triple-pickle-special-ketchup burger. \
                I really do!" << "\n";
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. \
                You didn’t put enough bacon in my burger! \
                If you did, I wouldn’t be asking for more!" << "\n";
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. \
                I’ve been coming for years whereas you started working \
                here since last month." << "\n";
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << "\n";
}

void Harl::complain(std::string level)
{
    switch(getLevel(level))
    {
        case DEBUG:
            this->debug();
            // fall through
        case INFO:
            this->info();
            // fall through
        case WARNING:
            this->warning();
            // fall through
        case ERROR:
            this->error();
            break;
        case NONE:
            std::cout << "[ Probably complaining about insignificant problems ]" << "\n";
            break;
    }
}
