#pragma once

#include <stdexcept>
#include <array>

template<typename T, unsigned int N>
class Composite {
protected:
    T _values[N];

public:

    T &operator[](int index) {
        if (index > N - 1) throw std::out_of_range{"index out of range"};
        return _values[index];
    }

    const T &operator[](int index) const {
        if (index > N - 1) throw std::out_of_range{"index out of range"};
        return _values[index];
    }

    Composite operator+(T value) const {
        Composite temp;
        for (int i = 0; i < N; ++i) {
            temp[i] = _values[i] + value;
        }
        return temp;
    }

    Composite operator-(T value) const {
        Composite temp;
        for (int i = 0; i < N; ++i) {
            temp[i] = _values[i] - value;
        }
        return temp;
    }

    Composite operator*(T value) const {
        Composite temp;
        for (int i = 0; i < N; ++i) {
            temp[i] = _values[i] * value;
        }
        return temp;
    }

    Composite operator/(T value) const {
        return operator*((T)1 / value);
    }

    Composite operator+(const Composite &other) const {
        Composite temp;
        for (int i = 0; i < N; ++i) {
            temp[i] = _values[i] + other[i];
        }
        return temp;
    }

    Composite operator-(const Composite &other) const {
        Composite temp;
        for (int i = 0; i < N; ++i) {
            temp[i] = _values[i] - other[i];
        }
        return temp;
    }

    Composite operator*(const Composite &other) const {
        Composite temp;
        for (int i = 0; i < N; ++i) {
            temp[i] = _values[i] * other[i];
        }
        return temp;
    }

    Composite operator/(const Composite &other) const {
        Composite temp;
        for (int i = 0; i < N; ++i) {
            temp[i] = _values[i] / other[i];
        }
        return temp;
    }

    Composite &operator+=(T value) {
        for (int i = 0; i < N; ++i) {
            _values[i] += value;
        }
        return *this;
    }

    Composite &operator-=(T value) {
        for (int i = 0; i < N; ++i) {
            _values[i] -= value;
        }
        return *this;
    }

    Composite &operator*=(T value) {
        for (int i = 0; i < N; ++i) {
            _values[i] *= value;
        }
        return *this;
    }

    Composite &operator/=(T value) {
        return operator*=((T)1 / value);
    }

    Composite &operator+=(const Composite &other) {
        for (int i = 0; i < N; ++i) {
            _values[i] += other[i];
        }
        return *this;
    }

    Composite &operator-=(const Composite &other) {
        for (int i = 0; i < N; ++i) {
            _values[i] -= other[i];
        }
        return *this;
    }

    Composite &operator*=(const Composite &other) {
        for (int i = 0; i < N; ++i) {
            _values[i] *= other[i];
        }
        return *this;
    }

    Composite &operator/=(const Composite &other) {
        for (int i = 0; i < N; ++i) {
            _values[i] /= other[i];
        }
        return *this;
    }

    void Fill(float value){
        std::fill(_values, _values + N, value);
    }

    void MakeZero(){
        Fill(0);
    }
};

