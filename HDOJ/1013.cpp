////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-03-10 22:34:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1013
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
char str[1000];

int f(int n){
    int s = 0;
    while(n){
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main(){
    int n, s;
    while(scanf("%s", str), str[0] - '0'){
        s = 0;
		for(int i = 0; str[i] != '\0'; ++i)
			s += str[i] - '0';
        while(s > 9)
            s = f(s);
        printf("%d\n", s);
    }
    return 0;
}