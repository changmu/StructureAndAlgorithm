////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-16 12:49:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1251
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:43768KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	struct Node *nextAlph[26];
	int num;
} root;

void insert(char *str)
{
	Node *p = &root;	
	int id;
	while(*str){
		id = *str - 'a';
		if(p->nextAlph[id] == NULL){
			p->nextAlph[id] = (Node *)malloc(sizeof(Node));
			p = p->nextAlph[id];
			memset(p->nextAlph, 0, sizeof(p->nextAlph));
			p->num = 0;
		}else  p = p->nextAlph[id];	
		
		++p->num; ++str;
	}	
}

int FIND(char *str)
{
	Node *p = &root;
	int id;
	while(*str){
		id = *str - 'a';
		if(p->nextAlph[id] == NULL) return 0;
		p = p->nextAlph[id];
		++str;
	}
	return p->num;
}

int main()
{
	//freopen("stdin.txt", "r", stdin);
	char str[12];
	while(gets(str), *str) insert(str);	
	while(gets(str)) printf("%d\n", FIND(str));	
	return 0;
}