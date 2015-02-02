////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-05-03 17:45:16
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3374
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:5100KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 1000002
char str[maxn];
int len, next[maxn];

void getNext(){
	int i = 0, j = -1;
	next[0] = -1;
	while(i < len){
		if(j == -1 || str[i] == str[j]){
			++i; ++j;
			next[i] = j;
		}else j = next[j];
	}
}

int minR(){
	int i = 0, j = 1, k = 0, t;
	while(i < len && j < len && k < len){
		t = str[i+k >= len ? i+k-len : i+k] - 
			str[j+k >= len ? j+k-len : j+k];
		if(t == 0) ++k;
		else{
			if(t > 0) i += k + 1;
			else j += k + 1;
			k = 0;
			if(i == j) ++j;
		}
	}
	return i < j ? i : j;
}

int maxR(){
	int i = 0, j = 1, k = 0, t;
	while(i < len && j < len && k < len){
		t = str[i+k >= len ? i+k-len : i+k] - 
			str[j+k >= len ? j+k-len : j+k];
		if(t == 0) ++k;
		else{
			if(t > 0) j += k + 1;
			else i += k + 1;
			k = 0;
			if(i == j) ++j;
		}
	}
	return i < j ? i : j;
}

int main(){
	int minlen, num;
	while(scanf("%s", str) == 1){
		len = strlen(str);
		getNext();
		if(len % (len - next[len]) == 0) //最小循环节点
			minlen = len - next[len];
		else minlen = len;
		num = len / minlen;
		printf("%d %d %d %d\n", minR()+1, num, maxR()+1, num);
	}
	return 0;
}