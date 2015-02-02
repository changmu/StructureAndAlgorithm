////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-08 14:41:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1302
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

struct Node {
    double U, F, H;
} a;

int main() {
    // freopen("stdin.txt", "r", stdin);
    double H, U, D, F;
    int cnt;
    while(scanf("%lf%lf%lf%lf", &H, &U, &D, &F), H) {
        a.H = 0.0; a.U = U; a.F = F * U / 100.0;
        cnt = 0;
        while(true) {
            ++cnt;
            if(a.U < 0) {
                a.U = U;
                a.H -= D;
                if(a.H < 0.0) break;
                continue;
            }
            a.H += a.U;
            if(a.H < 0.0 || a.H > H) break;
            a.U -= a.F;
            a.H -= D;
            if(a.H < 0.0 || a.H > H) break;
        }
        if(a.H > H) printf("success on day %d\n", cnt);
        else printf("failure on day %d\n", cnt);
    }
    return 0;
}