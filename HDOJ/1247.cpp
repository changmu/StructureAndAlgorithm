////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-16 20:59:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1247
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:6368KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	struct Node *next[26];
	int wordCover;
} root;
char suffix[50], prefix[50], strArr[50000][50];

void cleanStruct(Node *p)
{
	memset(p->next, 0, sizeof(p->next));
	p->wordCover = 0;
}

void insert(char *str)
{
	int id;
	Node *p = &root;
	while(*str)
	{
		id = *str - 'a';
		if(p->next[id] == NULL){
			p->next[id] = (Node *)malloc(sizeof(Node));
			cleanStruct(p->next[id]);
		}
		p = p->next[id];
		++str;
	}
	++p->wordCover;
}

int isExist(char *str)
{
	Node *p = &root;
	int id;
	while(*str){
		id = *str - 'a';
		if(p->next[id] == NULL) return 0;
		p = p->next[id];
		++str;
	}
	return p->wordCover;
}

int main()
{
	//freopen("stdin.txt", "r", stdin);
	int id = 0, i, j, len;
	while(gets(strArr[id])) insert(strArr[id++]);
	for(i = 0; i < id; ++i){
		len = strlen(strArr[i]);
		for(j = 1; j < len; ++j){
			strcpy(prefix, strArr[i]);
			prefix[j] = '\0';
			strcpy(suffix, strArr[i] + j);
			if(isExist(prefix) && isExist(suffix)){
				puts(strArr[i]); break;
			}
		}
	}
	return 0;
}