//
//  main.c
//  TabelaHash
//
//  Created by Gabriel Eduardo on 11/11/23.
//

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100 // tamanho da tabela  hash

struct HashNode {
    int key;
    int value;
    struct HashNode* next;
};

struct HashTable {
    struct HashNode* array[TABLE_SIZE];
};

int hash(int key){
    return key % TABLE_SIZE;
};

struct HashTable* createHashTable(void) {
    struct HashTable* hashtable = (struct HashTable*)malloc(sizeof(struct HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashtable->array[i] = NULL;
    }
    return hashtable;
}

// Funçao para inserir um par chave-valor na tabela hash
void insert(struct HashTable* hashtable, int key, int value) {
    int index = hash(key);
    
    // Criar um novo nó para armazenar o par chave-valor
    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    
    // Verificar se já exite um nó na posição da tabela hash
    if (hashtable->array[index] == NULL) {
        hashtable->array[index] = newNode;
    } else {
        // Caso haja um nó na posição, encadeie o novo nó
        struct HashNode* current = hashtable->array[index];
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int get(struct HashTable* hashtable, int key) {
    int index = hash(key);
    struct HashNode* current = hashtable->array[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Valor não encontrado
}

int main(void) {
    struct HashTable* hashtable = createHashTable();
    
    insert(hashtable, 1, 42);
    insert(hashtable, 2, 56);
    insert(hashtable, 101, 72);
    
    int value = get(hashtable, 2);
    if (value != -1) {
        printf("Valor associado à chave 2: %d\n", value);
    } else {
        printf("Chave 2 não encontrada na tabela hash.\n");
    }
    
    return 0;
}
