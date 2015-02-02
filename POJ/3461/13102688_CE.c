#include <stdio.h>
#define maxn 10002
#define maxN 1000002

char str1[maxN], str2[maxn];
int next[maxn];

void getNext()
{
	int i = 0, j = -1;
	next[0] = -1;
	while(str2[i]){
		if(j == -1 || str2[i] == str2[j]){
			++i; ++j;
			if(str2[i] == str2[j]) next[i] = next[j];
			else next[i] = j;
		}else j = next[j];
	}
}

int KMP()
{	
	int ans = 0; 
	getNext();
	int i = 0, j = 0;	
	while(str1[i]){
		if(j == -1 || str1[i] == str2[j]){
			++i; ++j;
		}else j = next[j];
		
		if(j != -1 && !str2[j]){ //Attention!!!don't forget "j != -1"!
			++ans; j = next[j];
		}
	}
	return ans;
}

int main()
{
	//freopen("stdin.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%s%s", str2, str1);
		printf("%d\n", KMP());
	}
	return 0;
}