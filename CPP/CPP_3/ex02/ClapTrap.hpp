#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
  protected:
    std::string _name;
    unsigned int _HitPoint;
    unsigned int _EnergyPoint;
    unsigned int _AttackDamage;
  public:
    ClapTrap();
    ClapTrap(std::string name);
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif