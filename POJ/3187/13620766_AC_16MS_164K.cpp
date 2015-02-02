#include <stdio.h>
#include <string.h>
#include <algorithm>

int lev[12][12];
int box[12], N, S;

int main() {
    int i, j, sum;
    lev[1][1] = 1;
    for(i = 2; i <= 10; ++i)
        for(j = 1; j <= i; ++j)
            if(j == 1 || j == i) lev[i][j] = 1;
            else lev[i][j] = lev[i-1][j] + lev[i-1][j-1];
            
    while(scanf("%d%d", &N, &S) == 2) {
        for(i = 1; i <= N; ++i)
            box[i] = i;
        do {
            sum = 0;
            for(i = 1; i <= N; ++i)
                sum += box[i] * lev[N][i];
            if(sum == S) break;
        } while(std::next_permutation(box + 1, box + N + 1));

        for(i = 1; i <= N; ++i)
            printf("%d%c", box[i], i == N ? '\n' : ' ');
    }
    return 0;
}