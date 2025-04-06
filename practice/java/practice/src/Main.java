import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        int[][][] box = new int[n][n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                st = new StringTokenizer(br.readLine());
                for (int k = 0; k < n; k++) {
                    box[i][j][k] = Integer.parseInt(st.nextToken());
                }
            }
        }
        // 3次元の立体において、対角線上の要素の和の最大を求める

        int result = Integer.MIN_VALUE;

        // 縦方向
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                for (int k = 0; k < n; k++) {
                    sum += box[k][i][j];
                }
                result = Math.max(result, sum);
            }
        }

        // 横方向
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                for (int k = 0; k < n; k++) {
                    sum += box[i][k][j];
                }
                result = Math.max(result, sum);
            }
        }

        // 奥行方向
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                for (int k = 0; k < n; k++) {
                    sum += box[i][j][k];
                }
                result = Math.max(result, sum);
            }
        }

        // xy平面での斜め方向（高さ方向は固定）
        for (int i = 0; i < n; i++) {
            int sum1 = 0;
            int sum2 = 0;
            for (int j = 0; j < n; j++) {
                sum1 += box[i][j][j];
                sum2 += box[i][j][n - j - 1];
            }
            result = Math.max(result, Math.max(sum1, sum2));
        }

        // xz平面での斜め方向（横方向は固定）
        for (int i = 0; i < n; i++) {
            int sum1 = 0;
            int sum2 = 0;
            for (int j = 0; j < n; j++) {
                sum1 += box[j][i][j];
                sum2 += box[j][i][n - j - 1];
            }
            result = Math.max(result, Math.max(sum1, sum2));
        }

        // yz平面での斜め方向（縦方向は固定）
        for (int i = 0; i < n; i++) {
            int sum1 = 0;
            int sum2 = 0;
            for (int j = 0; j < n; j++) {
                sum1 += box[j][j][i];
                sum2 += box[j][n - j - 1][i];
            }
            result = Math.max(result, Math.max(sum1, sum2));
        }

        // 完全な対角線（3次元空間を貫く）
        int sum1 = 0;
        int sum2 = 0;
        int sum3 = 0;
        int sum4 = 0;
        for (int i = 0; i < n; i++) {
            sum1 += box[i][i][i];               // (0,0,0) から (n-1,n-1,n-1) への対角線
            sum2 += box[i][i][n - i - 1];       // (0,0,n-1) から (n-1,n-1,0) への対角線
            sum3 += box[i][n - i - 1][i];       // (0,n-1,0) から (n-1,0,n-1) への対角線
            sum4 += box[i][n - i - 1][n - i - 1]; // (0,n-1,n-1) から (n-1,0,0) への対角線
        }
        result = Math.max(result, Math.max(Math.max(sum1, sum2), Math.max(sum3, sum4)));

        System.out.println(result);
        br.close();
    }
}
