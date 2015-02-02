/************************************************************* 
 * 面试题11：数值的整数次方
 * 实现函数 double Power(double base, int exponent)，不需要考虑
 * 大数，不得使用库函数。
 * Edit by changmu
 *************************************************************/ 

bool g_InvalidInput = false;

double Power(double base, int exponent)
{
	g_InvalidInput = false;

	if (equal(base, 0.0) && exponent < 0) {
		g_InvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = (unsigned int)exponent;
	if (exponent < 0) absExponent = (unsigned int)(-exponent);

	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0) result = 1.0 / result;

	return result;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	if (equal(base, 1.0) || equal(base, 0.0)) return base;

	double result = 1.0;
	for ( ; exponent > 0; exponent >>= 1) { //快速幂
		if (exponent & 0x1) result *= base;
		base *= base;
	}

	return result;
}

bool equal(double num1, double num2)
{
	return num1 - num2 > -1e-7 && num1 - num2 < 1e-7;
}
