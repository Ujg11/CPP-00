/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:33:01 by ojimenez          #+#    #+#             */
/*   Updated: 2024/02/17 14:33:01 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	replace(std::ifstream &infile, const std::string &s1, const std::string &s2, std::ofstream &outfile)
{
	std::string str = "";
	size_t i = 0;

	while (std::getline(infile, str))
	{
		i = 0;
		while ((i = str.find(s1, i)) != std::string::npos)
		{
			str = str.erase(i, s1.length()); //elimina s1
			str = str.insert(i, s2);
			i += s2.length();
		}
		outfile << str << std::endl; //Es posa la linea canviada o sense canviar en cas de no trobar la cadena
	}
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Error! Introduzca <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	std::string outputFilename = filename + ".replaced";

	std::ifstream infile(filename);
	if (!infile.is_open())
	{
		std::cout << "Error al abrir el archivo " << filename << std::endl;
		return (1);
	}
	std::ofstream outfile(outputFilename, std::ios::out | std::ios::trunc); //Se abre en modo escritura y se trunca el contenido
	if (!outfile.is_open())
	{
		std::cout << "Error al abrir el archivo de salida " << filename << std::endl;
		return (1);
	}
	replace(infile, s1, s2, outfile);
	std::cout << "Reemplazo hecho" << std::endl;
	infile.close();
	outfile.close();
	return (0);
}