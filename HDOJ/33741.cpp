////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-18 17:21:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3374
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:5092KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define maxn 1000002

char str[maxn];
int next[maxn], len, cir, minPos, maxPos;

void getNext()
{
	int i = 0, j = -1;
	next[0] = -1;
	while(str[i]){
		if(j == -1 || str[i] == str[j]){
			++i; ++j;
			next[i] = j; //mode 1
		}else j = next[j];
	}
	len = i;
}

void findMinAndMaxPos()
{
	minPos = maxPos = 0;
	int k = 0, pos = 1, t;
	while(minPos < len && k < len && pos < len){
		t = str[(minPos + k) % len] - str[(pos + k) % len];
		if(t == 0){ ++k; continue; }
		else if(t < 0) pos += k + 1;
		else minPos += k + 1;
		k = 0;
		if(minPos == pos) ++pos;
	}
	if(minPos > pos) minPos = pos;
	++minPos;

	k = 0; pos = 1;
	while(maxPos < len && k < len && pos < len){
		t = str[(maxPos + k) % len] - str[(pos + k) % len];
		if(t == 0){ ++k; continue; }
		else if(t > 0) pos += k + 1;
		else maxPos += k + 1;
		k = 0;
		if(maxPos == pos) ++pos;
	}
	if(maxPos > pos) maxPos = pos;
	++maxPos;
}

int main()
{
	//freopen("stdin.txt", "r", stdin);
	while(scanf("%s", str) != EOF){
		getNext(); 
		findMinAndMaxPos(); cir = 1;
		if(len % (len - next[len]) == 0) 
			cir = len / (len - next[len]);
		printf("%d %d %d %d\n", minPos, cir, maxPos, cir);
	}
	return 0;
}