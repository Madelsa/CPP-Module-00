/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:18:23 by mahmoud           #+#    #+#             */
/*   Updated: 2024/08/13 16:58:58 by mabdelsa         ###   ########.fr       */
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
                    if (pB.contacts[selectedIndexInt - 1].firstName.empty())
                    {
                        std::cout << "Selected index entry is empty." << std::endl;
                        return ;
                    }
                    else
                    {
                        system("clear");
                        std::cout << "First Name: " << pB.contacts[selectedIndexInt - 1].firstName << std::endl;
                        std::cout << "Last Name: " << pB.contacts[selectedIndexInt - 1].lastName << std::endl;
                        std::cout << "Nickname: " << pB.contacts[selectedIndexInt - 1].nickName << std::endl;
                        std::cout << "Phone Number: " << pB.contacts[selectedIndexInt - 1].phoneNum << std::endl;
                        std::cout << "Secret: " << pB.contacts[selectedIndexInt - 1].secret << std::endl;
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

std::string formatString(std::string &entry) 
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
    std::string command;
    pB.index = 0;
    std::string selectedIndex;

    system("clear");
    while (1)
    {
        std::cout << "Enter a command: ADD - SEARCH - EXIT" << std:: endl;
        if (!std::getline(std::cin, command))
        {
            std::cout << "End of input detected. Exiting the program." << std::endl;
            break;
        }
        
        if (pB.index > 7)
            pB.index = 0;
        if (command == "ADD")
        {
            system("clear");      
            getInput(pB.contacts[pB.index].firstName, "Enter the first name:");
            getInput(pB.contacts[pB.index].lastName, "Enter the last name:");
            getInput(pB.contacts[pB.index].nickName, "Enter the nickname:");
            getInput(pB.contacts[pB.index].phoneNum, "Enter the phone number:");
            getInput(pB.contacts[pB.index].secret, "Enter the darkest secret:");
            system("clear");      
            pB.index++;
        }
        else if (command == "SEARCH")
        {
            system("clear");      
            for (int i = 0; i < 8; i++)
            {
                if (!pB.contacts[i].firstName.empty())
                {
                    std::cout << std::setw(10) << formatString(pB.contacts[i].firstName) << "|"
                    << std::setw(10) << formatString(pB.contacts[i].lastName) << "|" 
                    << std::setw(10) << formatString(pB.contacts[i].nickName) << "|"
                    << std::setw(10) << formatString(pB.contacts[i].phoneNum) << "|" 
                    << std::setw(10) << formatString(pB.contacts[i].secret) << "|"
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