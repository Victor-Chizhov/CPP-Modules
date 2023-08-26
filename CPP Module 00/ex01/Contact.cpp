/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:43:18 by vchizhov          #+#    #+#             */
/*   Updated: 2023/08/08 12:43:20 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName() { return firstName; }
void Contact::setFirstName(std::string firstNameValue) { firstName = firstNameValue; }

std::string Contact::getLastName() { return lastName; }
void Contact::setLastName(std::string lastNameValue) { lastName = lastNameValue; }

std::string Contact::getNickname() { return nickname; }
void Contact::setNickname(std::string nicknameValue) { nickname = nicknameValue; }

std::string Contact::getPhoneNumber() { return phoneNumber; }
void Contact::setPhoneNumber(std::string phoneNumberValue) { phoneNumber = phoneNumberValue; }

std::string Contact::getDarkestSecret() { return darkestSecret; }
void Contact::setDarkestSecret(std::string darkestSecretValue) { darkestSecret = darkestSecretValue; }

int Contact::getIndex() { return index; }
void Contact::setIndex(int indexValue) { index = indexValue; }
