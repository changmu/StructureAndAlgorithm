////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-08 14:37:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1862
////Problem Title: 
////Run result: Accept
////Run time:500MS
////Run memory:2188KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>

#define maxn 100010

struct Node {
    int id, score;
    char name[10];
} stu[maxn];

bool cmp1(const Node &a, const Node &b) {
    return a.id < b.id;
}

bool cmp2(const Node &a, const Node &b) {
    int c = strcmp(a.name, b.name);
    if(!c)
        return a.id < b.id;
    return c < 0;
}

bool cmp3(const Node &a, const Node &b) {
    if(a.score == b.score)
        return a.id < b.id;
    return a.score < b.score;
}

int main() {
    int N, C, i, cas = 1;
    while(scanf("%d%d", &N, &C) == 2) {
        if(!N) break;
        for(i = 0; i < N; ++i)
            scanf("%d%s%d", &stu[i].id, stu[i].name, &stu[i].score);
        if(C == 1) std::sort(stu, stu + N, cmp1);
        else if(C == 2) std::sort(stu, stu + N, cmp2);
        else std::sort(stu, stu + N, cmp3);
        printf("Case %d:\n", cas++);
        for(i = 0; i < N; ++i)
            printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
    }
}