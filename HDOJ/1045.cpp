////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-04 17:11:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1045
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

char map[5][5];
int n, power[5][5], maxSum, sum;

void getFire(int x, int y)
{
	int i;
	for(i = 0; x - i >= 0 && map[x-i][y] == '.'; ++i)
		++power[x-i][y];
	for(i = 0; x + i < n && map[x+i][y] == '.'; ++i)
		++power[x+i][y];
	for(i = 0; y - i >= 0 && map[x][y-i] == '.'; ++i)
		++power[x][y-i];
	for(i = 0; y + i < n && map[x][y+i] == '.'; ++i)
		++power[x][y+i];
}

void cancelFire(int x, int y)
{
	int i;
	for(i = 0; x - i >= 0 && map[x-i][y] == '.'; ++i)
		--power[x-i][y];
	for(i = 0; x + i < n && map[x+i][y] == '.'; ++i)
		--power[x+i][y];
	for(i = 0; y - i >= 0 && map[x][y-i] == '.'; ++i)
		--power[x][y-i];
	for(i = 0; y + i < n && map[x][y+i] == '.'; ++i)
		--power[x][y+i];
}

bool check(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < n && map[x][y] != 'X';
}

void DFS(int x, int y)
{
	int i, j;
	for(i = x, j = y; i < n; ++i, j = 0){
		for( ; j < n; ++j){
			if(check(i, j) && !power[i][j]){
				++sum;
				getFire(i, j);
				DFS(i, j + 1);
				if(sum > maxSum) maxSum = sum;
				--sum;
				cancelFire(i, j);
			}
		}
	}
}

int main()
{
	//freopen("stdin.txt", "r", stdin);
	int i;
	while(scanf("%d", &n), n){
		for(i = 0; i < n; ++i)
			scanf("%s", map[i]);
		memset(power, 0, sizeof(power));
		maxSum = sum = 0;
		DFS(0, 0);
		printf("%d\n", maxSum);
	}
	return 0;
}