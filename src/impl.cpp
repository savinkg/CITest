#include "impl.h"

Complex::Complex(int re,int im): _re(re),_im(im)
{
    _re = re;
    _im = im;
}
Complex::~Complex()
{
}

constexpr Complex Complex::operator+(const Complex& op)
{
    Complex result;

    result._re = _re + op.getRe();
    result._im = _im + op.getIm();

    return result;
}

constexpr Complex Complex::operator-(const Complex& op)
{
    Complex result;

    result._re = _re - op.getRe();
    result._im = _im - op.getIm();

    return result;
}

constexpr Complex Complex::operator+=(const Complex& op)
{
    Complex result;

    result._re = _re + op.getRe();
    result._im = _im + op.getIm();

    return result;
}

constexpr Complex Complex::operator-=(const Complex& op)
{
    Complex result;

    result._re = _re - op.getRe();
    result._im = _im - op.getIm();

    return result;
}
constexpr bool Complex::operator==(const Complex& op1,const Complex& op2)
{
    return (op1.getRe() == op2.getRe()) && (op1.getIm() == op2.getIm());
}

constexpr Complex operator "" _i(int re, int im)
{
    return {re,im};
}
