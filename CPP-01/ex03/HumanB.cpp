#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_arma = nullptr;
}

HumanB::~HumanB(void)
{

}

void HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_arma->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &arma)
{
	this->_arma = &arma;
}