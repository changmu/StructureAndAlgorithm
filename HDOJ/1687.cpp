////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-17 20:39:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1687
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
using std::sort;
using std::swap;
double X, Y;
struct Node{
	double left, right;
} arr[102];

double getX(double a, double b){
	return X - Y * (X - a) / (Y - b);
}

bool cmp(Node a, Node b){
	return a.left < b.left;
}

int main(){
	double x1, y1, x2, y2, flag;
	int t, n, ans;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		scanf("%lf%lf", &X, &Y);
		for(int i = 0; i < n; ++i){
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			arr[i].left = getX(x1, y1);
			arr[i].right = getX(x2, y2);
			if(arr[i].left > arr[i].right) swap(arr[i].left, arr[i].right);			
		}
		sort(arr, arr + n, cmp);
		ans = 1;
		flag = arr[0].right;
		for(int i = 1; i < n; ++i){
			if(flag < arr[i].left){
				++ans;
				flag = arr[i].right;
			}else if(flag < arr[i].right) flag = arr[i].right;
		}
		if(!n) printf("1\n"); 
		else printf("%d\n", ans + 1);
	}
	return 0;
}