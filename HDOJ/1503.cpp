#include <stdio.h>
#include <string.h>

const int maxn = 110;
int dp[maxn][maxn];
int mark[maxn][maxn];
char str1[maxn], str2[maxn];
int len1, len2;

void LCS_with_path()
{
    int i, j;

    /* attention! the first deminsion means str1, second means str2 */
    for (i = 1; i <= len1; ++i)
        mark[i][0] = 1;     // to left
    for (i = 1; i <= len2; ++i)
        mark[0][i] = -1;    // to up

    for (i = 1; i <= len1; ++i)
        for (j = 1; j <= len2; ++j) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                mark[i][j] = 0;     // whether left or up is ok    
            } else if (dp[i-1][j] >= dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                mark[i][j] = 1;     // indicate 'j' is contributed
            } else {
                dp[i][j] = dp[i][j-1];
                mark[i][j] = -1;
            }
        }
/*    for (i = 0; i <= len1; ++i)
        for (j = 0; j <= len2; ++j)
            printf("%d%c", mark[i][j], j == len2 ? '\n' : '\t');
    puts("-------------------------");*/
}

void print_path(int x, int y)
{
    if (!x && !y) {
        puts("");
        return;
    }

    if (0 == mark[x][y]) {
        print_path(x - 1, y - 1);
        putchar(str1[x-1]);
    } else if (1 == mark[x][y]) {
        print_path(x - 1, y);
        putchar(str1[x-1]);
    } else {
        print_path(x, y - 1);
        putchar(str2[y-1]);
    }
}

int main()
{
    while (~scanf("%s%s", str1, str2)) {
        len1 = strlen(str1);
        len2 = strlen(str2);
        LCS_with_path();
        print_path(len1, len2);
    }
    return 0;
}
