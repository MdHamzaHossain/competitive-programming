import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        // Scanner sc = new Scanner(System.in);
        int a = (new Scanner(System.in).nextInt());
        a++;
        int sum = 0;
        while (a-- > 0) {
            sum += a * a;
        }
        System.out.print(sum);
    }
}