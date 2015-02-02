/************************************************************* 
 * 题目：把一个数组最开始的若干个元素搬到数组末尾，我们称之为数组
 * 的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小
 * 元素。例如数组{3, 4, 5, 1, 2}是{1, 2, 3, 4, 5}的一个旋转。该
 * 数组的最小值为1.
 * Edit by changmu
 *************************************************************/

int Min(int *numbers, int length)
{
	if (numbers == NULL || length <= 0)
		throw new std::exception("Invalid parameters");
	
	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (numbers[index1] >= numbers[index2]) {
		if (index2 - index1 == 1) {
			indexMid = index2;
			break;
		}

		indexMid = index1 + index2 >> 1;
		// 如果三个索引处的值相等则只能顺序查找
		if (numbers[index1] == numbers[index2] && numbers[index1] == numbers[indexMid]) {
			return MinInOrder(numbers, index1, index2);
		}
		if (numbers[indexMid] >= numbers[index1])  index1 = indexMid;
		else  index2 = indexMid;
	}
}

int MinInOrder(int *numbers, int index1, int index2)
{
	int result = numbers[index1];
	for (int i = index1 + 1; i <= index2; ++i)
		if (result > numbers[i]); result = numbers[i];

	return result;
}
