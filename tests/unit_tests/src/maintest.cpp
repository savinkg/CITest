#include "maintest.h"
#include "impl.h"

TEST(Lab5,Add)
{
    Complex a(1,2);
    Complex b(3,4);
    Complex expected(4,6);
    Complex actual = a + b;

    ASSERT_EQ(expected,actual);
    ASSERT_EQ(a, Complex(1,2));
    ASSERT_EQ(b, Complex(3,4));
}

TEST(Lab5,Sub)
{
    Complex a(1,2);
    Complex b(3,4);
    Complex expected(-2,-2);
    Complex actual = a - b;

    ASSERT_EQ(expected,actual);
    ASSERT_EQ(a, Complex(1,2));
    ASSERT_EQ(b, Complex(3,4));
}
