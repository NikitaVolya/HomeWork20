
#include <iostream>
#include "Equation.h"

int main()
{
	MyMath::Fraction a{ 15, 3 };
	std::cout << a << std::endl;

	MyMath::Fraction b{ 4, 48 };
	std::cout << b << std::endl;

	MyMath::QuadraticEquation test{ 2, 8, MyMath::Fraction{1, 2} + 7 };
	std::cout << test << " : " << test.equationRoot() << std::endl;

	MyMath::LinearEquation testL{ MyMath::Fraction {1, 6}, 5 };
	std::cout << testL << " : " << testL.equationRoot() << std::endl;

	return 0;
}