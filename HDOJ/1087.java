////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-27 20:18:59
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1087
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:5656KB
//////////////////System Comment End//////////////////
import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		final int maxn = 1002;
		int n, i, j, ans, tmp; 
		int[] dp = new int[maxn], arr = new int[maxn];
		while(true){
			n = cin.nextInt();
			if(n == 0) break;
			ans = arr[0] = dp[0] = cin.nextInt();
			for(i = 1; i < n; ++i){
				arr[i] = dp[i] = cin.nextInt();
				for(j = 0; j < i; ++j)
					if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + arr[i]);
				if(dp[i] > ans) ans = dp[i];
			}
			System.out.println(ans);
		}
		
	}

	public static int max(int a, int b){
		return a > b ? a : b;
	}
}