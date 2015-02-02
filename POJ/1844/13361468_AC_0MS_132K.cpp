#include <stdio.h>

int main()
{
    int s, sum, i;
    while(scanf("%d", &s) == 1){
        sum = 0; i = 0;
        while(sum < s || (sum - s) & 1)
            sum += ++i;
        printf("%d\n", i);
    }
    return 0;
}