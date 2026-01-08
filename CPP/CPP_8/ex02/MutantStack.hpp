#include <stack>
#include <iostream>

template <typename T> class MutantStack: public std::stack<T> {
  public:
    MutantStack() {};
    ~MutantStack() {};
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() {
      return this->c.begin();
    }
    iterator end() {
      return this->c.end();
    }
};