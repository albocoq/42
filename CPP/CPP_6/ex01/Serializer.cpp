#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}


Data::Data(int id, std::string name, bool isActive): _id(id), _name(name), _isActive(isActive) {}

Data::~Data() {}

std::string Data::getName() {
  return _name;
}

int Data::getId() {
  return _id;
}

bool Data::isActive() {
  return _isActive;
}