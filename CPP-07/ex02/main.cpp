/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:30:26 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/04 15:59:18 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 100
int main(int, char**)
{
    Array<int> arrInts(10);
    Array<std::string> arrStrings(3);

    try
    {
        for (size_t i = 0; i < arrInts.size(); i++)
        {
            arrInts[i] = i * 4;
        }
        std::cout << "[";
        for (size_t i = 0; i < arrInts.size(); i++)
        {
            std::cout << arrInts[i] << " ";
        }
        std::cout << "]" << std::endl;
        std::cout << arrInts[10];//exception
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        arrStrings[0] = "Hola";
        arrStrings[1] = "que";
        arrStrings[2] = "tal";
        for (size_t i = 0; i < arrStrings.size(); i++)
        {
            std::cout << arrStrings[i] << std::endl;
        }
        std::cout << arrInts[-1];//exception
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
