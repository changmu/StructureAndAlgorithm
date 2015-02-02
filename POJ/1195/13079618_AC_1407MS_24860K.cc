#include <stdio.h>
#define maxn 1026
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

int tree[maxn * 3][maxn * 3], size;

void getSize(){ scanf("%d", &size); }

void updateY(int rootX, int pos, int val, int l, int r, int rt)
{
	tree[rootX][rt] += val;
	if(l == r) return;
	
	int mid = (l + r) >> 1;
	if(pos <= mid) updateY(rootX, pos, val, lson);
	else updateY(rootX, pos, val, rson);
}

void updateX(int x, int y, int val, int l, int r, int rt)
{
	//更新的任务都交给updateY
	updateY(rt, y, val, 0, size - 1, 1);
	if(l == r) return;
	
	int mid = (l + r) >> 1;
	if(x <= mid) updateX(x, y, val, lson);
	else updateX(x, y, val, rson);
}

void update()
{
	int x, y, val;
	scanf("%d%d%d", &x, &y, &val);
	updateX(x, y, val, 0, size - 1, 1);	
}

int queryY(int rootX, int y1, int y2, int l, int r, int rt)
{
	if(l == y1 && r == y2) return tree[rootX][rt];
	
	int mid = (l + r) >> 1;
	if(y2 <= mid) return queryY(rootX, y1, y2, lson);
	else if(y1 > mid) return queryY(rootX, y1, y2, rson);
	else{
		return queryY(rootX, y1, mid, lson) + queryY(rootX, mid + 1, y2, rson);
	}
}

int queryX(int x1, int x2, int y1, int y2, int l, int r, int rt)
{
	if(x1 == l && x2 == r) return queryY(rt, y1, y2, 0, size - 1, 1);
	
	int mid = (l + r) >> 1;
	if(x2 <= mid) return queryX(x1, x2, y1, y2, lson);
	else if(x1 > mid) queryX(x1, x2, y1, y2, rson);
	else{
		return queryX(x1, mid, y1, y2, lson) + queryX(mid + 1, x2, y1, y2, rson);
	}
}

void query()
{
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	
	printf("%d\n", queryX(x1, x2, y1, y2, 0, size - 1, 1));
}

void (*funArr[])() = {
	getSize, update, query
};

int main()
{	
	int num;
	while(scanf("%d", &num), num != 3)
		(*funArr[num])();
	return 0;
}