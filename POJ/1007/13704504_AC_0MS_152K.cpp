#include <stdio.h>
#include <string.h>
#include <algorithm>
using std::stable_sort;
#define maxn 102

struct Node {
    int inverNum;
    char str[52];
} arr[maxn];
int N, M;

bool cmp(Node a, Node b) {
    return a.inverNum < b.inverNum;
}

int getInver(char *str) {
    int sum = 0, i, j;
    for(i = 0; i < N - 1; ++i)
        for(j = i + 1; j < N; ++j)
            if(str[i] > str[j]) ++sum;
    return sum;
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int i, j;
    while(scanf("%d%d", &N, &M) == 2) {
        for (i = 0; i < M; ++i) {
            scanf("%s", arr[i].str);
            arr[i].inverNum = getInver(arr[i].str);
        }
        stable_sort(arr, arr + M, cmp);
        for (i = 0; i < M; ++i)
            puts(arr[i].str);
    }
    return 0;
}