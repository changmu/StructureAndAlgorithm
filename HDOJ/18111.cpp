////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-11-24 21:36:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1811
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:500KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 10010
#define maxm 20010

int N, M, pre[maxn], hash[maxn];
int head[maxn], id, cnt, in[maxn];
bool U, C;
struct Node {
	int u, v, next;
} E[maxm];

int ufind(int k) {
	int a = k, b;
	while(pre[k] != -1) k = pre[k];
	while(a != k) {
		b = pre[a];
		pre[a] = k;
		a = b;
	}
	return k;
}

bool same(int a, int b) {
	return ufind(a) == ufind(b);
}

bool unite(int a, int b) {
	a = ufind(a);
	b = ufind(b);
	if(a == b) return false;
	else {
		pre[a] = b;
		return true;
	}
}

void getMap() {
	memset(pre, -1, sizeof(int) * N);
	memset(head, -1, sizeof(int) * N);
	memset(in, 0, sizeof(int) * N);
	int u, v, i; id = 0;
	char ch;
	for(i = 0; i < M; ++i) {
		scanf("%d %c %d", &u, &ch, &v);
		if(ch == '=') {
			unite(u, v);
		} else if(ch == '<') {
			E[id].u = v;
			E[id++].v = u;
		} else {
			E[id].u = u;
			E[id++].v = v;
		}
	}
}

void solve() {
	int i, j, u, v, iq, front; U = C = 0;
	/* 以下使用并查集来缩点 */
	memset(hash, -1, sizeof(int) * N);
	for(i = cnt = 0; i < N; ++i) {
		u = ufind(i);
		if(hash[u] != -1) hash[i] = hash[u];
		else hash[u] = hash[i] = cnt++;
	}
	for(i = 0; i < id; ++i) {
		E[i].u = hash[E[i].u];
		E[i].v = hash[E[i].v];
		++in[E[i].v];
		E[i].next = head[E[i].u];
		head[E[i].u] = i;
	} // 至此新图构造完成, 共有cnt个节点
	/* 以下开始拓扑排序 当且仅当图是一条路径时名次才可能确定 */
	// 由于原hash数组已废，可以当队列来用
	iq = front = 0;
	for(i = 0; i < cnt; ++i)
		if(in[i] == 0) hash[iq++] = i;
	while(front != iq) {
		if(iq - front > 1) U = 1;
		u = hash[front++];
		for(i = head[u]; i != -1; i = E[i].next) {
			if(!--in[v = E[i].v]) hash[iq++] = v;
		}
	}
	if(iq != cnt) C = 1; // 有环
	/* 以下输出结果，C的优先级最高 */
	if(C) printf("CONFLICT\n");
	else if(U) printf("UNCERTAIN\n");
	else printf("OK\n");
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	while(scanf("%d%d", &N, &M) == 2) {
		getMap();
		solve();
	}
	return 0;
}
