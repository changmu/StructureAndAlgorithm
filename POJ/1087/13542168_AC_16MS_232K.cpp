#include <stdio.h>
#include <string.h>
#include <string>
#include <map>

#define maxn 1010
#define maxm maxn * maxn << 1
#define maxs 30
#define inf 0x3f3f3f3f

int n, m, k, source, sink, num;
char str[maxs], buf[maxs];
std::map<std::string, int> mp;
int head[maxn], id;
struct Ndoe {
	int u, v, c, next;
} E[maxm];
int dep[maxn], ps[maxn], cur[maxn];

void addEdge(int u, int v, int c) {
	E[id].u = u; E[id].v = v;
	E[id].c = c; E[id].next = head[u];
	head[u] = id++;

	E[id].u = v; E[id].v = u;
	E[id].c = 0; E[id].next = head[v];
	head[v] = id++;
}

void getMap() {
	int i; id = 0; num = 3;
	source = 1; sink = 2;
	memset(head, -1, sizeof(head));
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%s", str);
		if(mp[str] == 0) mp[str] = num++;
		addEdge(mp[str], sink, 1);
	}
	scanf("%d", &m);
	for(i = 0; i < m; ++i) {
		scanf("%s%s", str, buf);
		mp[str] = num++;
		if(mp[buf] == 0) mp[buf] = num++;
		addEdge(mp[str], mp[buf], 1);
		addEdge(source, mp[str], 1);
	}
	scanf("%d", &k);
	for(i = 0; i < k; ++i) {
		scanf("%s%s", str, buf);
		if(mp[str] == 0) mp[str] = num++;
		if(mp[buf] == 0) mp[buf] = num++;
		addEdge(mp[str], mp[buf], inf);
	}
}

int Dinic(int n, int s, int t) {
    int tr, res = 0;
    int i, j, k, f, r, top;
    while(true) {
        memset(dep, -1, n * sizeof(int));
        for(f = dep[ps[0] = s] = 0, r = 1; f != r; )
            for(i = ps[f++], j = head[i]; j != -1; j = E[j].next) {
                if(E[j].c && -1 == dep[k=E[j].v]) {
                    dep[k] = dep[i] + 1; ps[r++] = k;
                    if(k == t) {
                        f = r; break;
                    }
                }
            }
        if(-1 == dep[t]) break;

        memcpy(cur, head, n * sizeof(int));
        for(i = s, top = 0; ; ) {
            if(i == t) {
                for(k = 0, tr = inf; k < top; ++k)
                    if(E[ps[k]].c < tr) tr = E[ps[f=k]].c;
                for(k = 0; k < top; ++k)
                    E[ps[k]].c -= tr, E[ps[k]^1].c += tr;
                res += tr; i = E[ps[top = f]].u;
            }
            for(j = cur[i]; cur[i] != -1;j = cur[i] = E[cur[i]].next)
                if(E[j].c && dep[i] + 1 == dep[E[j].v]) break;
            if(cur[i] != -1) {
                ps[top++] = cur[i];
                i = E[cur[i]].v;
            } else {
                if(0 == top) break;
                dep[i] = -1; i = E[ps[--top]].u;
            }
        }
    }
    return res;
}

void solve() {
	printf("%d\n", m - Dinic(num, source, sink));
}

int main() {
	getMap();
	solve();
	return 0;
}