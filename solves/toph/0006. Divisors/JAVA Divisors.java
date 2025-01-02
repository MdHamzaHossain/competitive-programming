import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        int A = new Scanner(System.in).nextInt();
        for (int i = 1; i <= A; i++) {
            if (A % i == 0)
                System.out.println(i);
        }
    }
}