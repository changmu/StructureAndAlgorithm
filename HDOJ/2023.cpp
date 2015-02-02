////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-01-26 19:45:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2023
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, m, a[50][5], count, ok;
	double ave[5], stu[50], t;
	while( scanf( "%d%d", &n, &m) == 2 ){
		count = 0;
		for( int i = 0; i != n; ++i )
			for( int j = 0; j != m; ++j )
				scanf( "%d", &a[i][j] );
		//统计平均数
		t = 0;
		for( int i = 0; i != m; ++i ){
			for( int j = 0; j != n; ++j )
				t += a[j][i];
			ave[i] = t / n;
			t = 0;
		}
		for( int i = 0; i != n; ++i ){
			for( int j = 0; j != m; ++j )
				t += a[i][j];
			stu[i] = t / m;
			t = 0;
		}
		//统计合格人数
		ok = 1;
		for( int i = 0; i != n; ++i ){
			for( int j = 0; j != m; ++j )
				if( a[i][j] < ave[j] ){ ok = 0; break; }
			if( ok ) ++count;
			ok = 1;
		}
		//输出
		for( int i = 0; i != n - 1; ++i )
			printf( "%.2lf ", stu[i] );
		printf( "%.2lf\n", stu[n - 1] );
		for( int i = 0; i != m - 1; ++i )
			printf( "%.2lf ", ave[i] );
		printf( "%.2lf\n", ave[m - 1] );
		printf( "%d\n\n", count );
	}
	return 0;
}