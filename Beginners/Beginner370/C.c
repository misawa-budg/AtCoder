#include <stdio.h>
#include <string.h>

int main() {
    char s[1001], t[1001];
    scanf("%s", s);
    scanf("%s", t);

    char ans[10000][1001]; // 結果を格納する配列
    int sz = 0;
    int n = strlen(s);

    while (strcmp(s, t) != 0) {
        char nxt[1001];
        // nxtを'n'個の'z'で初期化
        for (int i = 0; i < n; i++) nxt[i] = 'z';
        nxt[n] = '\0';

        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                char tmp[1001];
                strcpy(tmp, s);
                tmp[i] = t[i];
                // lex最小の文字列を選択
                if (strcmp(tmp, nxt) < 0) {
                    strcpy(nxt, tmp);
                }
            }
        }
        // 結果を保存
        strcpy(ans[sz], nxt);
        sz++;
        // sを更新
        strcpy(s, nxt);
    }

    // 結果を出力
    printf("%d\n", sz);
    for (int i = 0; i < sz; i++) {
        printf("%s\n", ans[i]);
    }

    return 0;
}
