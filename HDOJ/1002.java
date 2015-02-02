////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-02 15:13:07
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1002
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:5760KB
//////////////////System Comment End//////////////////
import java.util.Scanner;
import java.math.BigInteger;
public class Main{
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		BigInteger a, b;
		int t, i;
		t = cin.nextInt();
		for(i = 1; i <= t; ++i){
			a = cin.nextBigInteger();
			b = cin.nextBigInteger();
			System.out.println("Case " + i + ":");	
			System.out.print(a + " + " + b + " = ");
			System.out.println(a.add(b));
			if(i != t) System.out.println("");
		}
	}	
}