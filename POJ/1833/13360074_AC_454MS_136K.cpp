#include <stdio.h>
#include <algorithm>
using std::next_permutation;

int arr[1028], k;

int main()
{
    int n, i, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        for(i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        while(k--)
            next_permutation(arr, arr + n);
        for(i = 0; i < n; ++i)
            if(i != n - 1) printf("%d ", arr[i]);
        else printf("%d\n", arr[i]);
    }
    return 0;
}