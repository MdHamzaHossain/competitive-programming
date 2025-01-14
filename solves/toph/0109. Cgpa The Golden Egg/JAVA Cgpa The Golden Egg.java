import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        for (int i = 1; i <= T; i++) {
            int n = sc.nextInt();
            double totalGrade = 0;
            double totalCred = 0;
            int failed = 0;
            while (n-- > 0) {
                {
                    double a = sc.nextDouble(), c = sc.nextDouble();
                    if (a < 40) {
                        failed++;
                        continue;
                    }
                    totalCred += c;
                    if (a < 40)
                        a = 0.0;
                    else if (a < 45)
                        a = 2.0;
                    else if (a < 50)
                        a = 2.25;
                    else if (a < 55)
                        a = 2.5;
                    else if (a < 60)
                        a = 2.75;
                    else if (a < 65)
                        a = 3.0;
                    else if (a < 70)
                        a = 3.25;
                    else if (a < 75)
                        a = 3.5;
                    else if (a < 80)
                        a = 3.75;
                    else
                        a = 4.00;
                    totalGrade += a * c;
                }

            }
            System.out.print("Case " + i + ": ");
            if (failed > 0) {
                System.out.print("Sorry, you have failed in " + failed + " course" + (failed > 1 ? "s" : "") + "!\n");
            } else
                System.out.printf("%.2f\n", (totalGrade / totalCred));

        }
    }
}