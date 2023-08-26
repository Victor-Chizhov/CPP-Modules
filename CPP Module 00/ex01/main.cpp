/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:43:54 by vchizhov          #+#    #+#             */
/*   Updated: 2023/08/08 12:43:57 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phone;
    std::string command;
    
    while(1)
    {
        std::cout << "Enter command: ";
        std::cin >> command;
        if(command.compare("ADD") == 0)
            phone.printAdd();
        else if (command.compare("SEARCH") == 0)
            phone.printSearch();
        else if (command.compare("EXIT") == 0)
            phone.printExit();
        else
            std::cout << "Error command" << std::endl;
        command.erase();
    }
    return (0);
}
