#include <iostream>
#include <cassert>
#include <vector>     // std::vector
#include <algorithm>  // std::transform
#include <functional> // std::plus
#include <math.h>     // Pow, sqrt trig etc.

#ifndef VECTORND_H
#define VECTORND_H

//Forward declarations required for templated friend functions.
template <class T>
class VectorND;

template <class T>
bool operator==(const VectorND<T> &v1, const VectorND<T> &v2);

template <class T>
bool operator!=(const VectorND<T> &v1, const VectorND<T> &v2);

template <class T>
VectorND<T> operator*(const VectorND<T> &v1, const T a);

template <class T>
VectorND<T> operator*(const T a, const VectorND<T> &v1);

template <class T>
VectorND<T> operator/(const VectorND<T> &v1, const T a);

template <class T>
VectorND<T> operator/(const T a, const VectorND<T> &v1);

template <class T>
std::ostream &operator<<(std::ostream &output, const VectorND<T> &v1);

template <class T>
class VectorND
{
    std::vector<T> data; // Vector data stored here.

    friend bool operator==<>(const VectorND<T> &v1, const VectorND<T> &v2);

    friend bool operator!=<>(const VectorND<T> &v1, const VectorND<T> &v2);

    friend VectorND<T> operator*<>(const VectorND<T> &v1, const T a);

    friend VectorND<T> operator*<>(const T a, const VectorND<T> &v1);

    friend VectorND<T> operator/<>(const VectorND<T> &v1, const T a);

    friend VectorND<T> operator/<>(const T a, const VectorND<T> &v1);

    friend std::ostream &operator<< <>(std::ostream &output, const VectorND<T> &v1);

  public:
    // Convenient accessor to our custom vector's length.

    constexpr int length() { return data.size(); }

    // Initialise a move constructor with a std::vector

    constexpr VectorND(std::vector<T> &&values) : data(values){/*std::cout << "Move";*/};

    // Initialise a reference constructor with a std::vector input.
    constexpr VectorND(const std::vector<T> &values) : data(values){/*std::cout << "Ref";*/};

    inline VectorND()
    { /* Constructor with no parameters*/
    }

    // Destructor
    ~VectorND();

    // Construct empty vector of zeroes
    inline VectorND(int N) : data(N, 0) {}

    // Operator overload for vector addition
    VectorND<T> operator+(const VectorND &v1)
    {
        std::vector<T> rv(v1.data);
        assert(data.size() == rv.size());

        VectorND<T> result(rv.size());

        for (int i = 0; i < data.size(); i++)
        {
            result[i] = data[i] + rv[i];
        }
        return result;
    }

    // Operator overload for vector subtraction
    VectorND<T> operator-(const VectorND &v1)
    {
        std::vector<T> rv(v1.data);
        assert(data.size() == rv.size());

        VectorND<T> result(rv.size());

        for (int i = 0; i < data.size(); i++)
        {
            result[i] = data[i] - rv[i];
        }
        return result;
    }

    T& operator[] (const int i)
    {
        return data[i];
    }

    // Dot product
    T dot(const VectorND &v1)
    {
        T result = 0;
        std::vector<T> rv(v1.data);
        assert(data.size() == rv.size());
        for (int i = 0; i < rv.size(); i++)
        {
            result += data[i] * rv[i];
        }
        return result;
    }

    // Calculate vector magnitude.
    T magnitude()
    {
        T result = 0;
        for (auto &x : data)
        {
            result += pow(x, 2); // Sum the power of each component
        }
        return sqrt(result);
    }

    // Calculate the unit vector.
    VectorND<T> unit()
    {
        VectorND<T> rv(data);
        return rv / rv.magnitude();
    }

    // Display vector
    void show()
    {
        std::cout << '[';
        for (int i = 0; i < data.size(); i++)
        {
            std::cout << data[i];
            if (i < data.size() - 1)
            {
                std::cout << ',';
            }
        }
        std::cout << ']' << std::endl;
    }
};

template <class T>
VectorND<T>::~VectorND() {} // Destructor

template <class T>
bool operator==(const VectorND<T> &v1, const VectorND<T> &v2)
{
    std::vector<T> rv1(v1.data);
    std::vector<T> rv2(v2.data);
    for (int i = 0; i < rv1.size(); i++)
    {
        if (rv1[i] != rv2[i])
        {
            return false;
        }
    }
    return true;
}

template <class T>
bool operator!=(const VectorND<T> &v1, const VectorND<T> &v2)
{
    std::vector<T> rv1(v1.data);
    std::vector<T> rv2(v2.data);
    for (int i = 0; i < rv1.size(); i++)
    {
        if (rv1[i] != rv2[i])
        {
            return true;
        }
    }
    return false;
}

template <class T>
VectorND<T> operator*(const VectorND<T> &v1, const T a)
{
    std::vector<T> rv(v1.data);
    for (auto &i : rv)
        i *= a;
    VectorND<T> result(std::move(rv));
    return result;
}

template <class T>
VectorND<T> operator*(const T a, const VectorND<T> &v1)
{
    std::vector<T> rv(v1.data);
    for (auto &i : rv)
        i *= a;
    VectorND<T> result(std::move(rv));
    return result;
}

template <class T>
std::ostream &operator<<(std::ostream &output, const VectorND<T> &v1)
{
    
    output << '[';
        for (int i = 0; i < v1.data.size(); i++)
        {
            output << v1.data[i];
            if (i < v1.data.size() - 1)
            {
                output << ',';
            }
        }
        output << ']' << std::endl;
    return output;
}

template <class T>
VectorND<T> operator/(const VectorND<T> &v1, const T a)
{
    std::vector<T> rv(v1.data);
    for (auto &i : rv)
        i /= a;
    return rv;
}

template <class T>
VectorND<T> operator/(const T a, const VectorND<T> &v1)
{
    std::vector<T> rv(v1.data);
    for (auto &i : rv)
        i /= a;
    return rv;
}
#endif