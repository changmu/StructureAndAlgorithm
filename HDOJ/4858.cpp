////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-20 23:40:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4858
////Problem Title: 
////Run result: Accept
////Run time:796MS
////Run memory:6032KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <vector>
#include <string.h>
#define maxn 100002
using namespace std;

vector<int> vec[maxn];
vector<int>::iterator it;
int val[maxn];

int getVal(int k)
{
    int sum = 0;
    for(it = vec[k].begin(); it != vec[k].end(); ++it)
        sum += val[*it];
    return sum;
}

int main()
{
    int t, n, m, i, a, b, q, com;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        memset(vec, 0, sizeof(vec));
        memset(val, 0, sizeof(val));
        for(i = 1; i <= m; ++i){
            scanf("%d%d", &a, &b);
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        scanf("%d", &q);
        while(q--){
            scanf("%d%d", &com, &a);
            if(com == 1) printf("%d\n", getVal(a));
            else{
                scanf("%d", &b);
                val[a] += b;
            }
        }
    }
    return 0;
}