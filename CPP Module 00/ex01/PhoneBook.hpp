/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:43:46 by vchizhov          #+#    #+#             */
/*   Updated: 2023/08/08 12:43:47 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        
        void add(std::string *data);
        void printFormatted(const std::string &data);
        void printFourColumn();
        void printInformationByIndex();

    public:
        void printAdd();
        void printSearch();
        void printExit();

};

#endif
