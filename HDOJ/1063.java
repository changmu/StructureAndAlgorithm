////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-04-05 08:32:47
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1063
////Problem Title: 
////Run result: Accept
////Run time:359MS
////Run memory:6088KB
//////////////////System Comment End//////////////////
import java.util.Scanner;
import java.math.BigDecimal;

public class Main{
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		BigDecimal r;
		int n;
		String str;
		while(cin.hasNext()){
			r = cin.nextBigDecimal();
			n = cin.nextInt();
			str = r.pow(n).stripTrailingZeros().toPlainString();
			if(str.startsWith("0")) str = str.substring(1);
			System.out.println(str);
		}
	}
}