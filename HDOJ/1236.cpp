////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-28 10:06:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1236
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>
using std::sort;

int prob[12];
struct Node{
    char id[30];
    int sco;
} stu[1002];

bool cmp(Node a, Node b){
    if(a.sco == b.sco) return strcmp(a.id, b.id) < 0;
    return a.sco > b.sco;
}

int main()
{
    int n, m, k, tmp, mm, tmp2, id, i;
    while(scanf("%d%d%d", &n, &m, &k) == 3){
        for(i = 1; i <= m; ++i) scanf("%d", &prob[i]);
        for(i = id = 0; i < n; ++i){
            scanf("%s%d", stu[id].id, &mm);
            tmp = 0;
            while(mm--){
                scanf("%d", &tmp2);
                tmp += prob[tmp2];
            }
            if(tmp >= k)
                stu[id++].sco = tmp;
            
        }
        sort(stu, stu + id, cmp);
        printf("%d\n", id);
        for(i = 0; i < id; ++i)
            printf("%s %d\n", stu[i].id, stu[i].sco);
    }
    return 0;
}
