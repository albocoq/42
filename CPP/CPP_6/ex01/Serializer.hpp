#include <string>
#include <iostream>
#include <stdint.h>

class Data {
  public:
    std::string getName();
    int getId();
    bool isActive();
    Data(int id, std::string name, bool isActive);
    ~Data();
  private:
    int _id;
    std::string _name;
    bool _isActive;
};

class Serializer
{
  private:
  Serializer();
  ~Serializer();
  Serializer(const Serializer& other);
  Serializer& operator=(const Serializer& other);

  public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

