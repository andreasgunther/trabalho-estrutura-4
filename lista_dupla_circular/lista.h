#pragma once
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define TIME 2   // tempo de exibicao de cada imagem
#define SIZE 100 // tamanho maximo dos rotulos

typedef struct Node {
    char label[SIZE];
    struct Node *prev;
    struct Node *next;
} Node;

void partialFrame();
int mainFrame();
void create(Node **head, char label[]);
void addBeg(Node **head, char label[]);
void addEnd(Node **head, char label[]);
void rmBeg(Node **head);
void rmEnd(Node **head);
void search(Node *head, char label[]);
void print01();
void print02();
void print03();
void show(Node *head);