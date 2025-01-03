import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        int n = new Scanner(System.in).nextInt();
        System.out.printf("%s\n",
                ((n < 1582 && n % 4 == 0) || (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0))
                        ? "I can participate in LCPC"
                        : "I have to travel back to the past"));

    }

}