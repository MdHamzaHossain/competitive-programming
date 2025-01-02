import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt(), M = sc.nextInt();
        double angle = (60 * (double) H - 11 * (double) M) / 2;
        if (angle > 180)
            angle = 360.000 - angle;
        System.out.printf("%f", angle);
        return;
    }
}