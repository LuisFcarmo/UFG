#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ELEMENTS 10100
#define TABLE_SIZE 10103 

int colisões = 0;
int hashTable[TABLE_SIZE];

void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = 0;
    }
}

int hash(int key) {
    return key % TABLE_SIZE;
}

void insertIntoTable(int value) {
    int index = hash(value);
    int i = 0;
    int newIndex;
    while (1) {
        newIndex = (index + i * i) % TABLE_SIZE;
        if (hashTable[newIndex] == 0) {
            hashTable[newIndex] = value;
            break;
        }
        colisões++;
        i++;
        if (i == TABLE_SIZE) {
            break;
        }
    }
}

int search(int value, int *steps) {
    int index = hash(value);
    int i = 0;
    int newIndex;
    *steps = 0;
    while (1) {
        newIndex = (index + i * i) % TABLE_SIZE;
        (*steps)++;
        if (hashTable[newIndex] == value) {
            return hashTable[newIndex];
        }
        if (hashTable[newIndex] == 0 || *steps >= TABLE_SIZE) {
            return 0;
        }
        i++;
    }
}

void printTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index = %d, Value = %d\n", i, hashTable[i]);
    }
}

int main() {
    initTable();
    
    FILE *file = fopen("numerosaleatorios.txt", "r");
    if (file == NULL) {
        return 1;
    }

    int value;
    while (fscanf(file, "%d", &value) != EOF) {
        insertIntoTable(value);
    }
    fclose(file);

    file = fopen("checkin.txt", "r");
    if (file == NULL) {
        return 1;
    }

    clock_t start, end;
    double cpu_time_used;
    int steps;
    while (fscanf(file, "%d", &value) != EOF) {
        start = clock();
        int found = search(value, &steps);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        if (found) {
            printf("Valor %d encontrado em %d passos, tempo: %f segundos\n", value, steps, cpu_time_used);
        } else {
            printf("Valor %d não encontrado, tempo: %f segundos\n", value, cpu_time_used);
        }
    }
    
    fclose(file);
    printf("Total de colisões: %d\n", colisões);
    return 0;
}
