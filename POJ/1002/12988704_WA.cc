#include <stdio.h>
#include <stdlib.h>
#define maxn 100000 + 2

const char hashTable[] = {"22233344455566677778889999"};
char buf[31]; int id;
struct Node{
	int val, num;
};

void proceed(Node arr[]){
	int sum = 0, flag = 0;
	for(int i = 0; buf[i]; ++i){
		if(buf[i] == '-') continue;
		if(buf[i] >= '0' && buf[i] <= '9')
			sum = sum * 10 + buf[i] - '0';
		else sum = sum * 10 + hashTable[buf[i] - 'A'] - '0';
	}
	for(int i = 0; i < id; ++i){
		if(arr[i].val == sum){
			++arr[i].num; flag = 1;
			break;
		}
	}
	if(!flag){
		arr[id].val = sum;
		arr[id++].num = 1;
	}
}

int cmp(const void *a, const void *b){
	return ((Node *)a)->val - ((Node *)b)->val;
}

int main(){
	int t; scanf("%d", &t);
	Node arr[t];
	while(t--){
		scanf("%s", buf);
		proceed(arr);
	}
	
	qsort(arr, id, sizeof(Node), cmp);
	int flag = 0;
	
	for(int i = 0; i < id; ++i){
		if(arr[i].num > 1){
			printf("%03d-%04d %d\n", arr[i].val / 10000, 
				arr[i].val % 10000, arr[i].num);
			if(!flag) flag = 1;
		}
	}
	if(!flag) printf("No duplicates.\n");
	return 0;
}
