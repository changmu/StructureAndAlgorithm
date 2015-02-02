////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-13 11:15:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1088
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
char buf[82], str[82], hr[81];
int id, len;

int main(){
	//freopen("data.out", "w", stdout);
	memset(hr, '-', 80);
	while(scanf("%s", str) == 1){
		if(str[0] == '<'){
			buf[id] = '\0';
			if(str[1] == 'b'){ puts(buf); }
			else{
				if(id){ puts(buf); }
				puts(hr);
			}
			id = 0;
			continue;
		}
		len = strlen(str);
		if(id == 0){
			memcpy(buf, str, len);
			id += len;
		}else{
			if(id + len >= 80){
				buf[id] = '\0'; puts(buf);
				memcpy(buf, str, len); id = len; 
			}else{ 
				buf[id++] = ' '; memcpy(buf + id, str, len); 
				id += len; 
			}
		}
	}
	if(id){ buf[id] = '\0'; printf(buf); }
	printf("\n");
	return 0;
}