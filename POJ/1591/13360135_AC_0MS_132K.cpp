#include <stdio.h>
#include <string.h>
#define maxn 52

bool vis[maxn];
int card[22], n, m, preOut;

int getHead()
{
    int i;
    for(i = 0; i < n; ++i)
        if(!vis[i]) return i;
}

int getOut(int pos, int steps)
{
    int i = 0;
    while(i < steps){
        if(++pos == n){
            return preOut = -1;
        }
        if(!vis[pos]) ++i;        
    }
    return preOut = pos;
}

int main()
{
    int i, cas = 1, now, count;
    while(scanf("%d%d", &n, &m) == 2){
        memset(vis, 0, sizeof(bool) * n);
        for(i = 0; i < 20; ++i)
            scanf("%d", &card[i]);
        printf("Selection #%d \n", cas++);
        preOut = -1; count = 0; i = -1;
        while(count < n - m){
            if(preOut == -1) ++i;
            getOut(preOut, card[i % 20]);
            if(preOut != -1){
                ++count; vis[preOut] = 1;
            }
        }
        for(i = 0; i < n && m; ++i)
            if(!vis[i]){
                if(--m) printf("%d ", i + 1);
                else printf("%d\n", i + 1);
            }
        printf("\n");
    }
    return 0;
}