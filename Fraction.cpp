#include "Fraction.h"

MyMath::Fraction& MyMath::Fraction::autoResize()
{
	if (numerator == 0)
		return *this;

	int pgcd = MyMath::PGCD(numerator, denominator);

	numerator /= pgcd;
	denominator /= pgcd;

	if (denominator < 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
	return *this;
}

MyMath::Fraction::Fraction(const MyMath::Fraction& other) : numerator(other.numerator), denominator(other.denominator) { }

MyMath::Fraction::Fraction(float number)
{
	bool b = false;

	if (number < 0)
	{
		b = true;
		number *= 1;
	}

	int denom = 10;
	while (int(number * denom) % 10 != 0)
		denom *= 10;
	denom /= 10;

	numerator = int(number * denom) * (b ? -1 : 1);
	denominator = denom;
	autoResize();
}


MyMath::Fraction::Fraction(int number) : numerator(number), denominator(1) { }

MyMath::Fraction::Fraction(int numer, int denom) : Fraction()
{
	setNumerator(numer);
	setDenominator(denom);
}


MyMath::Fraction& MyMath::Fraction::operator=(const Fraction& other)
{
	if (other == *this)
		return *this;
	numerator = other.numerator;
	denominator = other.denominator;
	return *this;
}


float MyMath::Fraction::toFloat() const
{
	return (float)numerator / denominator;
}


inline int MyMath::Fraction::getNumerator() const
{
	return numerator;
}

inline int MyMath::Fraction::getDenominator() const
{
	return denominator;
}


inline void MyMath::Fraction::setNumerator(int number)
{ 
	numerator = number; 
	autoResize();
};

void MyMath::Fraction::setDenominator(int number)
{
	if (denominator == 0) 
		throw std::invalid_argument("Denominator cant be 0"); 
	denominator = number;
	autoResize();
}


MyMath::Fraction MyMath::Fraction::operator-() const
{
	return MyMath::Fraction{ -numerator, denominator };
}


MyMath::Fraction MyMath::Fraction::operator+(const MyMath::Fraction& other) const
{ 
	return MyMath::Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}

MyMath::Fraction MyMath::Fraction::operator-(const MyMath::Fraction& other) const
{
	return MyMath::Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
}

MyMath::Fraction MyMath::Fraction::operator*(const MyMath::Fraction& other) const
{
	return MyMath::Fraction(numerator * other.numerator, denominator * other.denominator);
}

MyMath::Fraction MyMath::Fraction::operator/(const MyMath::Fraction& other) const
{
	return MyMath::Fraction(numerator * other.denominator, denominator * other.numerator);
}


MyMath::Fraction MyMath::Fraction::operator+(int value) const
{
	return MyMath::Fraction(numerator + value * denominator, denominator);
}

MyMath::Fraction MyMath::Fraction::operator-(int value) const
{
	return MyMath::Fraction(numerator - value * denominator, denominator);
}

MyMath::Fraction MyMath::Fraction::operator*(int value) const
{
	return MyMath::Fraction(numerator * value, denominator);
}

MyMath::Fraction MyMath::Fraction::operator/(int value) const
{
	return MyMath::Fraction(numerator, denominator * value);
}


bool MyMath::Fraction::operator>(const MyMath::Fraction& other) const
{
	return numerator * other.denominator > other.numerator * denominator;
}

bool MyMath::Fraction::operator<(const MyMath::Fraction& other) const
{
	return numerator * other.denominator > other.numerator * denominator;
}

bool MyMath::Fraction::operator==(const MyMath::Fraction& other) const
{
	return numerator == other.numerator;
}

bool MyMath::Fraction::operator!=(const MyMath::Fraction& other) const
{
	return numerator != other.numerator;
}

bool MyMath::Fraction::operator>(int value) const
{
	return numerator > value * denominator;
}

bool MyMath::Fraction::operator<(int value) const
{
	return numerator < value * denominator;
}

bool MyMath::Fraction::operator==(int value) const
{
	return numerator == value * denominator;
}

bool MyMath::Fraction::operator!=(int value) const
{
	return numerator != value * denominator;
}


std::ostream& MyMath::operator<<(std::ostream& out, const MyMath::Fraction& fraction)
{
	if (fraction.getDenominator() != 1)
		out << fraction.getNumerator() << '/' << fraction.getDenominator();
	else
		out << fraction.getNumerator();
	return out;
}

std::istream& MyMath::operator>>(std::istream& in, MyMath::Fraction& fraction)
{
	int n, d;
	in >> n >> d;
	fraction.setNumerator(n);
	fraction.setDenominator(d);
	return in;
}


MyMath::Fraction MyMath::abs(const Fraction& fraction)
{
	return MyMath::Fraction{(fraction.getNumerator() < 0 ? -fraction.getNumerator() : fraction.getNumerator()), fraction.getDenominator()};
}

MyMath::Fraction MyMath::max(const Fraction& first, const Fraction& second)
{
	return (first > second ? first : second);
}

MyMath::Fraction MyMath::min(const Fraction& first, const Fraction& second)
{
	return (first < second ? first : second);
}
