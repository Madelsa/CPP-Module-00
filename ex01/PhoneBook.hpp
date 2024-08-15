/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:54:16 by mahmoud           #+#    #+#             */
/*   Updated: 2024/08/15 22:16:29 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
    private:
	std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string secret;
    std::string phoneNum;

    public:
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setNickName(std::string nickName);
    void setPhoneNum(std::string phoneNum);
    void setSecret(std::string secret);
    std::string  getFirstName();
    std::string  getLastName();
    std::string  getNickName();
    std::string  getPhoneNum(); 
};

class PhoneBook
{
    private:
	Contact contacts[8];
    int         index;
    
	public:
    void setIndex(int index);
    void setContact(int index, Contact contact);
    Contact getContact(int index);
    int getIndex();
    
};

#endif