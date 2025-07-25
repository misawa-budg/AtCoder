import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int q = Integer.parseInt(br.readLine());

        long now = 0;
        int pastSnake = 0;
        List<Long> snake = new ArrayList<>();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < q; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String op = st.nextToken();

            if (op.equals("1")) {
                long length = Long.parseLong(st.nextToken());
                snake.add(now);
                now += length;
            } else if (op.equals("2")) {
                pastSnake++;
            } else {
                int index = Integer.parseInt(st.nextToken());
                index--;
                sb.append(snake.get(pastSnake + index) - snake.get(pastSnake)).append("\n");
            }
        }

        System.out.print(sb);
    }
}
