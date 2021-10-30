#ifndef FRACTION
#define FRACTION

#include <iostream>
#include <algorithm>
using namespace std;

class Fraction
{
private:
    int numerator, denominator;

    void normalize();

public:
    Fraction(int x = 0, int y = 1);
    Fraction(const Fraction &f);

    friend istream &operator>>(istream &in, Fraction &f);
    friend ostream &operator<<(ostream &out, const Fraction &f);

    friend Fraction operator+(const Fraction &x, const Fraction &y);
    friend Fraction operator-(const Fraction &x, const Fraction &y);
    friend Fraction operator*(const Fraction &x, const Fraction &y);
    friend Fraction operator/(const Fraction &x, const Fraction &y);

    void operator+=(const Fraction &f);
    void operator-=(const Fraction &f);
    void operator*=(const Fraction &f);
    void operator/=(const Fraction &f);

    bool operator==(const Fraction &f);
    bool operator!=(const Fraction &f);
    bool operator>(const Fraction &f);
    bool operator<(const Fraction &f);
    bool operator>=(const Fraction &f);
    bool operator<=(const Fraction &f);

    Fraction &operator++();
    Fraction operator++(int);
    Fraction &operator--();
    Fraction operator--(int);

    explicit operator float() const;
};

#pragma region Define Methods
#pragma region Constructors
Fraction::Fraction(int x, int y)
{
    numerator = x;
    denominator = y != 0 ? y : 1;
    normalize();
}

Fraction::Fraction(const Fraction &f)
{
    numerator = f.numerator;
    denominator = f.denominator;
    normalize();
}
#pragma endregion Constructors

#pragma region IO Operators
istream &operator>>(istream &in, Fraction &f)
{
    in >> f.numerator >> f.denominator;
    return in;
}

ostream &operator<<(ostream &out, const Fraction &f)
{
    if (f.denominator == 1)
        out << f.numerator;
    else
        out << f.numerator << "/" << f.denominator;
    return out;
}
#pragma endregion IO Operators

#pragma region Calculate Operators
#pragma region Operators1
Fraction operator+(const Fraction &x, const Fraction &y)
{
    Fraction res(x.numerator * y.denominator + y.numerator * x.denominator, x.denominator * y.denominator);
    res.normalize();
    return res;
}

Fraction operator-(const Fraction &x, const Fraction &y)
{
    Fraction res(x.numerator * y.denominator - y.numerator * x.denominator, x.denominator * y.denominator);
    res.normalize();
    return res;
}

Fraction operator*(const Fraction &x, const Fraction &y)
{
    Fraction res(x.numerator * y.numerator, x.denominator * y.denominator);
    res.normalize();
    return res;
}

Fraction operator/(const Fraction &x, const Fraction &y)
{
    Fraction res(x.numerator / y.numerator, x.denominator / y.denominator);
    res.normalize();
    return res;
}
#pragma endregion Operators1

#pragma region Operators2
void Fraction::operator+=(const Fraction &f)
{
    *this = *this + f;
}

void Fraction::operator-=(const Fraction &f)
{
    *this = *this - f;
}

void Fraction::operator*=(const Fraction &f)
{
    *this = *this * f;
}

void Fraction::operator/=(const Fraction &f)
{
    *this = *this / f;
}
#pragma endregion Operators2

#pragma region Operators3
Fraction &Fraction::operator++()
{
    numerator += denominator;
    normalize();
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction temp(*this);
    ++*this;
    return temp;
}

Fraction &Fraction::operator--()
{
    numerator -= denominator;
    normalize();
    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction temp(*this);
    --*this;
    return temp;
}
#pragma endregion Operators3
#pragma endregion Calculate Operators

#pragma region Compare Operators
bool Fraction::operator==(const Fraction &f)
{
    Fraction x = *this, y = f;
    x.normalize();
    y.normalize();

    return x.numerator == y.numerator && x.denominator == y.denominator;
}

bool Fraction::operator!=(const Fraction &f)
{
    return !(*this == f);
}

bool Fraction::operator>(const Fraction &f)
{
    Fraction temp = *this - f;
    return temp.numerator * temp.denominator > 0;
}

bool Fraction::operator<(const Fraction &f)
{
    return !(*this > f) && (*this != f);
}

bool Fraction::operator>=(const Fraction &f)
{
    return !(*this < f);
}

bool Fraction::operator<=(const Fraction &f)
{
    return !(*this > f);
}
#pragma endregion Compare Operators

Fraction::operator float() const
{
    return (float)numerator / (float)denominator;
}

void Fraction::normalize()
{
    if (denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }

    if (numerator != 0)
    {
        int normalGCD = __gcd(abs(numerator), denominator);
        numerator /= normalGCD;
        denominator /= normalGCD;
    }
}
#pragma endregion Define Methods
#endif