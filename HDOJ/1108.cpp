////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-01-25 19:22:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1108
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
//最小公倍数等于两数的乘积除以最大公约数
#include <stdio.h>

int main(){
    int x, y, t, xx, yy;
    while( scanf( "%d%d", &x, &y ) == 2 ){
        xx = x; //保存原数据
        yy = y;
        while( yy ){
            t = xx % yy;
            xx = yy;
            yy = t;
        } //xx为最大公约数,副本被销毁
        printf( "%d\n", x / xx * y ); //防溢出
    }
    return 0;
}
