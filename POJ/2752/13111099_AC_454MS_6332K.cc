#include <stdio.h>
#define maxn 400002

char str[maxn];
int next[maxn], len;

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

void getVal(int n)
{
	if(next[n] == 0) return;
	getVal(next[n]);
	printf("%d ", next[n]);
}

int main()
{
	//freopen("stdin.txt", "r", stdin);
	while(scanf("%s", str) == 1){
		getNext();
		getVal(len);
		printf("%d\n", len);
	}
	return 0;
}