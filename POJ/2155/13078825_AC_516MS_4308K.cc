#include <stdio.h>
#include <string.h>
#define maxn 1002

int size, tree[maxn][maxn];

int lowBit(int x){ return x & (-x); }

//向下更新表示A[1]...A[i]每个元素都要 += val,推广到二维同理
void update(int x, int y, int val)
{
	int temp;
	while(x > 0){
		temp = y;
		while(temp > 0){
			tree[x][temp] += val;
			temp -= lowBit(temp);
		}
		x -= lowBit(x);
	}
}

int query(int x, int y)
{
	int sum = 0, temp;
	while(x <= size){
		temp = y;
		while(temp <= size){
			sum += tree[x][temp];
			temp += lowBit(temp);
		}
		x += lowBit(x);
	}
	return sum;
}

int main()
{
	//freopen("stdin.txt", "r", stdin);
	
	int cas, q, a, b, c, d;
	char com[2];
	scanf("%d", &cas);
	
	while(cas--){
		scanf("%d%d", &size, &q);
		memset(tree, 0, sizeof(tree));
		
		while(q--){
			scanf("%s%d%d", com, &a, &b);
			if(com[0] == 'C'){
				scanf("%d%d", &c, &d);
				update(c, b - 1, -1);
				update(a - 1, d, -1);
				update(a - 1, b - 1, 1);
				update(c, d, 1);
			}else printf("%d\n", query(a, b) & 1);
		}
		
		if(cas) printf("\n");
	}
	return 0;
}