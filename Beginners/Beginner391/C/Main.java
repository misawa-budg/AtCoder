import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        final int N = Integer.parseInt(st.nextToken());
        final int Q = Integer.parseInt(st.nextToken());

        int multipleBirdsCount = 0;
        StringBuilder sb = new StringBuilder();
        int[] positions = new int[N+1];
        int[] counters = new int[N+1];

        for (int i = 0; i < N+1; i++) {
            positions[i] = i;
            counters[i] = 1;
        }
        counters[0] = 0;

        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(br.readLine());
            int query = Integer.parseInt(st.nextToken());

            System.out.println();
            if (query == 1) {
                int bird = Integer.parseInt(st.nextToken());
                int nest = Integer.parseInt(st.nextToken());

                if (counters[positions[bird]] == 2) multipleBirdsCount--;
                counters[positions[bird]]--;

                positions[bird] = nest;

                counters[positions[bird]]++;
                if (counters[positions[bird]] == 2) multipleBirdsCount++;
            } else {
                System.out.println(multipleBirdsCount);
            }
        }
    }
}
