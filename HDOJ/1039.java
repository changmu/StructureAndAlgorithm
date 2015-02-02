////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-25 21:28:07
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1039
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:4884KB
//////////////////System Comment End//////////////////
import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		final String str1 = " is acceptable.", str2 = " is not acceptable.";
		String str;
		while(true){
			str = cin.next();
			if(str.equals("end")) break;
			System.out.print('<' + str +'>');
			if(check(str)) System.out.println(str1);
			else System.out.println(str2);
		}
	}

	public static boolean check(String str){
		int a = 0, b = 0, c = 0;
		boolean ok = false; char ch;
		for(int i = 0; i < str.length(); ++i){
			ch = str.charAt(i);
			if(isVowel(ch)){
				ok = true; b = 0;
				if(++a == 3) return false;
			}else{
				a = 0;
				if(++b == 3) return false;
			}
			if(i != 0 && ch == str.charAt(i-1) && ch != 'e' && ch != 'o')
				return false;
		}
		return ok;
	}

	public static boolean isVowel(char ch){
		if(ch == 'a' || ch == 'e' || ch == 'i'
			 || ch == 'o'|| ch == 'u') return true;
		return false;
	}
}