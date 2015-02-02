////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-06-01 12:31:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1237
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
char str[202], buf[202], sign[202]; //buf´æ´¢Äæ²¨À¼Ê½
double stack[202], a;
int len, n, id, id2, id3, id4;

double perform(double x, double y, char ch){
	if(ch == '*') return x * y;
	if(ch == '/') return x / y;
	if(ch == '+') return x + y;
	return x - y;
}

void check(char ch){
	buf[id2++] = ' ';
	if(ch == '*' || ch == '/'){	
		while(id3 && (sign[id3-1] == '*' || sign[id3-1] == '/')) 
			buf[id2++] = sign[--id3];
		sign[id3++] = ch;
		return;
	}
	while(id3) buf[id2++] = sign[--id3];
	sign[id3++] = ch;
}

int main(){	
	while(gets(str)){
		len = strlen(str);
		if(len == 1 && str[0] == '0') break;
		id = id2 = id3 = id4 = 0;
		for(int i = 0; i < len; ++i){
			if(str[i] == ' ') continue;
			if(str[i] >= '0' && str[i] <= '9'){
				buf[id2++] = str[i];
			}else check(str[i]);
		}
		while(id3) buf[id2++] = sign[--id3];
		//for(int i = 0; i < id2; ++i) putchar(buf[i]);
	 	for(int i = 0; i < id2; ++i){
			if(buf[i] == ' ') continue;
			if(buf[i] >= '0' && buf[i] <= '9'){
				sscanf(buf + i, "%lf%n", &stack[id4++], &n);
				i += n - 1;
			}else stack[id4-2] = perform(stack[id4-2], stack[id4-1], buf[i]), --id4;			
		}
		
		printf("%.2lf\n", stack[0]);
	}
	return 0;
}