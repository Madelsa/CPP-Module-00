/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:54:16 by mahmoud           #+#    #+#             */
/*   Updated: 2024/08/12 19:01:49 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
    public:
	std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string secret;
    std::string phoneNum;
};

class PhoneBook
{
	public:
	Contact contacts[8];
    int         index;
};

#endif