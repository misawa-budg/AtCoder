import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        long target = scan.nextLong();

        long factorial = 1;
        for (int i = 1; i <= target; i++) {
            factorial *= i;
            if (factorial == target) {
                System.out.println(i);
                break;
            }
        }
    }
}
