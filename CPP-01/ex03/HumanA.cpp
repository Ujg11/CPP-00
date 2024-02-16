#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &arma): _name(name), _arma(arma)
{
	
}

HumanA::~HumanA(void)
{

}

void HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_arma.getType() << std::endl;
}