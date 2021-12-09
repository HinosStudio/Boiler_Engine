#pragma once

#include <stdexcept>
#include <array>

template<typename T, unsigned int S, unsigned int N, typename derived>
class Composite {
protected:
    std::array<T, S> _values;
    unsigned int _size, _columns, _rows;

public:
    Composite() : _size{S}, _columns{N}, _rows{S / N} {
        std::fill(_values.begin(), _values.end(), 0);
    }

    ~Composite() = default;

//---------------------------------------------------------
// Rule of 3
//---------------------------------------------------------
/*
    Composite(const Composite& other) : _size{S}, _columns{N}, _rows{S / N} {
        _values = new T[_size];
        std::memcpy(_values, other._values, _size);
    }

    Composite &operator=(const Composite &other) {
        if (this != &other) {
            T *new_array = new T[other._size];
            std::memcpy(other._values, other._values + other._size, new_array);

            delete[] _values;

            _values = new_array;
            _size = other._size;
        }
        return *this;
    }
    */

//---------------------------------------------------------
// Index Operator
//---------------------------------------------------------

    T &operator[](int index) {
        if (index > _size - 1) throw std::out_of_range{"index out of range"};
        return _values[index];
    }

    const T &operator[](int index) const {
        if (index > _size - 1) throw std::out_of_range{"index out of range"};
        return _values[index];
    }

//---------------------------------------------------------
// Additive Operations
//---------------------------------------------------------

    Composite &operator+=(const Composite &other) {
        for (int i = 0; (i < _size && i < other._size); ++i) {
            _values[i] += other[i];
        }
        return *this;
    }

    friend derived operator+(const derived &a, const derived &b) {
        derived temp;
        for (int i = 0; (i < a._size && i < b._size); ++i) {
            temp[i] = a[i] + b[i];
        }
        return temp;
    }

//---------------------------------------------------------
// Subtract Operations
//---------------------------------------------------------

    Composite &operator-=(const Composite &other) {
        for (int i = 0; (i < _size && i < other._size); ++i) {
            _values[i] -= other[i];
        }
        return *this;
    }

    derived operator-(const derived &other) {
        derived temp;
        for (int i = 0; (i < _size && i < other._size); ++i) {
            temp[i] = _values[i] - other[i];
        }
        return temp;
    }

//---------------------------------------------------------
// Scalar Operations
//---------------------------------------------------------

    derived operator*(const T &value) const {
        derived temp;
        for (int i = 0; i < _size; ++i)
            temp[i] = _values[i] * value;
        return temp;
    }

    derived operator/(const T &value) const {
        derived temp;
        for (int i = 0; i < _size; ++i)
            temp[i] = _values[i] * value;
        return temp;
    }
};

