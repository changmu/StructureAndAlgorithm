////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-25 15:42:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2091
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:276KB
//////////////////System Comment End//////////////////
// HDU2091
#include <stdio.h>

void putK(int k) {
  while(k--) putchar(' ');
}

int main() {
  int n, i, j, cas = 0;
  char ch[2];
  while(scanf("%s%d", ch, &n) == 2) {
    if(cas++) putchar('\n');
    for(i = 1; i < n; ++i) {
      for(j = 1; j <= n + i - 1; ++j)
        if(j == n - i + 1 || j == n + i - 1)
          putchar(*ch);
        else putchar(' ');
      putchar('\n');
    }
    for(i = 0; i < 2 * n - 1; ++i)
      putchar(*ch);
    putchar('\n');
  }
  return 0;
}