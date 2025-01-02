import java.util.Scanner;
public class Solution {
	public static void main(String[] args) {
		int max;
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		n--;
		max = a;
		while(n-- > 0){
			a= sc.nextInt();
			if(a > max) max = a;
		}
		System.out.println(max);
		
	}
}
Download