import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        final int MAX_HEIGHT = 1000, MAX_WIDTH = 1000;

        int H = Integer.parseInt(st.nextToken());
        int W = Integer.parseInt(st.nextToken());
        char[][] board = new char[MAX_HEIGHT][MAX_WIDTH];
        int minH = MAX_HEIGHT, maxH = 0, minW = MAX_WIDTH, maxW = 0;
        for (int i = 0; i < H; i++) {
            String line = br.readLine();
            for (int j = 0; j < W; j++) {
                char letter = line.charAt(j);
                board[i][j] = letter;

                if (letter == '#') {
                    minH = Math.min(minH, i);
                    maxH = Math.max(maxH, i);
                    minW = Math.min(minW, j);
                    maxW = Math.max(maxW, j);
                }
            }
        }

        for (int i = minH; i <= maxH; i++) {
            for (int j = minW; j <= maxW; j++) {
                if (board[i][j] == '.') {
                    System.out.println("No");
                    return;
                }
            }
        }

        System.out.println("Yes");

    }
}
