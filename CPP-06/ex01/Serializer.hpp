/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:58:55 by ojimenez          #+#    #+#             */
/*   Updated: 2024/06/23 15:58:55 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

typedef struct Data
{
	char		c;
	int			number;
	std::string	s;
}	Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &cpy);
		Serializer &operator=(const Serializer &cpy);
		~Serializer();

	public:
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
};

//serializacion: convertir un objeto en una secuencia de bytes (u otros) para que se pueda volver a construir luego
//uintptr_t: valor entero sin signo
//reinterpret_cats: permite convertir qualquier tipo de puntero a qualquier otro.