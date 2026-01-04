#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
: AForm(target, 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const {
  std::ofstream file;
  std::string filename = _target + "_shrubbery";
  file.open(filename.c_str());

  if (!file.is_open()) {
    throw std::runtime_error("cant create file");
  }

  file << "       _-_       " << std::endl;
  file << "    /~~   ~~\\   " << std::endl;
  file << " /~~         ~~\\" << std::endl;
  file << "{               }" << std::endl;
  file << " \\  _-     -_  /" << std::endl;
  file << "   ~  \\ //  ~   " << std::endl;
  file << "_- -   | | _- _  " << std::endl;
  file << "  _ -  | |   -_  " << std::endl;
  file << "      // \\     " << std::endl;

  file.close();
}