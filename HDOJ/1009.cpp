////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-29 17:06:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1009
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:236KB
//////////////////System Comment End//////////////////
/*Input
The input consists of multiple test cases. Each test case begins with a line containing two non-negative integers M and N. Then N lines follow, each contains two non-negative integers J[i] and F[i] respectively. The last test case is followed by two -1's. All integers are not greater than 1000.

 

Output
For each test case, print in a single line a real number accurate up to 3 decimal places, which is the maximum amount of JavaBeans that FatMouse can obtain.

 

Sample Input
5 3
7 2
4 3
5 2
20 3
25 18
24 15
15 10
-1 -1
 

Sample Output
13.333
31.500
*/
#include <stdio.h>
#include <algorithm>
#define maxn 1002
using std::sort;

struct Node{
	int v, c;
	double val;
} arr[maxn];

bool cmp(Node a, Node b)
{
	return a.val > b.val;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int m, n, i, a, b;
	double ans;
	while(scanf("%d%d", &m, &n), m >= 0 && n >= 0){
		for(i = 0; i < n; ++i){
			scanf("%d%d", &a, &b);
			arr[i].val = a * 1.0 / b;
			arr[i].v = a; arr[i].c = b;
		}
		ans = 0;
		sort(arr, arr + n, cmp);
		for(i = 0; i < n; ++i){
			if(m >= arr[i].c){
				m -= arr[i].c; ans += arr[i].v;
			}else{
				ans += m * arr[i].val; break;
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}
