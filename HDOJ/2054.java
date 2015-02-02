////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-06 20:57:07
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 2054
////Problem Title: 
////Run result: Accept
////Run time:328MS
////Run memory:5740KB
//////////////////System Comment End//////////////////
import java.util.Scanner;
import java.math.BigDecimal;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		BigDecimal a, b;
		while(cin.hasNext()) {
			a = cin.nextBigDecimal();
			b = cin.nextBigDecimal();
			if(a.compareTo(b) == 0)
				System.out.println("YES");
			else System.out.println("NO");
		}
	}
}