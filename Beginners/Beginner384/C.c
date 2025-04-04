#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int index;
    int binaryIndex[5];
    char name[6];
    int point;
} Member;

void index_to_binary(int index, int binaryIndex[5]) {
    for (int i = 0; i < 5; i++) {
        binaryIndex[i] = index % 2;
        index /= 2;
    }
}


int main() {
    int points[5];
    scanf("%d %d %d %d %d", &points[0], &points[1], &points[2], &points[3], &points[4]);

    Member member[31];
    for (int i = 0; i < 31; i++) {
        member[i].index = i + 1;
        index_to_binary(i + 1, member[i].binaryIndex);
        member[i].point = 0;

        char name[6] = "ABCDE";
        int count = 0;

        for (int j = 0; j < 5; j++) {
            if (member[i].binaryIndex[j] == 1) {
                member[i].point += points[j];
                member[i].name[count++] = name[j];
            }
        }
        member[i].name[count] = '\0';
    }

    for (int i = 0; i < 31 - 1; i++) {
        for (int j = i + 1; j < 31; j++) {
            if (member[i].point < member[j].point) {
                Member temp = member[i];
                member[i] = member[j];
                member[j] = temp;
            } else if (member[i].point == member[j].point) {
                if (strcmp(member[i].name, member[j].name) > 0) {
                    Member temp = member[i];
                    member[i] = member[j];
                    member[j] = temp;
                }
            }
        }
    }

    for (int i = 0; i < 31; i++) {
        printf("%s\n", member[i].name);
    }

    return 0;
}
