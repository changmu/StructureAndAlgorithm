////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-06-01 20:27:16
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1172
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int ans, num, num1, num2;
bool arr[10002];
char numstr[5], buf[5];

bool cmp(int k){
	int i = 0, com = 0, com1 = 0, j;
	while(k){
		buf[i++] = k % 10 + '0';
		k /= 10;
	}
	buf[i] = '\0'; //µ¹Ðò
	for(i = 0; i < 4; ++i)
		if(numstr[i] == buf[i]) ++com1;
	
	for(i = 0; i < 4; ++i){		
		for(j = 0; j < 4; ++j)
			if(numstr[i] == buf[j]){
				++com;
				buf[j] = '9' + 1;
				break;
			}
	}
	if(com == num1 && com1 == num2) return true;
	return false;
}

void judge(){
	int i = 0;
	while(num){
		numstr[i++] = num % 10 + '0';
		num /= 10;
	}
	numstr[i] = '\0'; //µ¹Ðò	
	for(i = 1000; i < 10000; ++i){
		if(!arr[i] && !cmp(i)){
			arr[i] = 1;
			--ans;
		}
	}
}

int main(){
	int n;
	while(scanf("%d", &n), n){
		memset(arr, 0, sizeof(arr));
		ans = 9000;
		while(n--){
			scanf("%d%d%d", &num, &num1, &num2);
			judge();
		}
		//printf("ok...%d\n", ans);
		if(ans > 1){
			printf("Not sure\n");
			continue;
		}
		//printf("ok...%d\n", ans);
		for(int i = 1000; i < 10000; ++i)
			if(!arr[i]){
				printf("%d\n", i);
				break;
			}
	}
	return 0;
}