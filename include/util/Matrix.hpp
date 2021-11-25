#pragma once

#include <array>

template<typename T, unsigned int N, unsigned int M>
struct Matrix {
    std::array<T, N * M> values;
    int rows{N};
    int columns{M};

    //--------------------------------------------------------------
    // Matrix Addition and subtraction
    //--------------------------------------------------------------
    //
    // We can only add and subtract Matrices of the same size
    //

    Matrix &operator+=(const Matrix &other) {
        for (int i = 0; i < values.size(); ++i) {
            values[i] += other.values[i];
        }
        return *this;
    }

    friend Matrix operator+(const Matrix &a, const Matrix &b) {
        Matrix temp;
        for (int i = 0; i < a.values.size(); ++i) {
            temp.values[i] = a.values[i] + b.values[i];
        }
        return temp;
    }

    Matrix &operator-=(const Matrix &other) {
        for (int i = 0; i < values.size(); ++i) {
            values[i] -= other.values[i];
        }
        return *this;
    }

    friend Matrix operator-(const Matrix &a, const Matrix &b) {
        Matrix temp;
        for (int i = 0; i < a.values.size(); ++i) {
            temp.values[i] = a.values[i] - b.values[i];
        }
        return temp;
    }

    //--------------------------------------------------------------
    // Matrix Multiplication
    //--------------------------------------------------------------
    //
    // Scalar: multiply every value
    // Vector:
    // Matrix:

    Matrix &operator*=(const T &value) {
        for (int i = 0; i < values.size(); ++i) {
            values[i] *= value;
        }
        return *this;
    }

    //TODO [SJORS]:
    // -Multiply with Vector
    // -Multiply with Matrix
};

using M2 = Matrix<float, 2, 2>;
using M3 = Matrix<float, 3, 3>;
