////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-25 15:41:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1272
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:764KB
//////////////////System Comment End//////////////////
// Ð¡Ï£µÄÃÔ¹¬
#include <stdio.h>
#include <string.h>

#define maxn 100005

int pre[maxn];
bool vis[maxn];

int ufind(int k) {
  int a = k, b;
  while(pre[k] != -1) k = pre[k];
  while(a != k) {
    b = pre[a];
    pre[a] = k;
    a = b;
  }
  return k;
}

bool unite(int x, int y) {
  x = ufind(x);
  y = ufind(y);
  if(x == y) return false;
  pre[x] = y;
  return true;
}

int main() {
  // freopen("stdin.txt", "r", stdin);
  int i, j, cnt = 0, x, y, ok = 1;
  memset(pre, -1, sizeof(pre));
  memset(vis, 0, sizeof(vis));
  while(scanf("%d%d", &x, &y), x >= 0) {
    if(x == 0) {
      if(cnt > 1) ok = 0;
      printf(ok ? "Yes\n" : "No\n");
      ok = 1; cnt = 0;
      memset(pre, -1, sizeof(pre));
      memset(vis, 0, sizeof(vis));
      continue;
    }
    if(ok == 0) continue;
    if(!vis[x]) {
      vis[x] = 1; ++cnt;
    }
    if(!vis[y]) {
      vis[y] = 1; ++cnt;
    }
    if(!unite(x, y)) ok = 0;
    else --cnt;
  }
  return 0;
}