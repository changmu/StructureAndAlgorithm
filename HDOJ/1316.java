////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-04-05 09:09:45
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1316
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:5640KB
//////////////////System Comment End//////////////////
import java.util.Scanner;
import java.math.BigInteger;

public class Main{
	static final int max = 500;
	static BigInteger[] arr = new BigInteger[max];
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);		
		BigInteger a, b;		
		int i, l, r;
		arr[1] = BigInteger.ONE; arr[2] = BigInteger.valueOf(2);
		for(i = 3; i != max; ++i)
			arr[i] = arr[i - 1].add(arr[i - 2]);
		while(true){
			a = cin.nextBigInteger();
			b = cin.nextBigInteger();
			if(a.compareTo(BigInteger.ZERO) == 0 
				&& b.compareTo(BigInteger.ZERO) == 0) break;
			l = binarySearch1(a);
			r = binarySearch2(b);
			System.out.println(r - l);
		}
	}
	
	public static int binarySearch1(BigInteger n){
		int i;
		for(i = 1; i < max; ++i)
			if(arr[i].compareTo(n) >= 0) return i;
		return 0;
	}
	
	public static int binarySearch2(BigInteger n){
		int i;
		for(i = 1; i < max; ++i)
			if(arr[i].compareTo(n) > 0) return i;
		return 0;
	}
}