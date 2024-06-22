#pragma once

#include <iostream>
#include "MyMath.h"

namespace MyMath
{

	class Fraction
	{
	private:
		int numerator, denominator;
		Fraction& autoResize();
	public:
		Fraction() : numerator(0), denominator(1) {}
		Fraction(const Fraction& other);
		explicit Fraction(float number);
		Fraction(int number);
		Fraction(int numer, int denom);

		Fraction& operator=(const Fraction& other);

		float toFloat() const;

		int getNumerator() const;
		int getDenominator() const;

		void setNumerator(int number);
		void setDenominator(int number);

		Fraction operator-() const;

		Fraction operator+(const Fraction& other) const;
		Fraction operator-(const Fraction& other) const;
		Fraction operator*(const Fraction& other) const;
		Fraction operator/(const Fraction& other) const;

		Fraction operator+(int value) const;
		Fraction operator-(int value) const;
		Fraction operator*(int value) const;
		Fraction operator/(int value) const;

		bool operator>(const Fraction& other) const;
		bool operator<(const Fraction& other) const;
		bool operator==(const Fraction& other) const;
		bool operator!=(const Fraction& other) const;

		bool operator>(int value) const;
		bool operator<(int value) const;
		bool operator==(int value) const;
		bool operator!=(int value) const;


		friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
		friend std::istream& operator>>(std::istream& in, Fraction& fraction);
	};

	Fraction abs(const Fraction& fraction);
	Fraction max(const Fraction& first, const Fraction& second);
	Fraction min(const Fraction& first, const Fraction& second);
}