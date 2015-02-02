////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-01-25 11:56:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1753
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define MAX 400 + 10
char a0[MAX], b0[MAX], s[MAX], aa[MAX], bb[MAX], ss0[MAX];  //aa保存整数，a保存小数

int main(){
	char *dot;
	while( scanf( "%s%s", a0, b0 ) == 2 ){
		char *a = a0, *b = b0, *ss = ss0;
		aa[0] = bb[0] = '0';  //留着进位
		dot = strchr( a, '.' );
		if( dot == NULL ){ strcpy( aa + 1, a ); a[0] = '\0'; } //如果a是整数，将a置空
		else{ dot[0] = '\0'; strcpy( aa + 1, a ); a = dot + 1; }
		dot = strchr( b, '.' );
		if( dot == NULL ){ strcpy( bb + 1, b ); b[0] = '\0'; }
		else{ dot[0] = '\0'; strcpy( bb + 1, b ); b = dot + 1; }
		
		//接下来开始计算大整数相加aa+bb
		int aai = strlen( aa ), bbi = strlen( bb );  //保存整数位数
		int ssi = aai > bbi ? aai : bbi;
		ss[ssi] = '\0';
		int i = aai < bbi ? aai : bbi;  //保存较小位数
		int sign = 0, t; //保存进位
		while( i-- ){
			t = aa[--aai] - '0' + ( bb[--bbi] - '0' );
			t += sign; sign = 0;
			if( t > 9 ) { ++sign; t -= 10; }
			ss[--ssi] = t + '0';
		}
		while( aai ){ 
			t = aa[--aai] - '0';  //例如1+99999的情况
			t += sign; sign = 0;
			if( t > 9 ) { ++sign; t -= 10; }
			ss[--ssi] = t + '0'; 
		}
		while( bbi ){ 
			t = bb[--bbi] - '0'; 
			t += sign; sign = 0; 
			if( t > 9 ) { ++sign; t -= 10; }
			ss[--ssi] = t + '0'; 
		}
		//大整数加法aa+bb完成，2014-1-25 00:59:04
		
		//小数部分的加法，注意位要对齐，sign已被化成0，2014-1-25 09:49:02
		int ai = strlen( a ), bi = strlen( b );  //保存小数位数
		int si = ai > bi ? ai : bi;
		s[si] = '\0';
		int j = ai < bi ? ai : bi;  //保存较小位数
		while( j-- ){
			t = a[j] - '0' + ( b[j] - '0' );
			t += sign; sign = 0;
			if( t > 9 ){ ++sign; t -= 10; }
			s[j] = t + '0';
		}
		j = ai < bi ? ai : bi;
		if( ai < bi ) strcpy( s + j, b + j ); 
		else if( ai > bi ) strcpy( s + j, a + j );		
		
		//将小数位可能产生的进位整合到整数和ss中
		ssi = strlen( ss );
		if( sign ){ //如果小数相加产生了个位进位1
			while( ssi ){
				t = ss[--ssi] - '0' + sign;
				sign = 0;
				if( t > 9 ){ t -= 10; ++sign; }
				ss[ssi] = t + '0';
			} //整数部分整合完毕			
		}
		
		//处理小数和的末尾0
		si = strlen( s );
		while( si ){
			if( s[--si] == '0' ){ s[si] = '\0'; continue; }
			break;
		}
		
		//处理整数和可能存在的前导0
		int ii = 0;
		for( ; ss[ii] != '\0'; ++ii ){
			if( ss[ii] == '0' ) continue;
			break;
		}
		ss = ss + ii;
		if( !strlen(ss) ){  //防止ss被减成空字符串
			ss[0] = '0';
			ss[1] = '\0';
		}
		//输出结果
		printf( "%s", ss );
		si = strlen( s );
		if( si ){
			putchar( '.' );
			printf( "%s", s );
		}
		putchar( '\n' );
	}
	return 0;
}