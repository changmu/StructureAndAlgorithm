#include <stdio.h>
#include <string.h>
#define maxn 28

char str1[maxn], str2[maxn];

void traverse(int l1, int r1, int l2, int r2)
{
	if(l1 > r1) return;
	int rt;
	rt = strchr(str2, str1[l1]) - str2;
	traverse(l1 + 1, rt - l2 + l1, l2, rt - 1);
	traverse(rt-l2+l1+1, r1, rt+1, r2);
	putchar(str2[rt]);
}

int main()
{
	int len;
	while(scanf("%s%s", str1, str2) == 2){
		
		len = strlen(str1);
		traverse(0, len - 1, 0, len - 1);
		printf("\n");
	}
	return 0;
}