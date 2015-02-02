#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 100000 + 2

const char hashTable[] = {"22233344455566677778889999"};
char buf[31], str[31]; int id;
struct Node{
	char str[31];
	int times;
} arr[maxn];

int cmp(const void *a, const void *b){
	if( strcmp( ((Node *)a)->str, ((Node *)b)->str ) < 0 )
		return -1;
}

int hasExist(){
	int i;
	for(i = 0; i < id; ++i){
		if(strcmp(str, arr[i].str) == 0){
			++arr[i].times; return 1;
		}
	}
	return 0;
}

void proceed(){
	int i, j;
	for(i = j = 0; buf[i]; ++i){
		if(buf[i] == '-') continue;
		if(buf[i] >= '0' && buf[i] <= '9')
			str[j++] = buf[i];
		else str[j++] = hashTable[buf[i] - 'A'];	
	}
	str[j] = '\0';

	if(!hasExist()){
		strcpy(arr[id].str, str);
		arr[id++].times = 1;
	}
}

void print(char *ss){
	int i;
	for(i = 0; i < 7; ++i){
		putchar(ss[i]);
		if(i == 2) putchar('-');
	}
	putchar(' ');
}

int main(){
	int t, i, flag = 0; 
	scanf("%d", &t);
	while(t--){
		scanf("%s", buf);
		proceed();
	}

	qsort(arr, id, sizeof(Node), cmp);
	for(i = 0; i < id; ++i){		
		if(arr[i].times > 1){
			print(arr[i].str);
			printf("%d\n", arr[i].times);
			if(!flag) flag = 1;
		}		
	}
	if(!flag) puts("No duplicates.");
	//system("pause");
	return 0;
}
