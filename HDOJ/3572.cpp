////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-12 15:33:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3572
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:3072KB
//////////////////System Comment End//////////////////
// not mine
#include<iostream>
#include<memory.h>
using namespace std;
const int inf=1<<30;
struct edge
{
    int x;
    int y;
    int nxt;
    int c;
} bf[750000];
int ne,head[25000],cur[25000],ps[25000],dep[25000];
void addedge(int x,int y,int c)
{
    bf[ne].x=x;
    bf[ne].y=y;
    bf[ne].c=c;
    bf[ne].nxt=head[x];
    head[x]=ne++;
    bf[ne].x=y;
    bf[ne].y=x;
    bf[ne].c=0;
    bf[ne].nxt=head[y];
    head[y]=ne++;
}
int flow(int n,int s,int t)
{
    int tr,res=0;
    int i,j,k,f,r,top;
    while(1)
    {
        memset(dep,-1,n*sizeof(int));
        for(f=dep[ps[0]=s]=0,r=1; f!=r;)
            for(i=ps[f++],j=head[i]; j; j=bf[j].nxt)
            {
                if(bf[j].c && -1==dep[k=bf[j].y])
                {
                    dep[k]=dep[i]+1;
                    ps[r++]=k;
                    if(k==t)
                    {
                        f=r;
                        break;
                    }
                }
            }
        if(-1==dep[t])
            break;

        memcpy(cur,head,n*sizeof(int));
        for(i=s,top=0;;)
        {
            if(i==t)
            {
                for(k=0,tr=inf; k<top; ++k)
                    if(bf[ps[k]].c<tr)
                        tr=bf[ps[f=k]].c;
                for(k=0; k<top; ++k)
                {
                    bf[ps[k]].c-=tr;
                    bf[ps[k]^1].c+=tr;
                }
                res+=tr;
                i=bf[ps[top=f]].x;
            }
            for (j=cur[i]; cur[i]; j = cur[i] = bf[cur[i]].nxt)
                if (bf[j].c && dep[i]+1 == dep[bf[j].y])
                    break;
            if (cur[i])
            {
                ps[top++] = cur[i];
                i = bf[cur[i]].y;
            }
            else
            {
                if (0 == top)
                    break;
                dep[i] = -1;
                i = bf[ps[--top]].x;
            }
        }
    }
    return res;
}
int main()
{
    int i,j,p,s,e,m,N,t,k,sum,Max;
    cin>>t;
    k=t;
    while(t--)
    {
        cin>>N>>m;
        sum=0;
        Max=-1;
        ne=2;
        memset(head,0,24999*sizeof(int));
        for(i=1; i<=N; i++)
        {
            cin>>p>>s>>e;
            sum+=p;
            if(e>Max)
                Max=e;
            addedge(1,i+1,p);
            for(j=s; j<=e; j++)
                addedge(i+1,N+j+1,1);
        }
        for(j=N+1; j<=N+Max; j++)
            addedge(j+1,Max+N+2,m);
        if(flow(Max+N+3,1,Max+N+2)==sum)
            cout<<"Case "<<k-t<<": Yes"<<endl;
        else cout<<"Case "<<k-t<<": No"<<endl;
            cout<<endl;
    }
    return 0;
}
 
