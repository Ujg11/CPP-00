#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon		&_arma; //es una referencia ya qua almacenara una instancia ya creada
		std::string	_name;

	public:
		HumanA(std::string name, Weapon &arma); //se pasa &arma para pasar la referencia y asi no crear una copia
		~HumanA(void);
		void attack(void);
};

#endif
//HumanA usa una referencia directa y espera tener una instancia de Weapon desde el principio.
