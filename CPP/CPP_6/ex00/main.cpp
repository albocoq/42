#include "Convert.hpp"

int main(int argc, char **argv) {
    if (argc == 2) {
        ScalarConverter::convert(argv[1]);
    } else {
        std::string tests[] = {
            "a",
            "0",
            "-42",
            "42.0f",
            "4.2f",
            "-4.2f",
            "0.0",
            "4.2",
            "-4.2",
            "nan",
            "nanf",
            "+inf",
            "-inff",
            "2147483647",
            "2147483648",
            "invalid"
        };

        for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
            std::cout << "--- Test: [" << tests[i] << "] ---" << std::endl;
            ScalarConverter::convert(tests[i]);
            std::cout << std::endl;
        }
    }
    return 0;
}