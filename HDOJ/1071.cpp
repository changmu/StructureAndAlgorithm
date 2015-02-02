////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-23 11:19:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1071
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int t;
    double x1, y1, x2, y2, x3, y3, a, b, c, k, d, p, q, r, ans;
    scanf("%d", &t);
    while(t--){
        scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
        p = y1 / ((x1 - x2) * (x1 - x3));
        q = y2 / ((x2 - x1) * (x2 - x3));
        r = y3 / ((x3 - x1) * (x3 - x2));
        a = p + q + r;
        b = -p*(x2 + x3) - q*(x1 + x3) - r * (x1 + x2);
        c = p * x2 * x3 + q * x1 * x3 + r * x1 * x2;
        k = (y3 - y2) / (x3 - x2);
        d = y2 - k * x2;
        ans = (1.0/3*a*x3*x3*x3 + 1.0/2*(b-k)*x3*x3 + (c-d)*x3) - 
            (1.0/3*a*x2*x2*x2 + 1.0/2*(b-k)*x2*x2 + (c-d)*x2);
        if(ans < 0) ans = -ans;
        printf("%.2lf\n", ans);
    }
    return 0;
}
