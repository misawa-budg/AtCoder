#include <stdio.h>
#include <stdlib.h>

#define MAX_H 10
#define MAX_W 10

int H, W, K;
char grid[MAX_H][MAX_W];
int total_paths = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int steps, int visited[MAX_H][MAX_W]) {
    if (steps == K) {
        total_paths++;
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= H || ny < 0 || ny >= W)
            continue;
        if (grid[nx][ny] == '#')
            continue;
        if (visited[nx][ny])
            continue;

        visited[nx][ny] = 1;
        dfs(nx, ny, steps + 1, visited);
        visited[nx][ny] = 0; // バックトラック
    }
}

int main(){
    scanf("%d %d %d", &H, &W, &K);
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            scanf(" %c", &grid[i][j]);
        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(grid[i][j] == '.') {
                int visited[MAX_H][MAX_W] = {0};
                visited[i][j] = 1;
                dfs(i, j, 0, visited);
            }
        }
    }

    printf("%d\n", total_paths);

    return 0;
}
