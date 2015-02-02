////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-23 20:40:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1256
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

void printHead(char ch, int bian, int xia)
{
	int i;
	for(i = 0; i < bian; ++i) putchar(' ');
	for(i = 0; i < xia; ++i) putchar(ch);
	//for(i = 0; i < bian; ++i) putchar(' ');
	putchar('\n');
}

void printBody(char ch, int bian, int xia)
{
	int i;
	for(i = 0; i < bian; ++i) putchar(ch);
	for(i = 0; i < xia; ++i) putchar(' ');
	for(i = 0; i < bian; ++i) putchar(ch);
	putchar('\n');
}

int main()
{	
	int t, n, bian, xia, shang, i;
	char str[2];
	scanf("%d", &t);
	while(t--){
		scanf("%s%d", str, &n);
		bian = n / 6 + 1;
		shang = (n - 3) / 2;
		xia = n - 3 - shang;
		printHead(str[0], bian, xia);
		for(i = 0; i < shang; ++i) printBody(str[0], bian, xia);
		printHead(str[0], bian, xia);	
		for(i = 0; i < xia; ++i) printBody(str[0], bian, xia);
		printHead(str[0], bian, xia);
		if(t) putchar('\n');
	}
	return 0;
}
