#pragma once
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
  public:
    PresidentialPardonForm(std::string const & target);
    virtual ~PresidentialPardonForm();

  protected:
    virtual void action() const;

  private:
    std::string _target;
};