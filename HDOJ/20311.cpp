////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-11-25 15:40:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2031
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:280KB
//////////////////System Comment End//////////////////
// hdu 进制转换
#include <stdio.h>

void f(int n, int r) {
  if(0 == n) return;
  int a = n % r;
  f(n / r, r);
  if(a > 9) putchar('A' + a - 10);
  else putchar('0' + a);
}

int main() {
  int n, r, i;
  while(scanf("%d%d", &n, &r) == 2) {
    if(n < 0) {
      n = -n; putchar('-');
    }
    if(n == 0) putchar('0');
    else f(n, r);
    printf("\n");
  }
}
