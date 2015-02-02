/************************************************************* 
 * 定义栈的数据结构，在该类型中实现一个能够得到栈的最小元素的
 * min函数。在该栈中，调用min、push、pop的时间复杂度都是O(1)
 * Edit by changmu
 *************************************************************/ 

template<typename T> class StackWithMin {
	stack<T> m_data;
	stack<T> m_min;
};

template<typename T> void StackWithMin<T>::push(const T& value)
{
	m_data.push(value);

	if (m_min.empty() || value < m_min.top())
		m_min.push(value);
	else m_min.push(m_min.top());
}

template<typename T> void StackWithMin<T>::pop()
{
	assert(m_data.size());

	m_data.pop();
	m_min.pop();
}

template<typename T> const T& StackWithMin::min() const
{
	assert(m_data.size());

	return m_min.top();
}
