#include <stdio.h>
#include <string.h>
#define maxn 1002

struct Node{
	int pre, c, t;
	double w;
} V[maxn];

int findMax(int n, int root)
{
	int i, u;
	double maxv = -1;
	for(i = 1; i <= n; ++i){
		if(V[i].w > maxv && i != root){
			maxv = V[i].w; u = i;
		}
	}
	return u;
}

int main()
{
	int n, root, i, ans, a, b, m, pre, j;
	while(scanf("%d%d", &n, &root), n || root){
		for(i = 1, ans = 0; i <= n; ++i){
			scanf("%d", &V[i].c);
			ans += V[i].c; V[i].t = 1;
			V[i].w = V[i].c;
		}
		for(i = 1; i < n; ++i){
			scanf("%d%d", &a, &b);
			V[b].pre = a;
		}
		for(i = 1; i < n; ++i){
			m = findMax(n, root);
			V[m].w = 0; pre = V[m].pre;
			ans += V[m].c * V[pre].t;
			for(j = 1; j <= n; ++j)
				if(V[j].pre == m) V[j].pre = pre;
			V[pre].c += V[m].c;
			V[pre].t += V[m].t;
			V[pre].w = (double)V[pre].c / V[pre].t;
		}
		printf("%d\n", ans);
	}
	return 0;
}