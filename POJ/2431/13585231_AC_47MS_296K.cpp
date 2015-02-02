// notmine
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct data
{
    int dis,val;
    bool operator<(const data &next)const
    {
        return val<next.val;
    }
}po[10005];
bool comp(data a,data b)
{
    return a.dis>b.dis;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",&po[i].dis,&po[i].val);
        int d,p,cnt=0;
        scanf("%d%d",&d,&p);
        sort(po,po+n,comp);
        priority_queue<data> Q;
        int k=0;
        while(k<n&&d-p<=po[k].dis)
            Q.push(po[k++]);
        while(p<d&&!Q.empty())
        {
            cnt++;
            data a=Q.top();
            Q.pop();
            p+=a.val;
            while(k<n&&d-p<=po[k].dis)
                Q.push(po[k++]);
        }
        if(p<d)
            printf("-1\n");
        else
            printf("%d\n",cnt);
    }
    return 0;
}