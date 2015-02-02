////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-04-07 11:44:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4245
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

struct Node{
	char *a, *b;
} sam[5] = {{"A#", "Bb"}, {"C#", "Db"}, {"D#", "Eb"}, {"F#", "Gb"}, {"G#", "Ab"}};

int main(){
	char note[3], tona[6];
	int count = 1, ok;
	while(scanf("%s%s", note, tona) == 2){
		printf("Case %d: ", count++);
		if(strlen(note) == 1){
			printf("UNIQUE\n");
			continue;
		}
		
		for(int i = 0; i < 5; ++i){
			if(strcmp(note, sam[i].a) == 0) memcpy(note, sam[i].b, 2);			
			else if(strcmp(note, sam[i].b) == 0) memcpy(note, sam[i].a, 2);
		}		
		printf("%s %s\n", note, tona);
	}	
	return 0;
}