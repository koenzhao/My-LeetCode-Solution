#include <stdio.h>

double PowerWithUnsignedExponent(double base, unsigned int exponent);
double Power(double base, int exponent);
int equal(double num1, double num2);
int g_InvalidInput = 0;

double Power(double base, int exponent)
{
	if (equal(base, 0) && exponent < 0)
	{
		g_InvalidInput = 1;
		return 0.0;
	}
		
	unsigned unsigned_exponent = exponent < 0 ? (unsigned int)-exponent : (unsigned int)exponent;
	double result = PowerWithUnsignedExponent(base, unsigned_exponent);
	if (exponent<0)
	{
		result = 1.0 / result;
	}
	return result;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double result = PowerWithUnsignedExponent(base, exponent >> 1);
	result *= result;
	if ((exponent & 0x1) == 1)
		result *= base;
	return result;
}

int equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2) < 0.0000001)
		return 1;
	else
		return 0;
}

int main()
{
	double result = 0.0;
	double base = 0.0;
	int exponent = 0;
	printf("Please input base and exponent: ");
	scanf_s("%lf,%d", &base, &exponent);
	result = Power(base,exponent);
	if (g_InvalidInput == 1)
		printf("The input is invailable!\n");
	else 
		printf("%lf ^ %d = %lf\n",base,exponent,result);

	return 0;
}
