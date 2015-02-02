/*************************************************************
 *	面试题7.1：用两个队列实现一个栈。栈的声明如下，请实现它的两个
 *	函数appendTail和deleteTail。
 *	Edit by changmu.
 *************************************************************/

template<typename T> class CStack {
public:
	CStack(void);
	~CStack(void);

	void appendTail(const T& node);
	T deleteTail();

private:
	queue<T> queue1;
	queue<T> queue2;
};

template<typename T> void CStack<T>::appendTail(const T& element)
{
	queue1.push(element);
}

template<typename T> T CStack<T>::deleteTail()
{
	if (queue1.empty() && queue2.empty())
		throw new exception("stack is empty");

	if (!queue1.empty()) {
		while (queue1.size() != 1) {
			queue2.push(queue1.top());
			queue1.pop();
		}

		T tail = queue1.top();
		queue1.pop();
		return tail;
	} else {
		while (queue2.size() != 1) {
			queue1.push(queue2.top());
			queue2.pop();
		}

		T tail = queue2.top();
		queue2.pop();
		return tail;		
	}
}
