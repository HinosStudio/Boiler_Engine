#pragma once

#include <boiler/util/Composite.hpp>

template<typename T, unsigned int N, unsigned int M>
class Matrix_Base : public Composite<T, N * M> {
public:
    Matrix_Base operator*(const Matrix_Base &other) const {
        if(N != M) throw std::runtime_error("cannot multiply array");
        Matrix_Base temp{};

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                auto index = (i * N) + j;
                for (int k = 0; k < N; ++k) {
                    temp[index] += this->_values[(i * N) + k] * other[(k * N) + j];
                }
            }
        }

        return temp;
    }

    void operator*=(const Matrix_Base &other){
        *this = operator*(other);
    }

    Composite<T, N> operator*(const Composite<T,N> &vector){
        Composite<T,N> temp;
        temp.MakeZero();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                temp[i] += this->_values[(i * N) + j] * vector[j];
            }
        }
        return temp;
    }

    void MakeIdentity(){
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                this->_values[(i * M) + j] = i == j;
            }
        }
    }
};

template<typename T, unsigned int N, unsigned int M>
class Matrix : public Matrix_Base<T,N,M>{

};

typedef Matrix<float, 3, 3> M3;
typedef Matrix<float, 4, 4> M4;

template<typename T>
class Matrix<T, 4, 4> : public Matrix_Base<T,4,4>{
public:

    Matrix &operator=(const Composite<T, 16> &other) {
        if (this != &other) {
            for (int i = 0; i < 16; ++i) {
                this->_values[i] = other[i];
            };
        }
        return *this;
    }

    void MakeRotX(float value){
        Matrix_Base<T,4,4>::MakeIdentity();
        this->_values[5] = std::cos(value);
        this->_values[6] = -std::sin(value);
        this->_values[9] = std::sin(value);
        this->_values[10] = std::cos(value);
    }

    void MakeRotY(float value){
        Matrix_Base<T,4,4>::MakeIdentity();
        this->_values[0] = std::cos(value);
        this->_values[2] = -std::sin(value);
        this->_values[8] = std::sin(value);
        this->_values[10] = std::cos(value);
    }

    void MakeRotZ(float value){
        Matrix_Base<T,4,4>::MakeIdentity();
        this->_values[0] = std::cos(value);
        this->_values[1] = -std::sin(value);
        this->_values[4] = std::sin(value);
        this->_values[5] = std::cos(value);
    }

    void MakeRotXR(float value){
        Matrix_Base<T,4,4>::MakeIdentity();
        this->_values[5] = std::cos(value);
        this->_values[6] = std::sin(value);
        this->_values[9] = -std::sin(value);
        this->_values[10] = std::cos(value);
    }

    void MakeRotYR(float value){
        Matrix_Base<T,4,4>::MakeIdentity();
        this->_values[0] = std::cos(value);
        this->_values[2] = std::sin(value);
        this->_values[8] = -std::sin(value);
        this->_values[10] = std::cos(value);
    }

    void MakeRotZR(float value){
        Matrix_Base<T,4,4>::MakeIdentity();
        this->_values[0] = std::cos(value);
        this->_values[1] = std::sin(value);
        this->_values[4] = -std::sin(value);
        this->_values[5] = std::cos(value);
    }

    void MakeTrans(const Composite<T,3> &value){
        Matrix_Base<T,4,4>::MakeIdentity();
        this->_values[3] = value[0];
        this->_values[7] = value[1];
        this->_values[11] = value[2];
    }

    void MakeScale(const Composite<T,3> &value){
        Matrix_Base<T,4,4>::MakeIdentity();
        this->_values[0] = value[0];
        this->_values[5] = value[1];
        this->_values[10] = value[2];
    }

    void MakeProjection(float near, float far, float fov, float aspect){
        float fovRad = near / std::tan(fov * 0.5f / 180.0f * 3.14159f);

        Matrix_Base<T,4,4>::MakeZero();
        this->_values[0] = aspect * fovRad;
        this->_values[5] = fovRad;
        this->_values[10] = far / (far - near);
        this->_values[11] = -1.0f;
        this->_values[14] = (-far * near) / (far - near);
    }

    static M4 Zero(){M4 m; m.MakeZero(); return m;}
    static M4 Identity(){M4 m; m.MakeIdentity(); return m;}
    static M4 RotX(float value){M4 m; m.MakeRotX(value); return m;}
    static M4 RotY(float value){M4 m; m.MakeRotY(value); return m;}
    static M4 RotZ(float value){M4 m; m.MakeRotZ(value); return m;}
    static M4 RotXR(float value){M4 m; m.MakeRotXR(value); return m;}
    static M4 RotYR(float value){M4 m; m.MakeRotYR(value); return m;}
    static M4 RotZR(float value){M4 m; m.MakeRotZR(value); return m;}
    static M4 Trans(const Composite<T,3> &vector){M4 m; m.MakeTrans(vector); return m;}
    static M4 Scale(const Composite<T,3> &vector){M4 m; m.MakeScale(vector); return m;}
};