////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-06 10:48:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1106
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>

#define maxn 1010

char buf[maxn];
int arr[maxn];

int main() {
    int id, i;
    char *p;
    while(~scanf("%s", buf)) {
        p = strtok(buf, "5");
        id = 0;
        while(p) {
            sscanf(p, "%d", &arr[id++]);
            p = strtok(NULL, "5");
        }
        std::sort(arr, arr + id);
        for(i = 0; i < id; ++i)
            if(i != id - 1) printf("%d ", arr[i]);
            else printf("%d\n", arr[i]);
    }
    return 0;
}