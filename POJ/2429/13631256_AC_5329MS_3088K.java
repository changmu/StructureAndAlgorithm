import java.util.Scanner;

public class Main {
	static long gcd(long a, long b) {
		long c;
		while(b != 0) {
			c = a % b;
			a = b;
			b = c;
		}
		return a;
	}

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		long a, b, c, i;
		while(cin.hasNext()) {
			a = cin.nextLong();
			b = cin.nextLong();
			c = b / a;
			for(i = (long)Math.sqrt(c); i > 0; --i)
				if(c % i == 0 && gcd(i, c / i) == 1) {
					System.out.println(i*a + " " + c/i*a);
					break;
				}
		}
	}
}