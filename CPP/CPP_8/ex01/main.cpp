#include "Span.hpp"

// int main() {
//   try {
//     Span A(4);

//     // A.longestSpan();

//     A.addNumber(7);

//     // A.shortestSpan(); // Test error not enough number

//     A.addNumber(9);
//     A.addNumber(6);
//     A.addNumber(2);

//     std::cout << "shortest: " << A.shortestSpan() << std::endl;
//     std::cout << "longest: " << A.longestSpan() << std::endl;
//   } catch (std::exception & e) {
//     std::cout << e.what() << std::endl;
//   }
// }

// int main() {
//   try {
//     srand(time(NULL));
//     Span A(10000);

//     for (int i = 0; i < 10000; i++) {
//       A.addNumber(rand() % 100000);
//     }


//     std::cout << "shortest: " << A.shortestSpan() << std::endl;
//     std::cout << "longest: " << A.longestSpan() << std::endl;
//   } catch (std::exception & e) {
//     std::cout << e.what() << std::endl;
//   }
// }

int main() {
  try {
    Span A(10);

    A.addNumber(5);
    A.addNumber(7);

    A.addNumbers({4, 8, 7});

    A.addNumbers({7, 59, 89, 7, 6});

    std::cout << "shortest: " << A.shortestSpan() << std::endl;
    std::cout << "longest: " << A.longestSpan() << std::endl;
  } catch (std::exception & e) {
    std::cout << e.what() << std::endl;
  }
}