#pragma once

#include <boiler/util/Composite.hpp>
#include <cmath>

template<typename T, unsigned int N>
class Vector_Base : public Composite<T, N> {
public:
    Vector_Base operator-() const{
        Vector_Base temp;
        for (int i = 0; i < N; ++i) {
            temp[i] = -this->_values[i];
        }
        return temp;
    }

    Vector_Base operator-(const Vector_Base &other) const {
        Vector_Base temp;
        for (int i = 0; i < N; ++i) {
            temp[i] = this->_values[i] - other[i];
        }
        return temp;
    }
};

template<typename T, unsigned int N>
class Vector : public Vector_Base<T, N> {
public:

};

typedef Vector<float, 2> V2;
typedef Vector<float, 3> V3;
typedef Vector<float, 4> V4;
typedef Vector<int, 4> V4int;

template<typename T>
class Vector<T, 2> : public Vector_Base<T, 2> {
public:
    Vector() = default;

    Vector(T x, T y){
        this->_values[0] = x;
        this->_values[1] = y;
    }
};

template<typename T>
class Vector<T, 3> : public Vector_Base<T, 3> {
public:
    Vector() = default;

    Vector(T x, T y, T z) {
        this->_values[0] = x;
        this->_values[1] = y;
        this->_values[2] = z;
    }

    Vector &operator=(const Composite<T, 3> &other) {
        if (this != &other) {
            for (int i = 0; i < 3; ++i) {
                this->_values[i] = other[i];
            };
        }
        return *this;
    }

    Vector &operator=(const Vector_Base<T, 3> &other) {
        if (this != &other) {
            for (int i = 0; i < 3; ++i) {
                this->_values[i] = other[i];
            };
        }
        return *this;
    }

    [[nodiscard]] float Dot(const V3 &other) const {
        return this->_values[0] * other[0] + this->_values[1] * other[1] + this->_values[2] * other[2];
    }

    [[nodiscard]] V3 Cross(const V3 &other) const {
        return V3{
                this->_values[1] * other[2] - this->_values[2] * other[1],
                this->_values[2] * other[0] - this->_values[0] * other[2],
                this->_values[0] * other[1] - this->_values[1] * other[0]
        };
    }

    [[nodiscard]] float SqrMagnitude() const {
        return this->_values[0] * this->_values[0] +
               this->_values[1] * this->_values[1] +
               this->_values[2] * this->_values[2];
    }

    [[nodiscard]] float Magnitude() const {
        return std::sqrt(SqrMagnitude());
    }

    void Normalize() {
        (*this) /= Magnitude();
    }

    [[nodiscard]] V3 Normalized() const {
        return (*this) /= Magnitude();
    }

    explicit operator V2() const{
        return V2{this->_values[0], this->_values[1]};
    }
};

template<typename T>
class Vector<T, 4> : public Vector_Base<T, 4> {
public:
    Vector() = default;

    Vector(T x, T y, T z, T w) {
        this->_values[0] = x;
        this->_values[1] = y;
        this->_values[2] = z;
        this->_values[3] = w;
    }

    Vector(const V3 &vector, float w){
        this->_values[0] = vector[0];
        this->_values[1] = vector[1];
        this->_values[2] = vector[2];
        this->_values[3] = w;
    }

    Vector &operator=(const Composite<T, 4> &other) {
        if (this != &other) {
            for (int i = 0; i < 4; ++i) {
                this->_values[i] = other[i];
            };
        }
        return *this;
    }

    explicit operator V3() const{
        return V3{this->_values[0], this->_values[1], this->_values[2]};
    }
};