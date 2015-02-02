#include <stdio.h>
#include <string.h>
#define maxn 200

struct Node{
    int color, len;
} segment[maxn];
int score[maxn][maxn][maxn], arr[maxn];

int clickBox(int left, int right, int exLen)
{
    if(score[left][right][exLen]) return score[left][right][exLen];
    int i, ans, ans2;
    ans = segment[right].len + exLen;
    ans = ans * ans;
    if(left == right) return score[left][right][exLen] = ans;
    ans += clickBox(left, right - 1, 0);
    for(i = right - 1; i >= left; --i){
        if(segment[i].color != segment[right].color) continue;
        ans2 = clickBox(left, i, exLen + segment[right].len) +
                clickBox(i + 1, right - 1, 0);
        if(ans2 > ans) ans = ans2; break;
    }
    return score[left][right][exLen] = ans; 
}

int main()
{
    int t, n, i, id, cas = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i = 0; i < n; ++i) scanf("%d", arr + i);
        memset(score, 0, sizeof(score));
        segment[id = 0].color = arr[0];
        segment[id].len = 1;
        for(i = 1; i < n; ++i){
            if(arr[i] != arr[i-1]){
                segment[++id].color = arr[i];
                segment[id].len = 1;
            }else ++segment[id].len;
        }
        printf("Case %d: %d\n", cas++, clickBox(0, id, 0));
    }
    return 0;
}
