#include "MyMath.h"

int MyMath::abs(int value)
{
	return (value < 0 ? -value : value);
}

float MyMath::abs(float value)
{
	return (value < 0 ? -value : value);
}

double MyMath::abs(double value)
{
	return (value < 0 ? -value : value);
}

int MyMath::max(int a, int b)
{
	return (a > b ? a : b);
}

float MyMath::max(float a, float b)
{
	return (a > b ? a : b);
}

double MyMath::max(double a, double b)
{
	return (a > b ? a : b);
}

int MyMath::PGCD(int a, int b)
{
	a = abs(a);
	b = abs(b);

	while (a % b != 0)
	{
		int tmp = a % b;
		a = b;
		b = tmp;
	}

	return b;
}
