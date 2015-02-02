////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-04-29 16:48:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1198
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
//并查集
#include <stdio.h>
struct Node{
	bool up, down, left, right;
}node[] = 
{1, 0, 1, 0, //A
 1, 0, 0, 1, //B 
 0, 1, 1, 0, //C
 0, 1, 0, 1, //D
 1, 1, 0, 0, //E
 0, 0, 1, 1, //F
 1, 0, 1, 1, //G
 1, 1, 1, 0, //H
 0, 1, 1, 1, //I
 1, 1, 0, 1, //J
 1, 1, 1, 1};//K
 
char a[52][52];
 
struct NODE{
	int r, c;
}pre[52][52];

NODE find(NODE k){ //查找与压缩
	NODE i = k;
	while(!(i.r == pre[i.r][i.c].r && i.c == pre[i.r][i.c].c))
		i = pre[i.r][i.c];
	NODE j = k, t;
	while(j.r != i.r || j.c != i.c){
		t = pre[j.r][j.c];
		pre[j.r][j.c] = i;
		j = t;
	}
	return i;
}
 
int main(){
	int m, n, sum;
	NODE x, y, z;
	char ch;
	while(scanf("%d%d", &m, &n)){
		if(m < 0 || n < 0) break;
		
		sum = n * m;
		
		for(int i = 1; i <= m; ++i)
			for(int j = 1; j <= n; ++j){
				pre[i][j].r = i;
				pre[i][j].c = j;
			}
		
		getchar();
		for(int i = 1; i <= m; ++i)
			gets(a[i] + 1);
		
		for(int i = 1; i <= m; ++i){
			for(int j = 1; j <= n; ++j){
				x = find(pre[i][j]);
				y = find(pre[i][j+1]);
				z = find(pre[i+1][j]);
			
				if(j < n && node[a[i][j]-'A'].right && node[a[i][j+1]-'A'].left){
					if(x.r != y.r || x.c != y.c){ //如果两点联通但又不在一个集合
						--sum;
						pre[y.r][y.c] = x; //联通
					}
				}
				
				if(i < m && node[a[i][j]-'A'].down && node[a[i+1][j]-'A'].up){
					if(x.r != z.r || x.c != z.c){ 
						--sum;
						pre[z.r][z.c] = x; 
					}
				}				
			}
		}
		
		printf("%d\n", sum);
	}
	return 0;
}