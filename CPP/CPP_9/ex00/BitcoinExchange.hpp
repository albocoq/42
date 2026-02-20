#include <map>
#include <string>
#include <iostream>
#include <bits/stdc++.h>

class BitcoinExchange {
  private:
    std::map<std::string, float> _data;
    int _dataSize;
    static bool isLeap(int y) {
      return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    void isValidValue(std::string value) {
      if (value.empty())
        throw std::runtime_error("bad input => empty value");

      char* end;
      double val = strtod(value.c_str(), &end);

      if (*end != '\0')
        throw std::runtime_error("bad input => " + value);

      if (val < 0)
        throw std::runtime_error("not a positive number.");
      if (val > 1000)
        throw std::runtime_error("too large a number.");
    }

    bool isValidDate(std::string date) {
      char* end;
      double year = strtod(date.substr(0, 4).c_str(), &end);
      double month = strtod(date.substr(5, 2).c_str(), &end);
      double day = strtod(date.substr(8, 2).c_str(), &end);

      if (year < 0 || year > 2026 || month < 1 || month > 12)
        return false;

      int daysInMonth = 31;
      switch (static_cast<int>(month)) {
        case 4: case 6: case 9: case 11: daysInMonth = 30; break;
        case 2: daysInMonth = isLeap(year) ? 29 : 28; break;
        default: daysInMonth = 31;
      }
      if (day < 1 || day > daysInMonth)
        return false;
      return true;
    }

    float getExchangeRate(const std::string date) {
      std::map<std::string, float>::iterator it = _data.lower_bound(date);

      if (it != _data.end() && it->first == date)
        return it->second;

      if (it == _data.begin())
        throw std::runtime_error("no exchange rate available for this date (too old).");

      --it;
      return it->second;
    }

  public:
    BitcoinExchange();
    ~BitcoinExchange();
    void loadDatabase();
    void processInput(std::ifstream &f);

};