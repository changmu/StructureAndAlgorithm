////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-31 12:12:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1230
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int sam[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,
			59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
int arr[3][26], id, id2, id3, len;
char s1[200], s2[200], *p;
int main(){
	while(scanf("%s%s", s1, s2) == 2 && s1[0] != '0'){
		memset(arr, 0, sizeof(arr));
		p = strtok(s1, ",");
		id2 = id = 0;
		while(p != NULL){
			sscanf(p, "%d", &arr[0][++id]);
			p = strtok(NULL, ",");
		}
		p = strtok(s2, ",");
		while(p != NULL){
			sscanf(p, "%d", &arr[1][++id2]);
			p = strtok(NULL, ",");
		}
		len = id3 = id > id2 ? id : id2;
		while(id && id2)
			arr[2][id3--] = arr[0][id--] + arr[1][id2--];
		while(id) arr[2][id3--] = arr[0][id--];
		while(id2) arr[2][id3--] = arr[1][id2--];
			
		for(int i = len, j = 1; i; --i, ++j){
			if(arr[2][i] >= sam[j]){
				++arr[2][i-1];
				arr[2][i] -= sam[j];
			}
		}
		int i;
		if(arr[2][0] == 0){printf("%d", arr[2][1]); i = 2;}
		else {printf("%d", arr[2][0]); i = 1;}
		while(i <= len) printf(",%d", arr[2][i++]);
		printf("\n");
	}
	return 0;
}