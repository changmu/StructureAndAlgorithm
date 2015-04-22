/************************************************************* 
 * 4个朋友聚会，其中一个今天过生，以下是他们的对话：
 * A：不是我
 * B：是C
 * C：是D
 * D：C在胡说
 * 已知有且只有一个人在说谎，问：谁今天过生日。
 *************************************************************/ 
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int bir, i, sum;
    for (bir = 0; bir < 4; ++bir) {
        sum = (bir != 0) + (bir == 2) + (bir == 3) + (bir != 3);
        if (sum == 3) break;
    }
    cout << "Today is " << (char)('A' + bir) << "'s birthday!" << endl;
    return 0;
}
