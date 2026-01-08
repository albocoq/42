#include <iostream>

template <typename T> class Array {
  private:
    T *_array;
    unsigned int _size;
  public:
    unsigned int size() const {
      return _size;
    };
    Array() {
      _array = NULL;
      _size = 0;
    };
    Array(unsigned int n) {
      _array = new T[n]();
      _size = n;
    };
    ~Array() {
      delete [] this->_array;
    };
    Array &operator=(const Array &other) {

      if (other._array != this->_array) {

        T *arr = new T[other._size];


        delete [] this->_array;

        for (int i = 0; other._size > i; ++i) {
          arr[i] = other._array[i];
        }
        this->_array = arr;
        this->_size = other._size;

        return *this;
      }
    }
    Array(const Array &other) {
      T *arr = new T[other._size];

      for (unsigned int i = 0; other._size > i; ++i) {
        arr[i] = other._array[i];
      }
      this->_array = arr;
      this->_size = other._size;
    }
    T &operator[](std::size_t idx)
    {
        if (idx >= this->_size)
            throw std::out_of_range("Array index out of range");
        return this->_array[idx];
    }

    const T &operator[](std::size_t idx) const
    {
        if (idx >= this->_size)
            throw std::out_of_range("Array index out of range");
        return this->_array[idx];
    }



};