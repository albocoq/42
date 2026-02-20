#include "BitcoinExchange.hpp"

std::string trim(const std::string& s) {
    size_t first = s.find_first_not_of(" \t");
    if (std::string::npos == first) return s;
    size_t last = s.find_last_not_of(" \t");
    return s.substr(first, (last - first + 1));
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::processInput(std::ifstream &f) {
  std::string line;
  getline(f, line);

  while (getline(f, line)) {
    size_t pos = line.find("|");
    if (pos == std::string::npos) {
        std::cout << "Error: bad input => " << line << std::endl;
        continue;
    }

    std::string date = trim(line.substr(0, pos));
    std::string valueStr = trim(line.substr(pos + 1));

    if (!isValidDate(date)) {
        std::cout << "Error: bad input => " << date << std::endl;
        continue;
    }

    try {
        isValidValue(valueStr);
        double val = strtod(valueStr.c_str(), NULL);
        float rate = getExchangeRate(date);
        std::cout << date << " => " << val << " = " << val * rate << std::endl;
    } catch (std::exception & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
  }
}
void BitcoinExchange::loadDatabase() {
  std::ifstream f("data.csv");
  _dataSize = 0;

  if (!f.is_open())
    throw std::runtime_error("cannot open or file data.csv does not exist.");

  std::string s;

  getline(f, s);
  while (getline(f, s)) {
    int pos = s.find(",");

    std::string date = s.substr(0, pos);
    std::string rate = s.substr(pos + 1, s.size() - pos);

    char* end;
    double val = strtod(rate.c_str(), &end);

    _data.insert(std::make_pair(date, static_cast<float>(val)));
    _dataSize++;
  }

  f.close();
}