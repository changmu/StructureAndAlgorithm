//notmine
#include<cstdio>
#include<cstring>
using namespace std;
#define P 110
#define N 310
int map[P][N];
int match[N];
bool use[N];
int p, n;

bool find(int u) //u是课程
{
	for(int i = 1; i <= n; ++i)
	{
		if(!use[i] && map[u][i]) //标记匹配的学生
		{
			use[i] = true;
			if(match[i] == - 1 || find(match[i]))
			{
				match[i] = u;
				return true;
			}
		}
	}
	return false;
}

int sum()
{
	int sumall = 0;
	for(int i = 1; i <= p; ++i) //统计匹配的课程
	{
		memset(use, false, sizeof(use));
		if(find(i))
			sumall++;
	}
	return sumall;
}

int main()
{
	int ncase;
	int stunum, temp, ans;
	scanf("%d", &ncase);
	while(ncase--)
	{
		memset(map, 0, sizeof(map));
		memset(match, -1, sizeof(match));
		scanf("%d%d", &p, &n);
		for(int i = 1; i <= p; ++i)
		{
			scanf("%d", &stunum);
			for(int j = 1; j <= stunum; ++j)
			{
				scanf("%d", &temp); 
				map[i][temp] = 1; //j号学生喜欢i号课程
			}
		}
		ans = sum();
		printf("%s\n", ans == p ? "YES" : "NO");
	}
	return 0;
}