////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-06-01 20:57:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2206
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:188KB
//////////////////System Comment End//////////////////
#include <stdio.h>
char str[102];
int ok;

int check(char ch){ //1代表数字，2代表‘.’，0代表非法
	if(ch >= '0' && ch <= '9') return 1;
	if(ch == '.') return 2;
	return 0;
}

int main(){
	int dot, dignum, a, dotsum;
	while(gets(str)){
		dotsum = a = dot = dignum = 0;
		for(int i = 0; str[i]; ++i){
			ok = check(str[i]);
			if(!ok) break;
			if(ok == 1){
				dot = 0;
				++dignum;
				a = a * 10 + str[i] - '0';
				if(dignum > 3 || a > 255){
					ok = 0; break;
				}
			}else{
				dignum = a = 0;
				++dot; ++dotsum;
				if(dot > 1 || dotsum > 3){
					ok = 0; break;
				}
			}
		}
		if(dot || dotsum != 3) ok = 0; //防止诸如199.12.123的情况出现
		printf(ok ? "YES\n" : "NO\n");
	}
	return 0;
}