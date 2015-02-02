////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-04-29 21:12:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1272
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:700KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int pre[100002];
bool flag[100002];

int find(int k){	
	if(pre[k] == 0) return k;
	int i = k, ii = k;
	while(pre[i] != 0){
		ii = pre[i]; //ii保存集合代表元素,千万不要写成ii = i;
		i = pre[i];
	}
	int j = k, t;
	while(pre[j] != 0){
		t = pre[j];
		pre[j] = ii;
		j = t;
	}
	return ii;
}

int main(){
	int a, b, ok = 1, x, y, mark;
	while(scanf("%d%d", &a, &b)){
		if(a == -1 && b == -1) break;
		
		if(a == 0 && b == 0){
			if(ok == 0) printf("No\n");
			else{
				mark = find(mark);
				for(int i = 1; i < 100001; ++i){
					if(flag[i] && mark != find(i)){
						ok = 0; break;
					}
				}
				printf(ok ? "Yes\n" : "No\n");
			}
			ok = 1;
			memset(pre, 0, sizeof(pre));
			memset(flag, 0, sizeof(flag));
			continue;
		}
		
		if(ok == 0) continue;
		
		mark = x = find(a);
		y = find(b);
		flag[a] = flag[b] = 1;
		if(x == y) ok = 0;
		else mark = pre[x] = y;
	}
	return 0;
}