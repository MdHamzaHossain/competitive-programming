import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            float W = sc.nextFloat(), G = sc.nextFloat();
            System.out.printf("%.4f\n", (W / 2 - G / 2));
        }

    }
}