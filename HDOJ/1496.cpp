////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-12-09 10:37:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1496
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:8920KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int hash1[1000002], hash2[1000002];
int main()
{
    int a, b, c, d, i, j;    
    while(scanf("%d%d%d%d", &a, &b, &c, &d) != EOF)
    {
        if((a > 0 && b > 0 && c > 0 && d > 0) || (a < 0 && b < 0 && c < 0 && d < 0))
        {
            printf("0\n");
            continue;
      }
        int ans = 0, s;
        for(i = 0; i <= 1000001; i++)
            hash1[i] = hash2[i] = 0;
        for(i = 1; i <= 100; i++)
        {
            for(j = 1; j <= 100; j++)
            {
                s = a * i * i + b * j * j;
                if(s > 0)
                    hash1[s]++;
                else
                    hash2[-s]++;
            }
        }
        for(i = 1; i <= 100; i++)
        {        
            for(j = 1; j <= 100; j++)
            {
                s = c * i * i + d * j * j;
                if(s >= 0)
                 ans += hash2[s];
                else
                 ans += hash1[-s];
            }
        }
        printf("%d\n", 16 * ans);
    }
return 0;
}