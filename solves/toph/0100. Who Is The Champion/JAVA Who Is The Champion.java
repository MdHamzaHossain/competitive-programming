import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        System.out.print(n > m ? "Champion\nRunner up\n" : "Runner up\nChampion\n");

    }
}