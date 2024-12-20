import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        n -= 2;
        System.out.println(((n > 1 && n % 2 == 0) ? "YES" : "NO"));
    }
}