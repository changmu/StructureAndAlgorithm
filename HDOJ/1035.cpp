////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-12 17:43:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1035
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
char grid[12][12];
int mark[12][12];
int row, column, entrance, steps;

bool check(int i, int j){
	if(i < 1 || j < 1 || i > row || j > column) return 0;
	return 1;
}

void move(int i, int j){
	if(!check(i, j)){
		printf("%d step(s) to exit\n", steps);
		return;
	}
	if(mark[i][j]){
		printf("%d step(s) before a loop of %d step(s)\n", 
				mark[i][j] - 1, steps - mark[i][j] + 1);
		return;
	}
	mark[i][j] = ++steps;
	switch(grid[i][j]){
		case 'N': move(i - 1, j); break;
		case 'S': move(i + 1, j); break;
		case 'W': move(i, j - 1); break;
		case 'E': move(i, j + 1);
	}
}

int main(){
	while(scanf("%d%d%d", &row, &column, &entrance), 
		row || column || entrance){
		for(int i = 1; i <= row; ++i)
			scanf("%s", grid[i] + 1);
		memset(mark, 0, sizeof(mark));
		steps = 0;
		move(1, entrance);
	}
	return 0;
}