#pragma once

#include <boiler/util/Composite.hpp>
#include <cmath>

template<typename T, unsigned int N, typename derived>
class VectorBase : public Composite<T, N, N, derived> {
public:
    VectorBase() : Composite<T, N, N, derived>{} {
    }

    VectorBase(const VectorBase& other) : Composite<T, N, N, derived>{other}{
    }

    friend derived operator*(const derived &a, const derived &b){
        derived temp;
        for(int i = 0; i < a._size; i++)
            temp[i] = a[i] * b[i];
        return temp;
    }

    [[nodiscard]] float magnitude() const {
        float temp{0};
        for (int i = 0; i < this->_size; ++i) {
            temp += this->_values[i] * this->_values[i];
        }
        return std::sqrt(temp);
    }

    [[nodiscard]] derived normalized() const {
        return *this * (1 / magnitude());
    }

    static float distance(const derived &a, const derived &b) {
        derived temp = a - b;
        return temp.magnitude();
    }
};

//---------------------------------------------------------
// Vector
//---------------------------------------------------------

template<typename T, unsigned int N>
class Vector : public VectorBase<T, N, Vector<T, N>> {
public:
    Vector() : VectorBase<T, N, Vector<T, N>>{} {
    }
};

//---------------------------------------------------------
// Vector 2
//---------------------------------------------------------

using V2 = Vector<float, 2>;

template<typename T>
class Vector<T, 2> : public VectorBase<T, 2, Vector<T, 2>> {
public:
    Vector() : VectorBase<T, 2, Vector<T, 2>>{} {
    }

    Vector(const Vector& other) : VectorBase<T, 2, Vector<T, 2>>{other}{
    }

    Vector(T x, T y) : VectorBase<T, 2, Vector<T, 2>>{} {
        this->_values[0] = x;
        this->_values[1] = y;
    };

    explicit operator Vector<T,3>() const {
        return Vector<T,3>{this->_values[0], this->_values[1], 0};
    }
};

//---------------------------------------------------------
// Vector 3
//---------------------------------------------------------

using V3 = Vector<float, 3>;

template<typename T>
class Vector<T, 3> : public VectorBase<T, 3, Vector<T, 3>> {
public:
    Vector() : VectorBase<T, 3, Vector<T, 3>>{} {
    }

    Vector(T x, T y, T z) : VectorBase<T, 3, Vector<T, 3>>{} {
        this->_values[0] = x;
        this->_values[1] = y;
        this->_values[2] = z;
    };

    friend V3 operator-(const V3 &a, const V2 &b) {
        V3 temp;
        for (int i = 0; (i < a._size && i < b._size); ++i) {
            temp[i] = a[i] - b[i];
        }
        return temp;
    }

    explicit operator V2() const {
        return V2{this->_values[0], this->_values[1]};
    }

    explicit operator Vector<float, 4>() const {
        return V4{this->_values[0], this->_values[1], this->_values[2], 1};
    }
};

//---------------------------------------------------------
// Vector 4
//---------------------------------------------------------

using V4 = Vector<float, 4>;
using V4int = Vector<int,4>;

template<typename T>
class Vector<T, 4> : public VectorBase<T, 4, Vector<T, 4>> {
public:
    Vector() : VectorBase<T, 4, Vector<T, 4>>{} {
    }

    Vector(T x, T y, T z, T w) : VectorBase<T, 4, Vector<T, 4>>{} {
        this->_values[0] = x;
        this->_values[1] = y;
        this->_values[2] = z;
        this->_values[3] = w;
    };

    explicit operator V3() const {
        return V3{this->_values[0], this->_values[1], this->_values[2]};
    }
};