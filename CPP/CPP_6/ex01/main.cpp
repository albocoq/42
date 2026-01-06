#include "Serializer.hpp"

int main() {
  Data A(15, "salade", false);

  std::cout << "Name A: " << A.getName() << std::endl;

  uintptr_t s = Serializer::serialize(&A);

  std::cout << "uintptr_t: " << s << std::endl;

  Data *B = Serializer::deserialize(s);

  std::cout << "Name A: " << A.getName() << std::endl;
  std::cout << "Name B: " << B->getName() << std::endl;

  if (B == &A) {
      std::cout << "Verification réussie : les pointeurs sont identiques !" << std::endl;
  } else {
      std::cout << "Erreur : les pointeurs diffèrent." << std::endl;
  }

  delete B;

}