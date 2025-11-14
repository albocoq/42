#include <string>
#include <bits/stdc++.h>

class Weapon {
  public:
    Weapon(const std::string& type);
    const std::string& getType() const;
    void setType(const std::string& type);
  private:
    std::string _type;
};

class HumanA {
  private:
    std::string _name;
    Weapon& _weapon;
  public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack();
};

class HumanB {
  private:
    std::string _name;
    Weapon* _weapon;
  public:
    void setWeapon(Weapon& weapon);
    HumanB(const std::string name);
    void attack() const;
};
