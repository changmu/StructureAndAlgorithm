////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-28 17:06:44
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1250
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:12112KB
//////////////////System Comment End//////////////////
import java.util.Scanner;
import java.math.BigInteger;

public class Main{
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		BigInteger a, b, c, d;
		BigInteger[] arr = new BigInteger[10000];
		arr[1] = arr[2] = arr[3] = arr[4] = BigInteger.ONE;
		arr[5] = BigInteger.valueOf(4);
		for(int i = 6; i < 10000; ++i)
			arr[i] = arr[i-1].add(arr[i-2]).add(arr[i-3]).add(arr[i-4]);
		int n;
		while(cin.hasNext()){
			n = cin.nextInt();
			System.out.println(arr[n]);
		}
	}
}