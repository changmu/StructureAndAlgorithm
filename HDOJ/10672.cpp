////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-19 22:17:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1067
////Problem Title: 
////Run result: Accept
////Run time:609MS
////Run memory:2484KB
//////////////////System Comment End//////////////////
//notmine
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int MOD=1000007;
struct node
{
    int map[10][10];
    int d;
};
bool vis[MOD];
long long gethash(node &t)
{
    int tmp[70],k=0;
    memset(tmp,0,sizeof(tmp));
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<8;j++)
        {
            tmp[k++]=t.map[i][j]/10;
            tmp[k++]=t.map[i][j]%10;
        }
    }
    long long hash=0;
    for(i=0;i<k;i++)
    {
        hash=hash*7+tmp[i];
    }
    hash=(hash&0x7fffffff)%MOD;
    //hash=hash%MOD;
    return hash;

}
int aim[4][8]=
{
    {11,12,13,14,15,16,17,0},
    {21,22,23,24,25,26,27,0},
    {31,32,33,34,35,36,37,0},
    {41,42,43,44,45,46,47,0}
};
int getaim(node &t)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<8;j++)
        {
            if(t.map[i][j]!=aim[i][j])
                return 0;
        }
    }
    return 1;
}
int change(node &t,int num)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<8;j++)
        {
            if(t.map[i][j]==num+1)
            {
                t.map[i][j]=0;
                return 1;
            }
        }
    }
    return 0;
}
int bfs(node t)
{
    t.map[0][0]=11;
    t.map[1][0]=21;
    t.map[2][0]=31;
    t.map[3][0]=41;
    t.d=0;
    memset(vis,0,sizeof(vis));
    int hash=gethash(t);
    vis[hash]=1;
    queue<node> q;
    q.push(t);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(getaim(t))
            return t.d;
        int i,j;
        for(i=0;i<4;i++)
        {
            for(j=1;j<8;j++)
            {
                if(t.map[i][j]==0&&t.map[i][j-1]%10!=7&&t.map[i][j-1]!=0)
                {
                    node cur=t;
                    change(cur,cur.map[i][j-1]);
                    cur.map[i][j]=cur.map[i][j-1]+1;
                    cur.d=cur.d+1;
                    hash=gethash(cur);
                    if(!vis[hash])
                    {
                        vis[hash]=1;
                        q.push(cur);
                    }
                }
            }
        }
    }
    return -1;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int i,j;
        node t;
        memset(t.map,0,sizeof(t.map));
        for(i=0;i<4;i++)
        {
            for(j=1;j<8;j++)
            {
                scanf("%d",&t.map[i][j]);
                if(t.map[i][j]%10==1)
                    t.map[i][j]=0;
            }
        }
        int res=bfs(t);
        printf("%d\n",res);

    }
    return 0;
}
