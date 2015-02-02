////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-29 19:56:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1007
////Problem Title: 
////Run result: Accept
////Run time:1812MS
////Run memory:3352KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define maxn 100002
using std::sort;

struct Node{
	double x, y;
} arr[maxn], temp[maxn];

bool cmpx(Node a, Node b)
{
	return a.x < b.x;
}

bool cmpy(Node a, Node b)
{
	return a.y < b.y;
}

double calDist(int i, int j)
{
	double x = arr[i].x - arr[j].x;
	double y = arr[i].y - arr[j].y;
	return sqrt(x * x + y * y);
}

double divideAndConquer(int l, int r)
{
	if(r - l == 1) return calDist(l, r);
	else if(r - l == 2){
		double a = calDist(l, l + 1);
		double b = calDist(l + 1, r);
		double c = calDist(l, r);
		if(b > c) b = c;
		return a < b ? a : b;
	}
	int mid = (l + r) >> 1, i, j, id = 0;
	double a = divideAndConquer(l, mid);
	double b = divideAndConquer(mid + 1, r);
	double min = a < b ? a : b;
	for(i = l; i <= r; ++i)
		if(fabs(arr[i].x - arr[mid].x) < min) temp[id++] = arr[i];
	sort(temp, temp + id, cmpy);
	for(i = 0; i < id; ++i)
		for(j = i + 1; j < id; ++j){
			a = temp[j].y - temp[i].y;
			if(a >= min) break;
			b = temp[j].x - temp[i].x;
			a = sqrt(a * a + b * b);
			if(a < min) min = a;
		}
	return min;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, i, j;
	double ans, x, y, len;
	while(scanf("%d", &n), n){
		for(i = 0; i < n; ++i)
			scanf("%lf%lf", &arr[i].x, &arr[i].y);
		sort(arr, arr + n, cmpx);
		printf("%.2lf\n", divideAndConquer(0, n - 1) / 2);
	}
	return 0;
}
