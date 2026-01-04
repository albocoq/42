#pragma once
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
  public:
    RobotomyRequestForm(std::string const & target);
    virtual ~RobotomyRequestForm();

  protected:
    virtual void action() const;

  private:
    std::string _target;
};