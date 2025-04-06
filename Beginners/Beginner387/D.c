#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_H 1000
#define MAX_W 1000

typedef struct {
    int y, x, d; // d: 0 = 横移動直前, 1 = 縦移動直前
} State;

int main(){
    int H, W;
    if(scanf("%d %d", &H, &W) != 2) return 1;

    char board[MAX_H+1][MAX_W+2];
    for(int i = 0; i < H; i++){
        scanf("%s", board[i]);
    }

    int start_y = -1, start_x = -1, goal_y = -1, goal_x = -1;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(board[i][j] == 'S'){
                start_y = i;
                start_x = j;
            }
            if(board[i][j] == 'G'){
                goal_y = i;
                goal_x = j;
            }
        }
    }

    static bool visited[MAX_H+1][MAX_W+1][2] = { false };
    static int cost[MAX_H+1][MAX_W+1][2];
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            cost[i][j][0] = -1;
            cost[i][j][1] = -1;
        }
    }

    int capacity = H * W * 2;
    State *queue = (State*)malloc(sizeof(State) * capacity);
    int front = 0, rear = 0;

    int init_moves[4][3] = {
        { 1,  0, 1},
        {-1,  0, 1},
        { 0,  1, 0},
        { 0, -1, 0}
    };
    for(int i = 0; i < 4; i++){
        int ny = start_y + init_moves[i][0];
        int nx = start_x + init_moves[i][1];
        int nd = init_moves[i][2];
        if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
        if(board[ny][nx] == '#') continue;
        if(!visited[ny][nx][nd]){
            visited[ny][nx][nd] = true;
            cost[ny][nx][nd] = 1;
            queue[rear].y = ny;
            queue[rear].x = nx;
            queue[rear].d = nd;
            rear++;
        }
    }

    int ans = -1;
    while(front < rear){
        State cur = queue[front++];
        int y = cur.y, x = cur.x, d = cur.d;
        if(y == goal_y && x == goal_x){
            ans = cost[y][x][d];
            break;
        }
        if(d == 1){ // 直前が縦なら横移動のみ可能
            int moves[2][2] = { {0, 1}, {0, -1} };
            for(int i = 0; i < 2; i++){
                int ny = y + moves[i][0];
                int nx = x + moves[i][1];
                int nd = 0; // 横移動
                if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
                if(board[ny][nx] == '#') continue;
                if(!visited[ny][nx][nd]){
                    visited[ny][nx][nd] = true;
                    cost[ny][nx][nd] = cost[y][x][1] + 1;
                    queue[rear].y = ny;
                    queue[rear].x = nx;
                    queue[rear].d = nd;
                    rear++;
                }
            }
        } else {
            int moves[2][2] = { {1, 0}, {-1, 0} };
            for(int i = 0; i < 2; i++){
                int ny = y + moves[i][0];
                int nx = x + moves[i][1];
                int nd = 1;
                if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
                if(board[ny][nx] == '#') continue;
                if(!visited[ny][nx][nd]){
                    visited[ny][nx][nd] = true;
                    cost[ny][nx][nd] = cost[y][x][0] + 1;
                    queue[rear].y = ny;
                    queue[rear].x = nx;
                    queue[rear].d = nd;
                    rear++;
                }
            }
        }
    }

    if(ans != -1){
        printf("%d\n", ans);
    } else {
        int a = cost[goal_y][goal_x][0];
        int b = cost[goal_y][goal_x][1];
        if(a == -1 && b == -1)
            printf("-1\n");
        else if(a == -1)
            printf("%d\n", b);
        else if(b == -1)
            printf("%d\n", a);
        else
            printf("%d\n", a < b ? a : b);
    }

    free(queue);
    return 0;
}
