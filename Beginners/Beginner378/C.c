#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 524287

typedef struct {
    int key;
    int value;
} HashEntry;

typedef struct {
    HashEntry *table;
} HashMap;

unsigned int hash(int key) {
    return ((unsigned int)key) % TABLE_SIZE;
}

HashMap* createHashMap() {
    HashMap *map = malloc(sizeof(HashMap));
    map->table = malloc(sizeof(HashEntry) * TABLE_SIZE);
    for(int i = 0; i < TABLE_SIZE; i++) {
        map->table[i].key = -1;
        map->table[i].value = -1;
    }
    return map;
}

void put(HashMap *map, int key, int value) {
    unsigned int idx = hash(key);
    while(map->table[idx].key != -1 && map->table[idx].key != key) {
        idx = (idx + 1) % TABLE_SIZE;
    }
    map->table[idx].key = key;
    map->table[idx].value = value;
}

int get(HashMap *map, int key) {
    unsigned int idx = hash(key);
    while(map->table[idx].key != -1) {
        if(map->table[idx].key == key) return map->table[idx].value;
        idx = (idx + 1) % TABLE_SIZE;
    }
    return -1;
}

int main(){
    int N;
    scanf("%d", &N);
    int *A = malloc(sizeof(int) * N);
    int *B = malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++) scanf("%d", &A[i]);
    HashMap *map = createHashMap();
    for(int i = 0; i < N; i++) {
        B[i] = get(map, A[i]);
        put(map, A[i], i + 1);
    }
    if(N > 0){
        printf("%d", B[0]);
        for(int i = 1; i < N; i++) printf(" %d", B[i]);
        printf("\n");
    }
    free(A);
    free(B);
    free(map->table);
    free(map);
    return 0;
}
