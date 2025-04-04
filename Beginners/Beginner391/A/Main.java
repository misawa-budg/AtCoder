import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = br.readLine();

        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            if (c == 'N') {
                c = 'S';
            } else if (c == 'S') {
                c = 'N';
            } else if (c == 'E') {
                c = 'W';
            } else if (c == 'W') {
                c = 'E';
            }
            System.out.print(c);
        }
        System.out.println();
    }
}
