//
//  main.c
//  lesson6
//
//  Created by Александр Берлин on 14.10.2019.
//  Copyright © 2019 Александр Берлин. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int array[10] = {7, 12, 1, 8, 4, 9, 23, 5, 46, 14};
int i = 0;

// 1. Реализовать простейшую хэш-функцию.
//    На вход функции подается строка, на выходе сумма кодов символов.

int hash(char string[SIZE]) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
        sum += (int)string[i];
    return sum;
}

//2. Реализовать двоичное дерево поиска

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

Node* tree(int a, Node *parent) {
    Node* node;
    if (a == 0) {
        node = NULL;
    } else {
        node = (Node*) malloc(sizeof(Node));
        node->data = array[i++];
        node->left = tree((a / 2), node);
        node->right = tree((a - a / 2 - 1), node);
    }
    return node;
}

void printTree(Node *root) {
    if (root)
    {
        printf("%d", root->data);
        if (root->left || root->right)
        {
            printf("(");

            if (root->left)
                printTree(root->left);
            else
                printf("NULL");

            printf(",");

            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            
            printf(")");
        }
    }
}

void preOrderTravers(Node* root) {
    if (root) {
        printf("%d", root->data);
        printf("(");
        preOrderTravers(root->left);
        printf(",");
        preOrderTravers(root->right);
        printf(")");
    }
}

//   а) Добавить обход дерева различными способами;

void inOrderTravers(Node* root) {
    if (root) {
        preOrderTravers(root->left);
        printf("%d ", root->data);
        preOrderTravers(root->right);
    }
}

void postOrderTravers(Node* root) {
    if (root) {
        preOrderTravers(root->left);
        preOrderTravers(root->right);
        printf("%d ", root->data);
    }
}
//   б) Реализовать поиск в двоичном дереве поиска;

Node* search(Node* root, int value) {
    if (root) {
        if (root->data == value)
            return root;
        else {
            search(root->left, value);
            search(root->right, value);
        }
    } else
        return NULL;
    return root;
}

int main(int argc, const char * argv[]) {
    char string[SIZE] = { 0 };
    printf("Enter string: ");
    scanf("%s", string);
    printf("Hash: %d\n", hash(string));
    
    printf("\nTree:\n");
    Node *t = tree(10, NULL);
    printTree(t);
    printf("\nPreOrderTravers:\n");
    preOrderTravers(t);
    printf("\nSearch 5 in tree:\n");
    printf("%p", search(t, 5));
    printf("\n");
    return 0;
}
