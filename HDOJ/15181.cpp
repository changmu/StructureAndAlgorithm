////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-11-04 11:56:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1518
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <functional>
#include <algorithm>

#define maxn 22

int L[maxn], n, tar, times; // tar是边长，
bool vis[maxn], ok;

bool DFS(int k, int leftLen) {
    if(!leftLen) { // 当前边组合完成
        if(++times == 4) return true; // 4条边全部组合出来
        for(int i = 1; i < n; ++i) { // 开始组合下一条边
            if(!vis[i]) { // 第一根未选择的棍子必选，若它无法组合完成那么任务失败
                vis[i] = 1;
                if(DFS(i + 1, tar - L[i])) 
                    return true; // 任务完成
                else { // 失败则回溯
                    --times; // 之前的组合方案失败，清理现场，重新组合
                    vis[i] = 0;
                    return false;
                }
            }
        }
    }

    int i;
    for(i = k; i < n; ++i) {
        if(!vis[i] && L[i] <= leftLen) {
            vis[i] = 1;
            if(L[i-1] == L[i] && !vis[i-1]) { // 重要剪枝，原理是
                // 若前一根跟当前根长度相同但未选择，说明前一根的
                //搭配方案失败，那么当前根若选择的话也必定失败，所以cut掉
                vis[i] = 0;
                continue;
            }
            if(DFS(i+1, leftLen - L[i]))
                return true;
            vis[i] = 0;
        }
    }

    return false;
}

int main() {
    int t, i;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        tar = 0;
        for(i = 0; i < n; ++i) {
            scanf("%d", &L[i]);
            vis[i] = 0; tar += L[i];
        }

        if(tar % 4) { // cut1, you know why
            printf("no\n");
            continue;
        }
        tar /= 4; // 需要组合的目标长度

        std::sort(L, L + n, std::greater<int>()); // 降序
        if(L[0] > tar) { // cut2, you know why
            printf("no\n");
            continue;
        }

        times = 0; vis[0] = 1; // cut3, 第一根必选，很重要的剪枝，
        //因为如果第一根开始无法组合那么即便从后面开始能组合出
        //目标长度也不可能组合成四条边
        DFS(1, tar - L[0]); // 由于第一根已选，那么从第二根开始遍历，
        //第二个参数为剩余需要组合的长度

        printf(times == 4 ? "yes\n" : "no\n"); // 4条边全部组合成功才yes
    }
    return 0;
}