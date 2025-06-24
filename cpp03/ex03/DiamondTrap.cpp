//
// Created by edvieira on 6/24/25.
//

#include "DiamondTrap.hpp"

void DiamondTrap::whoAmI() {

}

void DiamondTrap::attack(const std::string& target)
{
    if(energyPoint > 0 && hitPoints > 0)
    {
        std::cout << "DiamondTrap " + this->name + " attacks " + target + ", causing ";
        std::cout << this->attackDamage + " points of damage!" << std::endl;
        energyPoint--;
    }
    else
        std::cout << "DiamondTrap " + this->name + " could not attack because it doesn't have energyPoints or hitPoints" << std::endl;
}

void DiamondTrap::takeDamage(unsigned int amount)
{
    this->hitPoints -= amount;
    std::cout << "DiamondTrap " << name << " was attacked, it received " << amount << " hit points." << std::endl;
    //std::cout << "Remaining live: " << hitPoints << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount)
{
    if (energyPoint > 0 && hitPoints > 0)
    {
        std::cout << "DiamondTrap " << name <<" repairs itself, it regains " << amount << " hit points." << std::endl;
        this->hitPoints += amount;
        energyPoint--;
    }
    else
        std::cout << "DiamondTrap " + this->name + " could not repair because it doesn't have energyPoints or hitPoints" << std::endl;
}

std::string DiamondTrap::getName() { return (this->name); }

// ============ Getters
int DiamondTrap::getHitPoints() { return (this->hitPoints); }

int DiamondTrap::getEnergyPoint() { return (this->energyPoint); }

int DiamondTrap::getAttackDamage() { return (this->attackDamage); }

// ============ Setters

void DiamondTrap::setHitPoints(int hitPoints){
    this->hitPoints = hitPoints;
}

void DiamondTrap::setEnergyPoint(int energyPoint){
    this->energyPoint = energyPoint;
}

void DiamondTrap::setAttackDamage(int attackDamage){
    this->attackDamage = attackDamage;
}

// ============ Constructors

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name + "_clap_name") {

}

DiamondTrap::DiamondTrap(DiamondTrap &cp) {

}

DiamondTrap::~DiamondTrap() {

}

// ============ Operators

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {
    this->name = other.name;
    this->attackDamage = other.attackDamage;
    this->hitPoints = other.hitPoints;
    this->energyPoint = other.energyPoint;
    return *this;
}


