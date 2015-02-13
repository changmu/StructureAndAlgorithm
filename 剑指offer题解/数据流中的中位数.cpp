template<typename T>
class DynamicArray {
public:
	void Insert(T num) {
		if ((min.size() + max.size()) & 1) {
			if (!min.empty() && min[0] < num) {
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<T>());

				num = min[0];

				pop_heap(min.begin(), min.end(), greater<T>());
				min.pop_back();
			}

			max.push_back(num);
			push_heap(max.begin(), max.end(), less<T>());
		} else {
			if (!max.empty() && num > max[0]) {
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<T>());

				num = max[0];

				pop_heap(max.begin(), max.end(), less<T>());
				max.pop_back();
			}

			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<T>());
		}
	}

	T GetMedian() {
		if ((min.size() + max.size()) & 1)
			return min[0];
		else if (min.empty()) 
			throw exception("No numbers");
		else return (min[0] + max[0]) / 2;
	}

private:
	vector<T> min;
	vector<T> max;
};
