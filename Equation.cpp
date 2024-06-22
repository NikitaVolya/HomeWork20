#include "Equation.h"

MyMath::Equation::Root::Root() : x1(0), x2(0), isQR(false), isEmpty(true)
{

}
MyMath::Equation::Root::Root(const Fraction& value) : x1(value), x2(0), isQR(false), isEmpty(false)
{

}
MyMath::Equation::Root::Root(const Fraction& value1, const Fraction& value2) : x1(value1), x2(value2), isQR(true), isEmpty(false)
{

}


MyMath::Fraction MyMath::Equation::Root::getX() const
{
	if (isEmpty) 
		throw* this;  
	return x1;
}

MyMath::Fraction MyMath::Equation::Root::getX1() const
{
	return getX();
}

MyMath::Fraction MyMath::Equation::Root::getX2() const
{
	if (!isQR || isEmpty) 
		throw* this; 
	return x2;
}

inline bool MyMath::Equation::Root::isQuadraticRoot() const
{
	return isQR;
}

bool MyMath::Equation::Root::isClear() const
{
	return isEmpty;
}

std::ostream& MyMath::operator<<(std::ostream& out, const MyMath::Equation::Root& root)
{
	if (root.isClear())
		return out << "[ ]";

	out << '[' << root.getX();
	if (root.isQuadraticRoot())
		out << " : " << root.getX2();
	return out << ']';
}

MyMath::Equation::Equation(const MyMath::Fraction& pValueA, const MyMath::Fraction& pValueB) : a(pValueA), b(pValueB)
{
	if (pValueA == 0) 
		throw std::invalid_argument("A can`t be 0");
};

MyMath::Equation::Root MyMath::LinearEquation::equationRoot() const
{
	return MyMath::Equation::Root{ -b / a};
}

std::ostream& MyMath::operator<<(std::ostream& out, const MyMath::LinearEquation& eq)
{
	return std::cout << "( " << eq.getA() << "x + " << eq.getB() <<" )";
}

std::ostream& MyMath::operator<<(std::ostream& out, const QuadraticEquation& eq)
{
	return std::cout << "( " << eq.getA() << "x^2 + " << eq.getB() << "x + " << eq.getC() << " )";
}

MyMath::Fraction MyMath::QuadraticEquation::delta() const
{
	return b * b - a * c * 4;
}

MyMath::Equation::Root MyMath::QuadraticEquation::equationRoot() const
{
	MyMath::Fraction d = delta();
	if (d < 0)
		return MyMath::Equation::Root{};


	d = MyMath::Fraction{ sqrtf(d.getNumerator() / d.getDenominator()) };

	

	MyMath::Fraction x1 = (-b - d) / (a * 2);
	MyMath::Fraction x2;

	if (d != 0)
	{
		x2 = (-b + d) / (a * 2);
		return Root{x1, x2};
	}
	else
	{
		return Root{ x1 };
	}
}
