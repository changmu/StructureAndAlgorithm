////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-31 18:14:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1276
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
bool arr[5002];
int n, ans;

int getNext(int i){
	while(arr[i] == 0 && i <= n) ++i;
	return i;
}

void cal2(){
	if(ans <= 3) return;
	for(int pos = 0; pos <= n; ){
		pos = getNext(pos + 1);
		if(pos > n) return;
		pos = getNext(pos + 1);
		if(pos > n) return;
		arr[pos] = 0;
		--ans;
	}
}

void cal3(){
	if(ans <= 3) return;
	for(int pos = 0; pos <= n; ){
		pos = getNext(pos + 1);
		if(pos > n) return;
		pos = getNext(pos + 1);
		if(pos > n) return;
		pos = getNext(pos + 1);
		if(pos > n) return;
		arr[pos] = 0;		
		--ans;
	}
}

int main(){
	int t, flag;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		ans = n;
		for(int i = 1; i <= n; ++i)
			arr[i] = 1;
		while(ans > 3){
			cal2();
			cal3();
		}
		flag = 0;
		for(int i = 0; ;){
			i = getNext(i + 1);
			if(i > n) break;
			if(flag == 0) flag = 1, printf("%d", i);
			else printf(" %d", i);
		}
		printf("\n");
	}
	return 0;
}