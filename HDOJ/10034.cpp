////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-25 15:41:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1003
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:276KB
//////////////////System Comment End//////////////////
// HDU maxsum
#include <stdio.h>

int main() {
  // freopen("stdin.txt", "r", stdin);
  int T, N, i, j, maxSum, sum, maxL, maxR, L, R, v;
  scanf("%d", &T);
  for(int cas = 1; cas <= T; ++cas) {
    printf("Case %d:\n", cas);
    scanf("%d", &N);
    maxL = maxR = L = R = 1;
    scanf("%d", &sum);
    maxSum = sum;
    if(sum < 0) {
      sum = 0; L = 2;
    }
    for(i = 2; i <= N; ++i) {
      scanf("%d", &v);
      sum += v;
      if(sum > maxSum) {
        maxSum = sum;
        maxL = L;
        maxR = i;
      }
      if(sum < 0) {
        sum = 0; L = i + 1;
      }
    }
    printf("%d %d %d\n", maxSum, maxL, maxR);
    if(cas != T) printf("\n");
  }
  return 0;
}