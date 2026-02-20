#include <string>
#include <iostream>

class ICharacter;

class AMateria
{
  protected:
    std::string _type;
  public:
    AMateria(std::string const & type);
    AMateria(const AMateria &other);
    virtual ~AMateria();
    AMateria &operator=(const AMateria &other);
    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

class ICharacter {
  public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

class Character: public ICharacter {
  private:
    std::string _name;
    AMateria* _inventory[4];
  public:
    Character();
    Character(Character const &other);
    Character(std::string const & name);
    ~Character();
    std::string const & getName() const;
    Character &operator=(Character const &other);
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};


class Ice: public AMateria {
  public:
    Ice();
    Ice(const Ice &other);
    ~Ice();
    Ice &operator=(const Ice &other);
    void use(ICharacter& target);
    AMateria* clone() const;
};

class Cure: public AMateria {
  public:
    Cure();
    Cure(const Cure &other);
    ~Cure();
    Cure &operator=(const Cure &other);
    void use(ICharacter& target);
    AMateria* clone() const;
};

class IMateriaSource {
  public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria* m) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource: public IMateriaSource {
  private:
    AMateria* _materias[4];
  public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(MateriaSource const &other);
    MateriaSource &operator=(MateriaSource const &other);
    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};