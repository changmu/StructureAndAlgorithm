////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-12-14 20:38:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4135
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1092KB
//////////////////System Comment End//////////////////
/*
** T¡Á¨¦&Ecirc;&yacute;&frac34;&Yacute;&pound;&not;&Ccedil;¨®¡¤&para;&Icirc;¡ì[u, v]&Auml;&Uacute;&cedil;¨²n&raquo;&yen;&Ouml;&Ecirc;&micro;&Auml;&Ecirc;&yacute;&micro;&Auml;&cedil;&ouml;&Ecirc;&yacute; 
*/
#include <stdio.h>
#include <string.h>

typedef __int64 LL;

int p[12], k, T, que[10000], id;
// &sup1;&sup1;&frac12;¡§&Euml;¨´&Oacute;&ETH;&cedil;¨²n&sup2;&raquo;&raquo;&yen;&Ouml;&Ecirc;&micro;&Auml;&Ocirc;&ordf;&Euml;&Oslash;&frac14;&macr;&ordm;&Iuml; 
void getp(LL n) { // &raquo;&ntilde;&micro;&Atilde;n&micro;&Auml;&Euml;¨´&Oacute;&ETH;&Ouml;&Ecirc;&Ograve;¨°&Ecirc;&yacute;&pound;&not;&Iuml;¨¤&micro;¡À&Oacute;&Uacute;&raquo;&ntilde;&micro;&Atilde;&Egrave;&Yacute;&sup3;&acirc;&frac14;&macr;&ordm;&Iuml;&Ouml;&ETH;&micro;&Auml;&cedil;¡Â&cedil;&ouml;&Ocirc;&shy;¡Á&Oacute;&frac14;&macr;&ordm;&Iuml; 
    int i, j, t; k = 0;
    for (i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            p[k++] = i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) p[k++] = n; // ¡¤&Agrave;&Ouml;&sup1;&Ouml;&icirc;&Egrave;&ccedil;n&Icirc;&ordf;34&Ecirc;¡À&Acirc;&copy;&micro;&ocirc;&Ouml;&Ecirc;&Ograve;¨°¡Á&Oacute;17&micro;&Auml;&Ccedil;¨¦&iquest;&ouml;
	/* &Ouml;&Aacute;&acute;&Euml;&pound;&not;n&micro;&Auml;&Euml;¨´&Oacute;&ETH;&Ouml;&Ecirc;&Ograve;¨°¡Á&Oacute;¡¤&Ouml;&frac12;&acirc;&Iacute;¨º&sup3;&Eacute;&pound;&not;&Ograve;&Ocirc;&Iuml;&Acirc;&Oacute;&Eacute;&cedil;¡Â&cedil;&ouml;&Ocirc;&shy;¡Á&Oacute;&frac14;&macr;&ordm;&Iuml;&sup1;&sup1;&frac12;¡§&cedil;&acute;&ordm;&Iuml;&frac14;&macr;&ordm;&Iuml; */
	id = 0;
	que[id++] = -1;
    for (i = 0; i < k; ++i) {
        t = id;
        for (j = 0; j < t; ++j)
            que[id++] = p[i] * que[j] * -1;
    }
}
// 
LL nop(LL m) {
    LL sum = 0;
    int i;
    for (i = 1; i < id; ++i)
    	sum += m / que[i];
    return sum;
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    LL u, v, n;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        printf("Case #%d: ", cas);
        scanf("%I64d%I64d%I64d", &u, &v, &n);
        getp(n);
        printf("%I64d\n", v - nop(v) - u + 1 + nop(u - 1));
    }
    return 0;
}