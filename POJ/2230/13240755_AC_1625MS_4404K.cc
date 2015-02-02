#include <stdio.h>
#include <string.h>
#define maxn 10002
#define maxm 50002

int n, m;
int head[maxn];
bool vis[maxm << 1];
struct Node{
	int to, next;
} edge[maxm << 1];

void Init()
{
	memset(head, -1, sizeof(head));
	memset(vis, 0, sizeof(vis));
}

void GetEdge()
{
	int i, a, b;
	m <<= 1;
	for(i = 0; i < m; ++i){
		scanf("%d%d", &a, &b);
		edge[i].to = b;
		edge[i].next = head[a];
		head[a] = i++;
		edge[i].to = a;
		edge[i].next = head[b];
		head[b] = i;
	}
}

void DFS(int k)
{
	for(int i = head[k]; i != -1; i = edge[i].next){
		if(!vis[i]){
			vis[i] = 1;
			DFS(edge[i].to);
		}
	}
	printf("%d\n", k);
}
int main()
{
	int i;
	while(scanf("%d%d", &n, &m) == 2){
		Init();
		GetEdge();
		DFS(1);
	}
	return 0;
}