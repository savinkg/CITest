#pragma once

class Complex
{
private:
    int _re;
    int _im;
public:
    Complex(int re = 0, int im = 0);
    virtual ~Complex();

    int getRe() const
    {
        return _re;
    }
    int getIm() const
    {
        return _im;
    }
    constexpr Complex operator+(const Complex& op);
    constexpr Complex operator-(const Complex& op);
    constexpr Complex operator+=(const Complex& op);
    constexpr Complex operator-=(const Complex& op);
};

constexpr bool operator==(const Complex &op1,const Complex &op2);
