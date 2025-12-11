#include <string>
#include <bits/stdc++.h>

class Zombie {
  public:
    Zombie();

    ~Zombie();
    void announce(void);
    void setName(std::string name);
  private:
    std::string _name;
};

Zombie* zombieHorde( int N, std::string name );
