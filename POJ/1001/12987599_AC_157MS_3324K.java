import java.util.Scanner;
import java.math.BigDecimal;

public class Main{
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		BigDecimal a; int n; String str;
		while(cin.hasNext()){
			a = cin.nextBigDecimal();
			n = cin.nextInt();
			str = a.pow(n).stripTrailingZeros().toPlainString();			
			if(str.startsWith("0")) str = str.substring(1);
			System.out.println(str);
		}
	}
}