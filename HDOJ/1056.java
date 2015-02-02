////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-26 11:51:50
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1056
////Problem Title: 
////Run result: Accept
////Run time:1421MS
////Run memory:5884KB
//////////////////System Comment End//////////////////
import java.util.Scanner;

public class Main{
	static final int maxn = 300;
	static double[] len = new double[maxn];
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);		
		double a = 0.0;
		for(int i = 1; i < maxn; ++i){
			a += 1.0 / (i + 1.0);
			len[i] = a;
		}
		while(true){
			a = cin.nextDouble();
			if(a == 0.00) break;
			System.out.println(bSearch(a) + " card(s)");
		}
	}

	public static int bSearch(double a)
	{
		int l = 1, r = maxn - 1, mid;
		while(l <= r){
			mid = (l + r) >> 1;
			if(len[mid] < a) l = mid + 1;
			else if(len[mid] > a) r = mid - 1;
			else return mid;
		}
		return l;
	}
}