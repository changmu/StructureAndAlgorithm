#include <stdio.h>
#include <string.h>
#define UP 0
#define DOWN 1
#define maxn 25

long long C[maxn][maxn][2];
//C[i][k][DOWN] 是S(i)中以第k短的木棒打头的DOWN方案数,C[i][k][UP] 
//是S(i)中以第k短的木棒打头的UP方案数,第k短指i根中第k短

void Init(int n)
{
    memset(C, 0, sizeof(C));
    C[1][1][UP] = C[1][1][DOWN] = 1;
    int i, k, M, N;
    for(i = 2; i <= n; ++i){
        for(k = 1; k <= i; ++k){ //枚举第一根木棒的长度
            //枚举第二根长度
            for(M = k; M < i; ++M) C[i][k][UP] += C[i-1][M][DOWN];
            //枚举第二根长度
            for(N = 1; N < k; ++N) C[i][k][DOWN] += C[i-1][N][UP];
        }
    }
    //总方案数是 Sum{ C[n][k][DOWN] + C[n][k][UP] } k = 1.. n;
}

void Print(int n, long long cc)
{
    long long skipped = 0, oldVal; //已经跳过的方案数
    int seq[maxn]; //最终要输出的答案
    int used[maxn]; //木棒是否用过
    memset(used, 0, sizeof(used));
    for(int i = 1, k; i <= n; ++i){ //依次确定位置i的木棒序号
        int No = 0;
        for(k = 1; k <= n; ++k){ //枚举位置i的木棒
            oldVal = skipped;
            if(!used[k]){
                ++No; //k是剩下木棒里的第No短的
                if(i == 1) skipped += C[n][No][UP] + C[n][No][DOWN];
                //以下寻找合法位置
                else if(k > seq[i-1] && (i == 2 || seq[i-2] > seq[i-1]))
                    skipped += C[n-i+1][No][DOWN];
                else if(k < seq[i-1] && (i == 2 || seq[i-2] < seq[i-1]))
                    skipped += C[n-i+1][No][UP];
                if(skipped >= cc) break;
            }
        }
        used[k] = 1;
        seq[i] = k;
        skipped = oldVal;
    }
    for(int i = 1; i <= n; ++i)
        if(i < n) printf("%d ", seq[i]);
        else printf("%d\n", seq[i]);
}

int main()
{
    int T, n; long long c;
    Init(20);
    scanf("%d", &T);
    while(T--){
        scanf("%d%lld", &n, &c);
        Print(n, c);
    }
    return 0;
}
