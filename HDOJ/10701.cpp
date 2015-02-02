////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-06 22:54:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1070
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<algorithm>
using namespace std;
struct data
{
	char br[110];
	int m;
	int v;
	double dj;
}nu[150];
bool cmp(data x,data y)
{
	if(x.dj==y.dj) return x.v>y.v;
	return x.dj<y.dj;
}

int main()
{
	int t,n,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s %d%d",nu[i].br,&nu[i].m,&nu[i].v);
			if(nu[i].v>1200) nu[i].v=1200;
			nu[i].dj=nu[i].m*1.0/nu[i].v;
		}
		sort(nu,nu+n,cmp);
		for(i=0;i<n;i++)
			if(nu[i].v>=200)
			{
				printf("%s\n",nu[i].br);
				break;
			}
	}
    return 0;
}
