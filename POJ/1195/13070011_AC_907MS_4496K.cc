#include <stdio.h>

int tree[1030][1030], size;

int lowBit(int n)
{
	return n & (-n);
}

void getSize()
{
	scanf("%d", &size);
}

void update()
{
	int x, y, val;
	scanf("%d%d%d", &x, &y, &val);
	++x; ++y;
	
	int temp;
	while(x <= size){
		temp = y;
		while(temp <= size){
			tree[x][temp] += val;
			temp += lowBit(temp);
		}
		x += lowBit(x);
	}
}

int getSum(int x, int y)
{
	int sum = 0, temp;
	while(x > 0){
		temp = y;
		while(temp > 0){
			sum += tree[x][temp];
			temp -= lowBit(temp);
		}
		x -= lowBit(x);
	}
	return sum;
}

void query()
{
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	++x1; ++y1; ++x2; ++y2;
	
	int sum = getSum(x2, y2) - getSum(x2, y1 - 1) - 
		getSum(x1 - 1, y2) + getSum(x1 - 1, y1 - 1);
	printf("%d\n", sum);
}

void (*funArr[])() = {
	getSize, update, query
}; //函数指针数组

int main()
{
	int com;
	while(scanf("%d", &com), com != 3)
		(*funArr[com])();	
	return 0;
}