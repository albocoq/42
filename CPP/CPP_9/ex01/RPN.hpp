#include <iostream>
#include <stack>

class RPN {
  private:
    std::stack<int> _stack;
    bool isOperator(char c) {
      return (c == '+' || c == '-' || c == '*' || c == '/') ?  true : false;
    };
    void performOperation(char op) {
      if (_stack.size() < 2)
        throw std::runtime_error("there is less than 2 elements in stack");

      int lastNumber = _stack.top();
      _stack.pop();
      int secondNumber = _stack.top();
      _stack.pop();

      std::cout << lastNumber << " " << secondNumber << op << std::endl;
      switch (op)
      {
        case '+':
          _stack.push(lastNumber + secondNumber);
          break;
        case '-':
          _stack.push(secondNumber - lastNumber);
          break;
        case '/':
          if (lastNumber == 0 || secondNumber == 0)
            throw std::runtime_error("division by 0");
          _stack.push(secondNumber / lastNumber);
          break;
        case '*':
          _stack.push(lastNumber * secondNumber);
          break;
      }
    };

  public:
    RPN() {};
    ~RPN() {};
    void evaluateExpression(std::string expression);
};