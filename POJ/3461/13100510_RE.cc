#include <stdio.h>
#include <string.h>
#define maxn 10002
#define maxN 1000002

char str1[maxN], str2[maxn];
int next[maxn], len1, len2, ans;

void getNext()
{
	int i = 0, j = -1;
	next[0] = -1;
	while(i < len1){
		if(j == -1 || str2[i] == str2[j]){
			++i; ++j;
			if(str2[i] == str2[j]) next[i] = next[j];
			else next[i] = j;
		}else j = next[j];
	}
}

void KMP()
{
	getNext();
	int i = 0, j = 0;
	while(i < len1){
		if(j == -1 || str1[i] == str2[j]){
			++i; ++j;
		}else j = next[j];
		
		if(j == len2){
			++ans; i -= len2 - 1; j = 0;
		}
	}
}

int main()
{
	//freopen("stdin.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%s%s", str2, str1);
		len1 = strlen(str1);
		len2 = strlen(str2);
		ans = 0; KMP();
		printf("%d\n", ans);
	}
	return 0;
}