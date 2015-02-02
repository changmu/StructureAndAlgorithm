////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-04-27 17:24:03
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1753
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:5708KB
//////////////////System Comment End//////////////////
import java.util.Scanner;
import java.math.BigDecimal;
public class Main{
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		BigDecimal a, b;
		String c;
		while(cin.hasNext()){
			a = cin.nextBigDecimal();
			b = cin.nextBigDecimal();
			c = a.add(b).stripTrailingZeros().toPlainString();
			System.out.println(c);
		}
	}
}