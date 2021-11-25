#pragma once

#include <array>
#include <cmath>

template<typename T, unsigned int N, typename derrived>
class Vector_Base {
protected:
    std::array<T, N> _values;

public:
    Vector_Base() {
        _values.fill(0);
    }

    int size() const{
        return _values.size();
    }

    T &operator[](int index) {
        return _values[index];
    }

    const T &operator[](int index) const {
        return _values[index];
    }

    derrived operator*(const T &value) const {
        derrived temp;
        for (int i = 0; i < size(); ++i) {
            temp[i] = _values[i] * value;
        }
        return temp;
    }

    derrived operator/(const float &value) const {
        derrived temp;
        for (int i = 0; i < size(); ++i) {
            temp[i] = _values[i] / value;
        }
        return temp;
    }

    derrived &operator+=(const derrived &other) {
        for (int i = 0; (i < size() && i < other.size()); ++i) {
            _values[i] += other[i];
        }
        return *this;
    }

    derrived &operator-=(const derrived &other) {
        for (int i = 0; (i < size() && i < other.size()); ++i) {
            _values[i] -= other[i];
        }
        return *this;
    }

    friend derrived operator+(const derrived &a, const derrived &b) {
        derrived temp;
        for (int i = 0; (i < a.size() && i < b.size()); ++i) {
            temp[i] = a[i] + b[i];
        }
        return temp;
    }

    friend derrived operator-(const derrived &a, const derrived &b) {
        derrived temp;
        for (int i = 0; (i < a.size() && i < b.size()); ++i) {
            temp[i] = a[i] - b[i];
        }
        return temp;
    }

    friend derrived operator*(const derrived &a, const derrived &b) {
        derrived temp;
        for (int i = 0; (i < a.size() && i < b.size()); ++i) {
            temp[i] = a[i] * b[i];
        }
        return temp;
    }

    friend derrived operator/(const derrived &a, const derrived &b) {
        derrived temp;
        for (int i = 0; (i < a.size() && i < b.size()); ++i) {
            temp[i] = a[i] / b[i];
        }
        return temp;
    }

    float magnitude() const {
        float temp;
        for (int i = 0; i < size(); ++i) {
            temp += _values[i] * _values[i];
        }
        return std::sqrt(temp);
    }

    derrived &ClampMagnitude(const T low, const T high) {
        for (int i = 0; i < size(); ++i) {
            _values[i] = (_values[i] < low) ? low : _values[i];
            _values[i] = (_values[i] > high) ? high : _values[i];
        }
        return *this;
    }

    derrived normalized() const {
        return *this * (1 / magnitude());
    }

    static float distance(const derrived &a, const derrived &b) {
        derrived temp = a - b;
        return temp.magnitude();
    }

    /*
    static Vector cross(Vector a, Vector b);

    static T dot(Vector a, Vector b);

    static Vector project(Vector vector, Vector normal);

    static Vector reflect(Vector vector, Vector normal);
     */
};

template<typename T, unsigned int N>
class Vector : public Vector_Base<T, N, Vector<T,N>> {
public:
    Vector() : Vector_Base<T, N, Vector<T,N>>{} {
    }
};

template<typename T>
class Vector<T, 2> : public Vector_Base<T, 2, Vector<T, 2>> {

public:
    Vector() : Vector_Base<T, 2, Vector<T, 2>>{} {
    }

    Vector(T x, T y) {
        this->_values[0] = x;
        this->_values[1] = y;
    };

};

template<typename T>
class Vector<T, 3> : public Vector_Base<T, 3, Vector<T, 3>> {
public:

    Vector() : Vector_Base<T, 3, Vector<T, 3>>{} {
    }

    Vector(T x, T y, T z) {
        this->_values[0] = x;
        this->_values[1] = y;
        this->_values[2] = z;
    }
};

template<typename T>
class Vector<T, 4> : public Vector_Base<T, 4, Vector<T, 4>> {
public:
    Vector() : Vector_Base<T, 4, Vector<T, 4>>{} {
    }

    Vector(T x, T y, T z, T w) {
        this->_values[0] = x;
        this->_values[1] = y;
        this->_values[2] = z;
        this->_values[3] = w;
    }
};

using V2 = Vector<float, 2>;
using V3 = Vector<float, 3>;
using V4 = Vector<float, 4>;
