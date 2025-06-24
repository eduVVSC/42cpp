//
// Created by edvieira on 6/24/25.
//

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


class DiamondTrap : public ClapTrap, public ScavTrap {
private:
    std::string	name;

public:
    void whoAmI();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    int getHitPoints();
    int getEnergyPoint();
    int getAttackDamage();
    std::string getName();

    void setHitPoints(int hitPoints);
    void setEnergyPoint(int energyPoint);
    void setAttackDamage(int attackDamage);

    DiamondTrap(std::string name);
    DiamondTrap(DiamondTrap &cp);
    ~DiamondTrap();

    DiamondTrap& operator=(DiamondTrap const&other);
};



#endif //DIAMONDTRAP_H
