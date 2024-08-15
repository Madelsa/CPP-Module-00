/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:14:24 by mahmoud           #+#    #+#             */
/*   Updated: 2024/08/15 21:50:36 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::setContact(int index, Contact contact)
{
    contacts[index] = contact;
}

void Contact::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
    this->lastName = lastName;
}

void Contact::setNickName(std::string nickName)
{
   this->nickName = nickName; 
}

void Contact::setPhoneNum(std::string phoneNum)
{
    this->phoneNum = phoneNum;
}

void Contact::setSecret(std::string secret)
{
    this->secret = secret;
}
void PhoneBook::setIndex(int index)
{
    this->index = index;
}

Contact PhoneBook::getContact(int index)
{
    return (contacts[index]);
}

std::string Contact::getFirstName(void)
{
    return (firstName);
}

std::string  Contact::getLastName(void)
{
    return (lastName);
}

std::string  Contact::getNickName(void)
{
    return (nickName);
}

std::string  Contact::getPhoneNum(void)
{
    return (phoneNum);
}

int PhoneBook::getIndex()
{
    return (index);
}





