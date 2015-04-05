/************************************************************* 
 * 有N个数，M条关系，每条关系形如：a, b, w，表示[a,b]的和为w，
 * 求这M条关系里有多少是错误的。
 * 总结：错误的判断需要一个标准
 *************************************************************/ 
#include <stdio.h>
#include <string.h>

const int maxn = 2e5 + 10;
struct Node {
    int root, weight;
} RT[maxn];
int N, M;

int find(int k) {
    if (RT[k].root == 0)
        return k;

    int rt = find(RT[k].root);
    RT[k].weight += RT[RT[k].root].weight;
    RT[k].root = rt;

    return rt;
}

bool unite(int x, int y, int w) {
    int rt_x = find(x);
    int rt_y = find(y);

    if (rt_x < rt_y) {
        RT[rt_x].root = rt_y;
        RT[rt_x].weight = w - RT[x].weight + RT[y].weight;
    } else if (rt_x > rt_y) {
        RT[rt_y].root = rt_x;
        RT[rt_y].weight = RT[x].weight - w - RT[y].weight;
    } else if (w + RT[y].weight != RT[x].weight)
        return false; 

    return true;
}

int main() {
    int a, b, w, cnt_wrong;

    while (~scanf("%d%d", &N, &M)) {
        memset(RT, 0, sizeof(Node) * (N += 2));
        cnt_wrong = 0;

        while (M--) {
            scanf("%d%d%d", &a, &b, &w);
            if (unite(a, b + 1, w) == false)
                ++cnt_wrong;
        }

        printf("%d\n", cnt_wrong);
    }
    return 0;
}
