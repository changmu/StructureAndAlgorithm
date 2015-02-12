/************************************************************* 
 * 求1+2+...+n，要求不能使用乘除法、for、while、if、switch等
 * 关键字及条件判断语句。
 *************************************************************/ 
// 解法一：利用构造函数求解
#include <iostream>

using namespace std;

class Temp {
	private:
		static int N;
		static int Sum;

	public:
		Temp() { Sum += ++N; }

		static void Reset() { N = Sum = 0; }
		static int GetSum() { return Sum; }
};

int Temp::Sum = 0;
int Temp::N = 0;

int Sum_Solution1(int n)
{
	Temp::Reset();
	delete[] new Temp[n];

	return Temp::GetSum();
}

// 解法二：利用虚函数求解
class A;
A *Array[2];

class A {
	public:
		virtual int Sum(int n) {
			return 0;
		}
};

class B: public A {
	public:
		virtual int Sum(int n) {
			return Array[!!n]->Sum(n - 1) + n;
		}
};

int Sum_Solution2(int n)
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;

	return Array[1]->Sum(n);
}

// 解法三：利用函数指针求解
typedef int (*fun)(int);

int Teminator(int n) { return 0; }

int Sum_Solution3(int n)
{
	static fun f[2] = {Sum_Solution3, Teminator};
	return f[!n](n - 1) + n;
}

// 解法四：利用模板类型求解，n必须是编译期能确定的常量
template<int n> struct Sum_Solution4 {
	enum Value { N = Sum_Solution4<n - 1>::N + n };
};

template<> struct Sum_Solution4<1> {
	enum Value { N = 1 };
};

int main()
{
	int n;
//	while (cin >> n)
	cout << Sum_Solution4<100>::N << endl;
	return 0;
}
