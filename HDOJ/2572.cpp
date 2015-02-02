////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-02-16 11:35:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2572
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
char buf[101], buff[101], a[101], b[11], c[11];

int strco(int i, int j, char str[]){
	int k, kk;
	for(k = i, kk = 0; k <= j; ++k, ++kk)
		str[kk] = a[k];
	str[kk] = '\0';
	return j - i + 1;
}

struct node{
	int min, ok;
};

bool cmp(char s[], char s1[]){
	int i;
	for(i = 0; s1[i] != '\0'; ++i)
		if(s[i] != s1[i]) return false;
	return true;
}

int main(){
	int t, lena, lenb, lenc, i, ii, j, jj, temp;
	node min;
	scanf("%d", &t);
	while(t-- && scanf("%s%s%s", a, b, c)){
		lena = strlen(a);
		lenb = strlen(b);
		lenc = strlen(c);
		min.ok = 0;
		for(i = 0; i != lena; ++i){
			if(cmp(a + i, b)){
				ii = i + lenb - 1; //b串的末尾下标
				for(j = 0; j != lena; ++j)
					if(cmp(a + j, c)){
						jj = j + lenc - 1; //c串的末尾下标
						if(!min.ok){							
							min.min = strco((i < j ? i : j), (ii > jj ? ii : jj), buf);
							min.ok = 1;
							continue;
						}
						temp = (ii > jj ? ii : jj) - (i < j ? i : j) + 1;
						if(temp < min.min)
							min.min = strco(i < j ? i : j, ii > jj ? ii : jj, buf);						
						else if(temp == min.min) {
							strco(i < j ? i : j, ii > jj ? ii : jj, buff);
							if(strcmp(buf, buff) > 0)
								strcpy(buf, buff);
						}
					}
			}					
		}
		if(min.ok)
			puts(buf);
		else puts("No");
	}
	return 0;
}