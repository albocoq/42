#include <iostream>
#include <stack>
#include <climits>
#include <vector>
#include <deque>

class PmergeMe {
  private:
    std::vector<int> _before;
    std::deque<int> _after;
    void sortVector() {
      int last = 0;

      if (_before.size() % 2 != 0) {
        last = _before.at(_before.size());
        _before.pop_back();
      }

    };
    void sortDeque() {
    };

  public:
    PmergeMe() {};
    ~PmergeMe() {};
    void parseToContainers(char **argv);
};