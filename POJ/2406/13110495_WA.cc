#include <stdio.h>
#define maxn 1000002

char str[maxn];
int next[maxn], len, cir;

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

int main()
{
	//freopen("stdin.txt", "r", stdin);
	while(scanf("%s", str) == 1){
		if(str[0] == '.' && !str[1]) break;
		getNext();
		cir = len - next[len];
		cir = len / cir;
		printf("%d\n", cir);
	}
	return 0;
}