#include <stdio.h>
#include <algorithm>
#define maxn 202
#define lson l, mid, rt << 1
#define rson mid, r, rt << 1 | 1
using std::sort;

struct Node{
	double y1, y2, height; //y1, y2记录y坐标离散前的值
	int coverTimes;
} tree[maxn << 2]; //区间树
double yArr[maxn]; //垂直于Y轴的割线
struct node{
	double x, y1, y2;
	int isLeftEdge;
} xArr[maxn]; //垂直于X轴的割线

bool cmp(node a, node b){ return a.x < b.x; }

void build(int l, int r, int rt)
{
	tree[rt].coverTimes = 0;
	tree[rt].height = 0;
	tree[rt].y1 = yArr[l];
	tree[rt].y2 = yArr[r];
	if(r - l == 1) return;
	
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
}

void getSweepLinesHeight(int l, int r, int rt)
{//由于存在线段覆盖的情况，所以长线段结束并不能代表扫描线长度为0
	if(tree[rt].coverTimes > 0){ 
		tree[rt].height = tree[rt].y2 - tree[rt].y1;
	}else if(r - l == 1){
		tree[rt].height = 0;
	}else tree[rt].height = tree[rt << 1].height + tree[rt << 1 | 1].height;
}

void update(node xNode, int l, int r, int rt)
{
	if(xNode.y1 == tree[rt].y1 && xNode.y2 == tree[rt].y2){
		tree[rt].coverTimes += xNode.isLeftEdge;
		getSweepLinesHeight(l, r, rt);
		return;
	} //include r - l == 1
	
	int mid = (l + r) >> 1;	
	if(xNode.y2 <= yArr[mid]) update(xNode, lson);
	else if(xNode.y1 >= yArr[mid]) update(xNode, rson);
	else{
		node temp = xNode;
		temp.y2 = yArr[mid];
		update(temp, lson);
		temp = xNode; temp.y1 =yArr[mid];
		update(temp, rson);
	}
	
	getSweepLinesHeight(l, r, rt); //Attention!	
}

int main()
{
	//freopen("stdin.txt", "r", stdin);
	int n, i, cas = 1, id;
	double x1, y1, x2, y2, sum;
	while(scanf("%d", &n), n){
		for(i = id = 0; i < n; ++i){
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			yArr[id] = y1; xArr[id].x = x1;
			xArr[id].isLeftEdge = 1; //1表示左，-1表示右
			xArr[id].y1 = y1; xArr[id++].y2 = y2;
			
			yArr[id] = y2; xArr[id].x = x2;
			xArr[id].isLeftEdge = -1;
			xArr[id].y1 = y1; xArr[id++].y2 = y2;
		}
		
		sort(yArr, yArr + id);
		sort(xArr, xArr + id, cmp);
		build(0, id - 1, 1);		
				
		update(xArr[0], 0, id - 1, 1);
		for(i = 1, sum = 0; i < id; ++i){
			sum += tree[1].height * (xArr[i].x - xArr[i - 1].x);
			update(xArr[i], 0, id - 1, 1);
		}
		
		printf("Test case #%d\nTotal explored area: %.2lf\n\n", cas++, sum);
	}
	return 0;
}