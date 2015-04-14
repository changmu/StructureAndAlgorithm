#include <stdio.h>
#include <string.h>
#include <queue>
#include <unordered_map>

using namespace std;

const int maxn = 1e4;
char buf[maxn];
int num[maxn], len;

int solve()
{
    unordered_map<char, int> mp;
    priority_queue<int, vector<int>, greater<int> > PQ;
    int i, sum = 0, x, y;
    char ch;

    for (i = 0; buf[i]; ++i)
        ++mp[buf[i]];
    for (len = i, ch = 'a'; ch <= 'z'; ++ch)
        if (mp[ch] > 0) PQ.push(mp[ch]);

    if (PQ.size() == 1) sum = PQ.top();
    while (PQ.size() > 1) {
        x = PQ.top(); PQ.pop();
        y = PQ.top(); PQ.pop();
        sum += x + y;
        PQ.push(x + y);
    }
    // printf("%d..\n", sum);
    return sum;
}

int main()
{
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &N, buf);
        puts(solve() > N ? "no" : "yes");
    }
    return 0;
}
