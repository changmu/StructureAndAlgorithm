////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-29 10:35:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1879
////Problem Title: 
////Run result: Accept
////Run time:578MS
////Run memory:380KB
//////////////////System Comment End//////////////////
//wutianqi
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct Road
{
    int c1, c2, cost, state;
}Road;
 
bool myCompare(const Road &a, const Road &b)
{
    if(a.cost < b.cost)
        return 1;
    return 0;
}
 
Road road[5051];
int city[101];
 
int Find(int n)
{
    if(city[n] == -1)
        return n;
    return city[n] = Find(city[n]);
}
 
bool Merge(int s1, int s2)
{
    int r1 = Find(s1);
    int r2 = Find(s2);
    if(r1 == r2)
        return 0;
    if(r1 < r2)
        city[r2] = r1;
    else
        city[r1] = r2;
    return 1;
}
 
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    while(scanf("%d", &n) && n)
    {
        int m = n*(n-1)/2;
        memset(city, -1, sizeof(city));
        int count = 0;
        for(int i=0; i<m; ++i)
        {
            scanf("%d %d %d %d", &road[i].c1, &road[i].c2, &road[i].cost, &road[i].state);
            if(road[i].state == 1)
            {
                count ++;
                Merge(road[i].c1, road[i].c2);
            }
        }
        sort(road, road+m, myCompare);
        int sum = 0;
        for(int i=0; i<m; ++i)
        {
            if(Merge(road[i].c1, road[i].c2) && road[i].state == 0)
            {
                count ++;
                sum += road[i].cost;
            }
            if(count == n-1)
                break;
        }
        printf("%d\n", sum);
    }
    return 0;
} 
