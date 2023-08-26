/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:43:35 by vchizhov          #+#    #+#             */
/*   Updated: 2023/08/08 12:43:37 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static int index_add = 0;

void PhoneBook::printExit()
{
    exit(0);
}

void PhoneBook::printSearch()
{
    printFourColumn();
    printInformationByIndex();
}

void PhoneBook::printAdd()
{
    std::string data[5];
            
    std::cout << "first name: ";
    std::cin >> data[0];
    std::cout << "last name: ";
    std::cin >> data[1];
    std::cout << "nickname: ";
    std::cin >> data[2];
    std::cout << "phone number: ";
    std::cin >> data[3];
    std::cout << "darkest secret: ";
    std::cin >> data[4]; 

    add(data);

}

void PhoneBook::printInformationByIndex()
{
    std::cout << "Enter index of contact: ";
    std::string index;
    std::cin >> index;
    for (size_t i = 0; i < index.size(); i++) {
        if (index[i] < '0' || index[i] > '9') {
            std::cout << "Index not found" << std::endl;
            return ;
        }
    }

    int in = atoi(index.data());
    int copyGlobalVariable = index_add;

    if (in > copyGlobalVariable - 1)
    {
        std::cout << "Index not found" << std::endl;
        return ;   
    }

    if (in >= 0 && in <= 7)
    {
        std::cout << "First name: " << contacts[in].getFirstName() << std::endl;
        std::cout << "Last name: " << contacts[in].getLastName() << std::endl;
        std::cout << "Nickname: " << contacts[in].getNickname() << std::endl;
        std::cout << "Phone number: " << contacts[in].getPhoneNumber() << std::endl;
        std::cout << "Darkest secret: " << contacts[in].getDarkestSecret() << std::endl;
    }
    else
        std::cout << "Index not found" << std::endl;
}

void PhoneBook::printFourColumn()
{
    std::cout << std::setw(11) << "Index|" << std::setw(11) << "Name|" << std::setw(11) << "Last name|" << std::setw(11) << "Nickname|" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << std::setw(10) << i << "|";
        printFormatted(contacts[i].getFirstName());
        printFormatted(contacts[i].getLastName());
        printFormatted(contacts[i].getNickname());
        std::cout << std::endl;
    };
}

void PhoneBook::printFormatted(const std::string& data)
{
    if (data.size() <= 10)
        std::cout << std::setw(10) << data << "|";
    else
    {
        for (int i = 0; i < 9; i++)
            std::cout << data[i];
        std::cout << ".|";
    }  
}

void PhoneBook::add(std::string *data)
{
    contacts[index_add].setFirstName(data[0]);
    contacts[index_add].setLastName(data[1]);
    contacts[index_add].setNickname(data[2]);
    contacts[index_add].setPhoneNumber(data[3]);
    contacts[index_add].setDarkestSecret(data[4]);
    contacts[index_add].setIndex(index_add);
    index_add++;
    if (index_add == 8) index_add = 0;
}
