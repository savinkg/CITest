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
    this->_re = this._re + op.getRe();
    this->_im = this._im + op.getIm();

    return this;
}

constexpr Complex Complex::operator-=(const Complex& op)
{
    this._re = this._re - op.getRe();
    this._im = this._im - op.getIm();

    return this;
}
constexpr bool operator==(const Complex& op1,const Complex& op2)
{
    return (op1.getRe() == op2.getRe()) && (op1.getIm() == op2.getIm());
}

//constexpr Complex operator "" _i(int im)
//{
 //   Complex value(0,im);
 //   return value;
//}
