#pragma once
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
  public:
    ShrubberyCreationForm(std::string const & target);
    virtual ~ShrubberyCreationForm();

  protected:
    virtual void action() const;

  private:
    std::string _target;
};