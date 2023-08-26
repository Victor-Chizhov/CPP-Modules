/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:49:49 by vchizhov          #+#    #+#             */
/*   Updated: 2023/08/08 12:44:13 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for(int i = 1; i < ac; i++)
        {
            std::string str = av[i];
            for (size_t i = 0; i < str.length(); i++)
                std::cout <<  (char)toupper(str[i]);
        } 
        std::cout << std::endl;
        return (0);
    }
}
