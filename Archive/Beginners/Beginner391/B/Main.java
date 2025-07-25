import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        char[][] grid1 = new char[n][n];
        char[][] grid2 = new char[m][m];

        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            for (int j = 0; j < n; j++) {
                grid1[i][j] = line.charAt(j);
            }
        }

        for (int i = 0; i < m; i++) {
            String line = br.readLine();
            for (int j = 0; j < m; j++) {
                grid2[i][j] = line.charAt(j);
            }
        }

        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j <= n - m; j++) {
                if (grid1[i][j] == grid2[0][0]) {
                    boolean match = true;
                    for (int k = 0; k < m; k++) {
                        for (int l = 0; l < m; l++) {
                            if (grid1[i + k][j + l] != grid2[k][l]) {
                                match = false;
                                break;
                            }
                        }
                        if (!match) {
                            break;
                        }
                    }

                    if (match) {
                        System.out.println(String.format("%d %d", i + 1, j + 1));
                        return;
                    }
                }

            }
        }
        System.out.println("-1 -1");
        br.close();
    }
}
