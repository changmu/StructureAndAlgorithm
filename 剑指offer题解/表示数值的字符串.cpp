/************************************************************* 
 * 实现一个函数用来判断字符串是否表示数值。表示数值的字符串
 * 遵循如下模式：
 * [sign]integral-digits[.[fractional-digits]][e|E[sign]exponential-digits]
 *************************************************************/ 
#include <stdio.h>

void scanDigits(char **string)
{
	while (**string >= '0' && **string <= '9')
		++*string;
}

bool isNumeric(char *string)
{
	if (string == NULL) return false;

	if (*string == '+' || *string == '-')
		++string;
	if (*string == '\0') return false; // 只有符号或空串

	scanDigits(&string);
	if (*string == '\0') return true; // 只有整数部分

	if (*string == '.') {
		scanDigits(&++string);
	}
	
	if (*string == 'e' || *string == 'E') {
		if (*++string == '+' || *string == '-')
			++string;
		if (*string == '\0') return false; // 指数只有符号或什么都没有
		scanDigits(&string);
	}

	return *string == '\0';
}
// ==================== Test Code ====================

void Test(char* testName, char* string, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(isNumeric(string) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    Test("Test1", "100", true);
    Test("Test2", "123.45e+6", true);
    Test("Test3", "+500", true);
    Test("Test4", "5e2", true);
    Test("Test5", "3.1416", true);
    Test("Test6", "600.", true);
    Test("Test7", "-.123", true);
    Test("Test8", "-1E-16", true);
    Test("Test9", "1.79769313486232E+308", true);

    printf("\n\n");

    Test("Test10", "12e", false);
    Test("Test11", "1a3.14", false);
    Test("Test12", "1+23", false);
    Test("Test13", "1.2.3", false);
    Test("Test14", "+-5", false);
    Test("Test15", "12e+5.4", false);

	return 0;
}
