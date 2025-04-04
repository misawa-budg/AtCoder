import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        int[] dp = new int[n + 5];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;

        for (int i = 0; i <= n + 4; i++) {
            if (i + 2 <= n + 4 && dp[i] != Integer.MAX_VALUE) {
                dp[i + 2] = Math.min(dp[i] + a, dp[i + 2]);
            }
            if (i + 5 <= n + 4 && dp[i] != Integer.MAX_VALUE) {
                dp[i + 5] = Math.min(dp[i] + b, dp[i + 5]);
            }
        }

        int ans = Integer.MAX_VALUE;
        for (int i = n; i <= n + 4; i++) {
            ans = Math.min(ans, dp[i]);
        }

        System.out.println(ans);
    }
}
