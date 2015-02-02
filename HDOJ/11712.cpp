////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-26 14:48:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1171
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:456KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 250002

struct Node{
    int v, m;
} arr[52];
bool c1[maxn], c2[maxn];

int main()
{
    int n, temp, mid, i, id, sum, j, k, a, b;
    while(scanf("%d", &n), n > 0){        
        for(id = sum = 0; id < n; ++id){
            scanf("%d%d", &arr[id].v, &arr[id].m);
            sum += arr[id].v * arr[id].m;
        }
        memset(c1, 0, sum * sizeof(c1[0]));
        memset(c2, 0, sum * sizeof(c2[0]));
        sum = arr[0].v * arr[0].m;
        for(i = 0; i <= sum; i += arr[0].v)
            c1[i] = 1;
        for(i = 1; i < id; ++i){
            temp = arr[i].v * arr[i].m;
            for(j = 0; j <= sum; ++j)
                if(c1[j]) for(k = 0; k <= temp; k += arr[i].v)
                    c2[k + j] += c1[j];
            sum += temp;
            for(k = 0; k <= sum; ++k){
                c1[k] = c2[k]; c2[k] = 0;
            }
        }
        mid = sum >> 1;
        while(c1[mid] == false) --mid;
        b = mid; a = sum - b;
        printf("%d %d\n", a, b);
    }
    return 0;
}
