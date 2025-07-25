import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            list.add(Integer.parseInt(st.nextToken()));
        }

        if (list.size() == 1) {
            System.out.println(1);
            return;
        } else if (list.size() == 2) {
            System.out.println(3);
            return;
        }

        List<Integer> arithmeticCount = new ArrayList<>();
        int streak = 2;
        int prevDiff = list.get(1) - list.get(0);
        arithmeticCount.add(1);
        arithmeticCount.add(2);
        for (int i = 2; i < N; i++) {
            int diff = list.get(i) - list.get(i - 1);
            if (diff == prevDiff) {
                streak++;
                arithmeticCount.add(streak);
            } else {
                streak = 2;
                arithmeticCount.add(streak);
                prevDiff = diff;
            }
        }

        long count = 0;
        for (int i = 0; i < arithmeticCount.size(); i++) {
            count += (long)arithmeticCount.get(i);
        }
        System.out.println(count);
    }
}
