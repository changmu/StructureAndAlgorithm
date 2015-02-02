#include <stdio.h>
#include <string.h>
#include <algorithm>

#define maxn 12
#define inf 0x3f3f3f3f

int box[maxn], box1[maxn], box2[maxn], vis[maxn], num, num1, num2;
int minSub, ans, sign; // sign 用来标记奇偶

void Select(int k) {
    for(int i = 0; k < num1 && i < num; ++i)
        if(!vis[i]) {
            vis[i] = 1;
            box1[k++] = box[i];
        }
    for(int i = num - 1; sign < num2 && i >= 0; --i)
        if(!vis[i]) {
            box2[sign++] = box[i];
        }
    int a = 0, b = 0;
    for(int i = 0; i < num1; ++i)
        a = a * 10 + box1[i];
    for(int i = 0; i < num2; ++i)
        b = b * 10 + box2[i];
    ans = std::min(ans, a - b);
}

int main() {
    int T, i;
    char ch;
    scanf("%d", &T);
    while(T--) {
        num = 0;
        while(scanf("%d%c", &box[num++], &ch)) {
            vis[num-1] = 0;
            if(ch == '\n') break;
        }

        std::sort(box, box + num);
        num2 = num >> 1;
        num1 = num - num2;
        ans = inf;

        if(num == 2 && box[0] == 0) { // 特判
            printf("%d\n", box[1]);
            continue;
        }

        minSub = 10;
        sign = 0;

        if(num & 1) {
            if(box[0]) {
                vis[0] = 1;
                box1[0] = box[0];
            } else {
                vis[1] = 1;
                box1[0] = box[1];
            }
            Select(1);
        } else {
            i = 1;
            if(!box[0]) i = 2;
            for( ; i < num; ++i)
                minSub = std::min(minSub, box[i] - box[i-1]);
            for(i = 1; i < num; ++i) {
                if(box[i-1] && box[i] - box[i-1] == minSub) {
                    vis[i] = 1; vis[i-1] = 1;
                    box1[0] = box[i];
                    box2[0] = box[i-1];
                    sign = 1;
                    Select(1);
                    memset(vis, 0, sizeof(vis));
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
