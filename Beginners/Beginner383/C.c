#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXHW 1000

typedef struct {
    int y, x;
} Point;

int main() {
    int H, W, D;
    scanf("%d %d %d", &H, &W, &D);

    static char office[MAXHW][MAXHW+1];
    for (int i = 0; i < H; i++) {
        scanf("%s", office[i]);
    }

    static int dist[MAXHW][MAXHW];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            dist[i][j] = -1;
        }
    }

    static Point queue[MAXHW * MAXHW];
    int front = 0, rear = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (office[i][j] == 'H') {
                dist[i][j] = 0;
                queue[rear].y = i;
                queue[rear].x = j;
                rear++;
            }
        }
    }

    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};

    while (front < rear) {
        Point p = queue[front++];
        int cy = p.y;
        int cx = p.x;
        int d_now = dist[cy][cx];

        if (d_now == D) continue;

        for (int k = 0; k < 4; k++) {
            int ny = cy + dy[k];
            int nx = cx + dx[k];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if (office[ny][nx] == '#') continue;
            if (dist[ny][nx] == -1) {
                dist[ny][nx] = d_now + 1;
                queue[rear].y = ny;
                queue[rear].x = nx;
                rear++;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (dist[i][j] != -1 && office[i][j] != '#') {
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}
