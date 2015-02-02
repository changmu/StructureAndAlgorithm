#include <stdio.h>
#define maxn 1002
#define maxm 52

char bigMap[maxn][maxn], smallMap[maxm][maxm];
__int64 smallToInt[maxm], hash[maxn][maxn];
int m, n, t, p, q, next[maxm];

void toInt64(int i, int j)
{
    __int64 sum = 0;
    for(int k = 0; k < p; ++k)
        if(bigMap[i + k][j] == '*') sum = sum << 1 | 1;
        else sum <<= 1;
    hash[i][j] = sum;
}

void charToHash()
{
    int i, j, temp = n - p;
    for(i = 0; i <= temp; ++i){
        for(j = 0; j < m; ++j) toInt64(i, j);
    }
}

void getNext()
{
    __int64 sum;
    int i, j;
    for(i = 0; i < q; ++i){
        for(sum = j = 0; j < p; ++j)
            if(smallMap[j][i] == '*') sum = sum << 1 | 1;
            else sum <<= 1;
        smallToInt[i] = sum;
    }
    i = 0; j = -1;
    next[0] = -1;
    while(i < q){
        if(j == -1 || smallToInt[i] == smallToInt[j]){
            ++i; ++j;
            if(smallToInt[i] == smallToInt[j]) next[i] = next[j];
            else next[i] = j; //mode 2
        }else j = next[j];
    }
}

bool KMP()
{
    getNext();
    int i, j, k, temp = n - p;
    for(k = 0; k <= temp; ++k){
        i = j = 0;
        while(i < m && j < q){
            if(j == -1 || hash[k][i] == smallToInt[j]){
                ++i; ++j;
            }else j = next[j];            
        }  
        if(j == q) return true;          
    }
    return false;
}

int main()
{
   // freopen("stdin.txt", "r", stdin);
    int i, j, ans, cas = 1;
    while(scanf("%d%d%d%d%d", &n, &m, &t, &p, &q) != EOF){
        if(m + n + t + p + q == 0) break;
        for(i = 0; i < n; ++i)
            scanf("%s", bigMap[i]);
        charToHash(); ans = 0;
        while(t--){
            for(i = 0; i < p; ++i)
                scanf("%s", smallMap[i]);
            if(KMP()) ++ans;
        }
        printf("Case %d: %d\n", cas++, ans);
    }
    return 0;
} 
