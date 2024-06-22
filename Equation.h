#pragma once

#include <iostream>
#include "Fraction.h"

namespace MyMath
{
	class Equation
	{
	protected:
		 Fraction a, b;
	public:
		class Root
		{
			Fraction x1;
			Fraction x2;
			bool isQR;
			bool isEmpty;
		public:
			Root();
			Root(const Fraction& value);
			Root(const Fraction& value1, const Fraction& value2);

			Fraction getX() const;
			Fraction getX1() const;
			Fraction getX2() const;

			bool isQuadraticRoot() const;
			bool isClear() const;

			friend std::ostream& operator<<(std::ostream& out, const Root& root);
		};

		Equation(const Fraction& pValueA, const Fraction& pValueB);

		Fraction getA() const { return a; }
		Fraction getB() const { return b; }

		virtual Equation::Root equationRoot() const = 0;
	};

	class LinearEquation : public Equation
	{
	public:
		LinearEquation(const Fraction& pValueA, const Fraction& pValueB) : Equation(pValueA, pValueB) {}
		Root equationRoot() const override final;

		friend std::ostream& operator<<(std::ostream& out, const LinearEquation& eq);
	};

	class QuadraticEquation : public Equation
	{
	private:
		Fraction c;
	public:
		QuadraticEquation(const Fraction& valueA, const Fraction& valueB, const Fraction& valueC) : Equation(valueA, valueB), c(valueC) {};

		Fraction getC() const { return c; }

		Fraction delta() const;
		Root equationRoot() const override final;

		friend std::ostream& operator<<(std::ostream& out, const QuadraticEquation& eq);
	};
}