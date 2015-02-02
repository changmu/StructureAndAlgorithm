////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-03-30 13:21:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1036
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main(){
	int sectionNumber, t, ok;
	double relayDistance;
	char buf[20];
	int teamNumber, teamSeconds, h, m, s;
	scanf("%d%lf", &sectionNumber, &relayDistance);	
	while(scanf("%d", &teamNumber) != EOF){
		t = sectionNumber;
		teamSeconds = 0;
		ok = 1;
		while(t--){
			if(scanf("%d:%d:%d", &h, &m, &s) == 3){
				if(ok) teamSeconds += h * 3600 + m * 60 + s;
			}else{
				ok = 0;
				scanf("%s", buf); //¶ÁÈ¡»º´æ
			}
		}
		printf("%3d: ", teamNumber);
		if(!ok) printf("-\n");
		else{
			int temp = int(teamSeconds / relayDistance + 0.5);
			printf("%d:%02d min/km\n", temp / 60, temp % 60);
		}
	}
	return 0;
}