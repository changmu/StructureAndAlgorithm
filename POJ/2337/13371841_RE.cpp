#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#define maxn 26

int pre[maxn], vis[maxn], in[maxn], out[maxn];
struct Node{
    char str[32];
    int to;
};

bool cmp(Node a, Node b){
    return strcmp(a.str, b.str) < 0;
}

int ufind(int k)
{
    int a = k, b;
    while(pre[k] != -1) k = pre[k];
    while(a != k){
        b = pre[a];
        pre[a] = k;
        a = b;
    }
    return k;
}

int main()
{
    int t, n, i, u, v, count, len, ok, inc, outc;
    char str[32]; Node tmp;
    std::vector<Node> vec[maxn];
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(vec, 0, sizeof(vec));        
        for(i = 0; i < 26; ++i){
            vis[i] = in[i] = out[i] = 0;
            pre[i] = -1;
        }
        count = 0;
        for(i = 0; i < n; ++i){
            scanf("%s", str);
            len = strlen(str);
            u = str[0] - 'a';
            v = str[len-1] - 'a';
            strcpy(tmp.str, str);
            tmp.to = v;
            vec[u].push_back(tmp);
            if(!vis[u]) ++count;
            vis[u] = 1;
            if(!vis[v]) ++count;
            vis[v] = 1;
            ++out[u]; ++in[v];
            u = ufind(u); v = ufind(v);
            if(u != v){
                pre[v] = u; --count;
            }
        }
        if(count != 1){
            printf("***\n"); continue;
        }
        ok = 1; inc = outc = 0; u = -1;
        for(i = 0; i < 26; ++i){
            if(in[i] == out[i])
                continue;
            else if(out[i] - in[i] == 1){
                if(++outc > 1){
                    ok = 0; break;
                }
                u = i;
            }else if(in[i] - out[i] == 1){
                if(++inc > 1){
                    ok = 0; break;
                }
            }else{
                ok = 0; break;
            }
        }


        // for(i = 0; i < 26; ++i)
        //     printf("%c: %d %d\n", i + 'a', in[i], out[i]);


        if(!ok){
            printf("***\n"); continue;
        }
        for(i = 0; i < 26; ++i){
            if(!vec[i].empty()){
                std::sort(vec[i].begin(), vec[i].end(), cmp);
                if(u == -1) u = i;
            }
        }

        // for(i = 0; i < 26; ++i)
        //     if(!vec[i].empty()) for(int j = 0; j < vec[i].size(); ++j)
        //         printf("%s\n", vec[i][j].str);

        printf("%s", vec[u][0].str);
        v = vec[u][0].to;
        vec[u].erase(vec[u].begin());
        count = n - 1; u = v;
        while(count--){
            printf(".%s", vec[u][0].str);
            v = vec[u][0].to;
            vec[u].erase(vec[u].begin()); u = v;
        }
        printf("\n");
    }
    return 0;
}
