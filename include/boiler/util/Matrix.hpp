#pragma once

#include <array>
#include <boiler/util/Composite.hpp>
#include <boiler/util/Vector.hpp>

template<typename T, unsigned int S, unsigned int N, typename derived>
class MatrixBase : public Composite<T, S, N, derived> {
public:
    MatrixBase() : Composite<T, S, N, derived>{} {
    }

    MatrixBase(const std::array<T, S> &values) : Composite<T, S, N, derived>{} {
        for (int i = 0; i < this->_size; ++i)
            this->_values[i] = values[i];
    }

    MatrixBase<T, S, N, derived> operator*(const MatrixBase<T, S, N, derived> &other) {
        if (this->_columns != other._rows) throw std::exception{"cannot multiply vectors"};

        MatrixBase<T,S,N, derived> temp{};

        for (int i = 0; i < this->_rows; ++i) {
            for (int j = 0; j < other._columns; ++j) {
                auto index = (i * temp._columns) + j;
                for (int k = 0; k < this->_columns; ++k) {
                    temp[index] += this->_values[(i * this->_columns) + k] * other[(k * other._columns) + j];
                }
            }
        }

        return temp;
    }

    friend Vector<T,N> operator*(const MatrixBase &a, const Vector<T, N> &b) {
        if (a._columns != N) throw std::exception{"cannot multiply vectors"};

        Vector<T,N> temp {};

        for (int i = 0; i < a._rows; ++i) {
            for (int j = 0; j < 1; ++j) {
                auto index = (i * 1) + j;
                for (int k = 0; k < a._columns; ++k) {
                    temp[index] += a._values[(i * a._columns) + k] * b[(k * 1) + j];
                }
            }
        }

        return temp;
    }
};

//---------------------------------------------------------
// Matrix
//---------------------------------------------------------

template<typename T, unsigned int S, unsigned int N>
class Matrix : public MatrixBase<T, S, N, Matrix<T, S, N>> {
public:
    Matrix() : MatrixBase<T, S, N, Matrix<T, S, N>>{} {
    }

    Matrix(const std::array<T, S> &values) : MatrixBase<T, S, N, Matrix<T, S, N>>{values} {

    }
};

//---------------------------------------------------------
// Matrix 2
//---------------------------------------------------------

using M2 = Matrix<float, (2 * 2), 2>;

template<typename T>
class Matrix<T, (2 * 2), 2> : public MatrixBase<T, (2 * 2), 2, M2> {
public:
    static Matrix<T, (2 * 2), 2> identity {
        1,0,
        0,1
    };

    Matrix() : MatrixBase<T, (2 * 2), 2, M2>{} {
    }
};

//---------------------------------------------------------
// Matrix 3
//---------------------------------------------------------

using M3 = Matrix<float, (3 * 3), 3>;

template<typename T>
class Matrix<T, (3 * 3), 3> : public MatrixBase<T, (3 * 3), 3, Matrix<float, (3 * 3), 3>> {
public:

    Matrix() : MatrixBase<T, (3 * 3), 3, Matrix<float, (3 * 3), 3>>{} {
    }

    Matrix(const std::array<T, (3*3)> &values) : MatrixBase<T, (3*3), 3, Matrix<T, (3*3), 3>>{values} {

    }
};

//---------------------------------------------------------
// Matrix 4
//---------------------------------------------------------

typedef Matrix<float, (4 * 4), 4> M4;

template<typename T>
class Matrix<T, (4 * 4), 4> : public MatrixBase<T, (4 * 4), 4, M4> {
public:
    Matrix() : MatrixBase<T, (4 * 4), 4, M4>{} {
    }

    Matrix(const std::array<T, (4*4)> &values) : MatrixBase<T, (4*4), 4, M4>{values} {

    }
};