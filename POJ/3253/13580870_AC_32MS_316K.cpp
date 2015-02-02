// POJ3253
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

#define maxn 20010
typedef long long LL;

int main() {
	int n, t;
	LL sum;
	while(scanf("%d", &n) == 1) {
		std::priority_queue<int, vector<int>, greater<int> > pq;
		while(n--) {
			scanf("%d", &t);
			pq.push(t);
		}
		sum = 0;
		while(pq.size() > 1) {
			t = pq.top(); pq.pop();
			t += pq.top(); pq.pop();
			sum += t; pq.push(t);
		}
		printf("%lld\n", sum);
	}
	return 0;
}