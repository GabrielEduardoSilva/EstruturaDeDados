//
//  desafio.c
//  TabelaHash
//
//  Created by Gabriel Eduardo on 11/11/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

struct HashNode {
    int key;
    char name[50];
    struct HashNode* next;
};

struct HashTable {
    struct HashNode* array[TABLE_SIZE];
};

int hash(int key) {
    return key % TABLE_SIZE;
}

struct HashTable* createHashTable(void) {
    struct HashTable* hashtable = (struct HashTable*)malloc(sizeof(struct HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashtable->array[i] = NULL;
    }
    return hashtable;
}

void insert(struct HashTable* hashtable, int key, const char* name) {
    int index = hash(key);

    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    newNode->key = key;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (hashtable->array[index] == NULL) {
        hashtable->array[index] = newNode;
    } else {
        struct HashNode* current = hashtable->array[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

const char* get(struct HashTable* hashtable, int key) {
    int index = hash(key);
    struct HashNode* current = hashtable->array[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->name;
        }
        current = current->next;
    }
    return "Aluno não encontrado";
}

int main(void) {
    struct HashTable* hashtable = createHashTable();

    for (int i = 0; i < 10; i++) {
        int matricula;
        char nome[50];
        
        printf("Informe a matrícula do aluno %d: ", i + 1);
        scanf("%d", &matricula);
        printf("Informe o nome do aluno %d: ", i + 1);
        scanf("%s", nome);

        insert(hashtable, matricula, nome);
    }

    int matricula_busca;
    printf("Informe a matrícula do aluno que deseja buscar: ");
    scanf("%d", &matricula_busca);

    const char* nome_aluno = get(hashtable, matricula_busca);
    printf("Nome do aluno com matrícula %d: %s\n", matricula_busca, nome_aluno);

    return 0;
}

