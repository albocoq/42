#include "RPN.hpp"

int main(int argc, char const *argv[])
{

  if (argc != 2 || !argv[1][0]) {
    std::cout << "Error: ./RPN [arguments]" << std::endl;
    return 1;
  }

  RPN r;


  try
  {
    r.evaluateExpression(argv[1]);
  }
  catch(const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << '\n';
  }




  return 0;
}
