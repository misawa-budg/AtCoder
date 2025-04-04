import java.util.*;
import java.io.*;
import java.math.BigDecimal;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        List<Long> list = new ArrayList<>();
        while (st.hasMoreTokens()) {
            list.add(Long.parseLong(st.nextToken()));
        }

        for (int i = 0; i < N - 2; i++) {
            if (list.get(i+1) * list.get(i+1) != list.get(i) * list.get(i + 2)) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}
