/*
** 题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数。
class CMyString {
public:
	CMyString(char *pData = NULL);
	CMyString(const CMyString& str);
	~CMyString(void);

private:
	char *m_pData;
};
*/

/*
** 思路：需要考虑4点：
** 1、是否把返回值类型声明为该类型的引用，并在函数结束前返回实例自身的引用即*this。这样连续赋值才有意义。
** 2、是否把传入的参数的类型声明为常量引用。如果传入的参数不是引用而是实例，那么从形参到实参会调用一次复制构造函数。把参数声明为引用可以避免这样的无谓消耗，提高代码效率，同时由于不改变实参状态，那么给形参加上const关键字。
** 3、是否释放实例自身已有的内存。如果我们忘记在分配新内存之前释放自身已有的空间，程序将出现内存泄露。
** 4、判断传入的参数和当前的实例(*this)是不是同一个实例。如果事先不判断就进行赋值，那么在释放实例自身的内存时就会导致严重的问题：找不到需要赋值的内容了。
*/

// 经典解法，入门级程序员
CMyString& CMyString::operator = (const CMyString& str) {
	if (this == &str) return *this;

	delete[] m_pData;
	m_pData = NULL;

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);

	return *this;
}

/*
** 经典解法的缺陷：new可能会抛出异常，违背了异常安全性原则，有两种解决方法：1、在new分配成功后再释放已有的内容；2、创建临时实例，交换临时实例和原来实例的内容。
*/

// 高级解法，高级程序员
CMyString& CMyString::operator = (const CMyString& str) {
	if (this == &str) return *this;

	CMystring tmp(str);
	char *ptmp = tmp.m_pData;
	tmp.m_pData = m_pData;
	m_pData = ptmp;

	return *this;
}

// via:changmu
