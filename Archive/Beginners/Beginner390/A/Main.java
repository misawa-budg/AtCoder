import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        List<Integer> a = new ArrayList<>();
        while (st.hasMoreTokens()) {
            a.add(Integer.parseInt(st.nextToken()));
        }

        List<Integer> ans = Arrays.asList(1, 2, 3, 4, 5);

        for (int i = 0; i < 4; i++) {
            List<Integer> b = new ArrayList<>(a);
            Collections.swap(b, i, i + 1);
            if (b.equals(ans)) {
                System.out.println("Yes");
                return;
            }
        }

        System.out.println("No");
    }
}
