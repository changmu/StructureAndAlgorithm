////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-26 14:31:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1171
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:1296KB
//////////////////System Comment End//////////////////
// Author: Tanky Woo
// HDOJ 1171
 
 
#include <iostream>
using namespace std;
 
int c1[250010], c2[250010];
int value[55];
int amount[55];
int main()
{
    int nNum;
    while(scanf("%d", &nNum) && nNum>0)
    {
        memset(value, 0, sizeof(value));
        memset(amount, 0, sizeof(amount));
 
        int sum = 0;
        for(int i=1; i<=nNum; ++i)
        {
            scanf("%d %d", &value[i], &amount[i]);
            sum += value[i]*amount[i];
        }
        memset(c1, 0, sum*sizeof(c1[0]));
        memset(c2, 0, sum*sizeof(c2[0]));
        for(int i=0; i<=value[1]*amount[1]; i+=value[1])
            c1[i] = 1;
        int len = value[1]*amount[1];
        for(int i=2; i<=nNum; ++i)
        {
            for(int j=0; j<=len; ++j)
                for(int k=0; k<=value[i]*amount[i]; k+=value[i])
                {
                    c2[k+j] += c1[j];
                }
            len += value[i]*amount[i];
            for(int j=0; j<=len; ++j)
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        for(int i= sum/2; i>=0; --i)
            if(c1[i] != 0)
            {
                printf("%d %d\n", sum-i, i);
                break;
            }
    }
    return 0;
}