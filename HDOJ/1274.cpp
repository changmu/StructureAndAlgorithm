#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdio>

using namespace std;

const int maxn = 300;
char buf[maxn];

string DFS(int &k)
{
    string str, str0;
    int num = 0;

    while (true) {
        if (buf[k] == '(') {
            str0 = DFS(k = k + 1);
            if (!num) num = 1;
            while (num--) str += str0;
            num = 0;
        } else if (buf[k] == '\0') {
            return str;
        } else if (buf[k] == ')') {
            ++k;
            return str;            
        } else if (isdigit(buf[k])) {
            num = 0;
            while (isdigit(buf[k])) 
                num = num * 10 + buf[k++] - '0';
        } else {
            if (!num) num = 1;
            while (num--) str += buf[k];
            ++k;
            num = 0;
        }
    }
}

int main()
{
    int T, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", buf);
        cout << DFS(k = 0) << endl;
    }
    return 0;
}
