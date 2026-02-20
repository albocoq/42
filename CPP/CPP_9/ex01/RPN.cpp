#include "RPN.hpp"


void RPN::evaluateExpression(std::string expression) {
  int size = static_cast<int>(expression.size());

  for (int i = 0; i < size; i++) {
    char s = expression.at(i);

    if (s == ' ')
      continue;

    if (s >= '0' && s <= '9') {
      _stack.push(s - '0');

      continue;
    }

    if (isOperator(s)) {
      performOperation(s);

      continue;
    } else {
      throw std::runtime_error("Caracter is not operator/space/number");
    }
  }
  if (_stack.size() == 1) {
    std::cout << _stack.top() << std::endl;
    return;
  } else {
    throw std::runtime_error("Incomplete expression");
  }
}