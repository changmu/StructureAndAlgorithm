////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-11 09:32:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2255
////Problem Title: 
////Run result: Accept
////Run time:375MS
////Run memory:600KB
//////////////////System Comment End//////////////////
// not mine
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 305;
const int INF = (1<<30)-1;
int g[maxn][maxn];
int lx[maxn],ly[maxn];
int match[maxn];
bool visx[maxn],visy[maxn];
int slack[maxn];
int n;
bool dfs(int cur){
     visx[cur] = true;
     for(int y=1;y<=n;y++){
         if(visy[y])   continue;
         int t=lx[cur]+ly[y]-g[cur][y];
         if(t==0){
            visy[y] = true;
            if(match[y]==-1||dfs(match[y])){
                match[y] = cur;
                return true;
            }
         }
         else if(slack[y]>t){
                 slack[y]=t;
         }
     }
     return false;
}
int KM(){
    memset(match,-1,sizeof(match));
    memset(ly,0,sizeof(ly));
    for(int i=1 ;i<=n;i++){
         lx[i]=-INF;
       for(int j=1;j<=n;j++)
           if(g[i][j]>lx[i])   lx[i]=g[i][j];
   }
   for(int x=1;x<=n;x++){
        for(int i=1;i<=n;i++)  slack[i]=INF;
        while(true){
            memset(visx,false,sizeof(visx));
            memset(visy,false,sizeof(visy));
            if(dfs(x))  break;
            int d=INF;
            for(int i=1;i<=n;i++){
               if(!visy[i]&&d>slack[i])     d=slack[i];
            }
            for(int i=1;i<=n;i++){
               if(visx[i])                  lx[i]-=d;
            }
            for(int i=1;i<=n;i++){
               if(visy[i])                 ly[i]+=d;
               else                        slack[i]-=d;
            }
        }
   }
    int result = 0;
    for(int i = 1; i <=n; i++)
    if(match[i]>-1)
        result += g[match[i]][i];
    return result;
}
int main(){
    // freopen("stdin.txt", "r", stdin);
    while(scanf("%d",&n)!=EOF){
         for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)  {
                    scanf("%d",&g[i][j]);
            }
            printf("%d\n",KM());
    }
    return 0;
}
