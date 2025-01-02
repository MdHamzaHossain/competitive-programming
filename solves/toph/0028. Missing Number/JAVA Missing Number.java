import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(),
                a = sc.nextInt(),
                b = sc.nextInt(),
                c = sc.nextInt();

        System.out.println((t - a - b - c));

    }
}