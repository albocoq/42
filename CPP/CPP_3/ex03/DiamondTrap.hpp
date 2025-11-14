#ifndef DiamondTRAP_HPP
#define DiamondTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: virtual public ClapTrap, public ScavTrap, public FragTrap {
  private:
    std::string _name;
  public:
    DiamondTrap();
    DiamondTrap(std::string name);
    ~DiamondTrap();
    void attack(const std::string& target);
    void whoAmI();
};

#endif