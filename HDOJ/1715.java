////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-04-05 09:21:44
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1715
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:5892KB
//////////////////System Comment End//////////////////
import java.util.Scanner;
import java.math.BigInteger;

public class Main{
	public static void main(String[] args){
		final int max = 1001;
		Scanner cin = new Scanner(System.in);
		BigInteger f[] = new BigInteger[max];
		int i; f[1] = f[2] = BigInteger.ONE;
		for(i = 3; i != max; ++i)
			f[i] = f[i - 1].add(f[i - 2]);
		int n = cin.nextInt();
		while(n-- > 0){
			i = cin.nextInt();
			System.out.println(f[i]);
		}
	}
}