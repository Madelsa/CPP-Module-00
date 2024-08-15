/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:18:23 by mahmoud           #+#    #+#             */
/*   Updated: 2024/08/15 22:06:17 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string trim(std::string &str) {
    size_t start = 0;
    while (start < str.length() && (str[start] == ' ' || (str[start] >= 9 && str[start] <= 13)))
    {
        start++;
    }
    size_t end = str.length();
    while (end > start && (str[end - 1] == ' ' || (str[end - 1] >= 9 && str[end - 1] <= 13))) 
    {
        end--;
    }
    return str.substr(start, end - start);
}

void getInput(std::string &field, const std::string &prompt)
{
    do
    {
        std::cout << prompt << std::endl;
        if (!std::getline(std::cin, field))
        {
            std::cout << "End of input detected. Exiting the program." << std::endl;
            exit (0);
        }
        field = trim(field);
        if (field.empty())
        {
            std::cout << "Input cannot be empty. Please try again." << std::endl;
        }
    } while (field.empty());
    std::cout << std::endl;
}

void checkIndex(std::string &selectedIndex, PhoneBook &pB)
{
    bool valid = false;

    do
    {
        if (pB.getContact(0).getFirstName().empty())
        {
            std::cout << "Phonebook has no entries." << std::endl;
            return ;
        }
        getInput(selectedIndex, "Type the phonebook index to display:");
        bool digitEntry = true;
        for (size_t i = 0; i < selectedIndex.length(); ++i)
        {
            if (!std::isdigit(selectedIndex[i]))
            {
                digitEntry = false;
                break;
            }
        }
        if (digitEntry)
        {
            try
            {
                int selectedIndexInt = std::stoi(selectedIndex);
                if (selectedIndexInt >= 1 && selectedIndexInt <= 8)
                {
                    if (pB.getContact(selectedIndexInt - 1).getFirstName().empty())
                    {
                        std::cout << "Selected index entry is empty." << std::endl;
                        return ;
                    }
                    else
                    {
                        system("clear");
                        std::cout << "First Name: " << pB.getContact(selectedIndexInt - 1).getFirstName() << std::endl;
                        std::cout << "Last Name: " << pB.getContact(selectedIndexInt - 1).getLastName() << std::endl;
                        std::cout << "Nickname: " << pB.getContact(selectedIndexInt - 1).getNickName() << std::endl;
                        std::cout << "Phone Number: " << pB.getContact(selectedIndexInt - 1).getPhoneNum() << std::endl;
                        std::cout << std::endl;
                        valid = true;
                    }
                }
                else
                {
                    std::cout << "Selected index is out of bounds. Please enter a number between 1 and 8." 
                    << std::endl;
                }
            }
            catch (const std::out_of_range&)
            {
                std::cout << "Number is too large. Please enter a number between 1 and 8." 
                << std::endl;
            }
        }
        else
        {
            std::cout << "Input contains non-digit characters. Please enter a valid number." 
            << std::endl;
        }

    } while (!valid);
}

std::string formatString(const std::string &entry) 
{
    if (entry.length() > 10) 
    {
        return (entry.substr(0, 9) + '.');
    } 
    else
    {
        return entry;
    }
}

int main()
{
    PhoneBook pB;
    Contact newContact;
    std::string command;
    std::string selectedIndex;
    std::string input;

    pB.setIndex(0);
    system("clear");
    while (1)
    {
        std::cout << "Enter a command: ADD - SEARCH - EXIT" << std:: endl;
        if (!std::getline(std::cin, command))
        {
            std::cout << "End of input detected. Exiting the program." << std::endl;
            break;
        }
        
        if (pB.getIndex() > 7)
            pB.setIndex(0);
        if (command == "ADD")
        {
            system("clear");

            getInput(input, "Enter the first name:");
            newContact.setFirstName(input);
            getInput(input, "Enter the last name:");
            newContact.setLastName(input);
            getInput(input, "Enter the nickname:");
            newContact.setNickName(input);
            getInput(input, "Enter the phone number:");
            newContact.setPhoneNum(input);
            getInput(input, "Enter the darkest secret:");
            newContact.setSecret(input);
            pB.setContact(pB.getIndex(), newContact);
            pB.setIndex(pB.getIndex() + 1);
            system("clear");

        }
        else if (command == "SEARCH")
        {
            system("clear");      
            for (int i = 0; i < 8; i++)
            {
                if (!pB.getContact(i).getFirstName().empty())
                {
                    std::cout << std::setw(10) << i + 1 << "|"
                    << std::setw(10) << formatString(pB.getContact(i).getFirstName()) << "|"
                    << std::setw(10) << formatString(pB.getContact(i).getLastName()) << "|"
                    << std::setw(10) << formatString(pB.getContact(i).getNickName())
                    << std::endl;
                }
            }
            std::cout << std::endl;
            checkIndex(selectedIndex, pB);
            
        }
        else if (command == "EXIT")
            break;
    }
}