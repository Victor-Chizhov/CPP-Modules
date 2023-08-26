/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:43:26 by vchizhov          #+#    #+#             */
/*   Updated: 2023/08/08 12:43:28 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
        int index;
    
    public:
        std::string getFirstName();
        void setFirstName(std::string firstNameValue);

        std::string getLastName();
        void setLastName(std::string lastNameValue);

        std::string getNickname();
        void setNickname(std::string nicknameValue);

        std::string getPhoneNumber();
        void setPhoneNumber(std::string phoneNumberValue);

        std::string getDarkestSecret();
        void setDarkestSecret(std::string darkestSecretValue);

        int getIndex();
        void setIndex(int indexValue);
};

#endif

