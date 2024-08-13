/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:45:58 by mabdelsa          #+#    #+#             */
/*   Updated: 2024/08/07 12:07:12 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>


int main(int ac, char **av) 
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; i < ac; i++)
        {
            for (int j = 0; av[i][j] != '\0'; j++)
            {
                std::cout << (char)toupper(av[i][j]);
            }
            if (i != ac - 1)
                std::cout << " ";
        } 
    }
    std::cout << std::endl;
}