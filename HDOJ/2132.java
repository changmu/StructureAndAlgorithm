////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-06 20:30:51
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 2132
////Problem Title: 
////Run result: Accept
////Run time:2203MS
////Run memory:12624KB
//////////////////System Comment End//////////////////
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	static final int maxn = 100005;
	static BigInteger[] arr = new BigInteger[maxn];

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		arr[0] = BigInteger.ZERO;
		BigInteger tmp;
		for(int i = 1; i <= 100000; ++i) {
			tmp = BigInteger.valueOf(i);
			if(i % 3 == 0)
				arr[i] = arr[i-1].add(tmp.multiply(tmp).multiply(tmp));
			else arr[i] = arr[i-1].add(tmp);
		}
		int n;
		while(true) {
			n = cin.nextInt();
			if(n < 0) break;
			System.out.println(arr[n]);
		}
	}
}