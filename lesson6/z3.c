//
//  z3.c
//  lesson6
//
//  Created by Александр Берлин on 14.10.2019.
//  Copyright © 2019 Александр Берлин. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

//3. ***Разработать базу данных студентов из двух полей “Имя”, “Возраст”, “Табельный номер”,
//   в которой использовать все знания, полученные на уроках.
//   Считайте данные в двоичное дерево поиска.
//   Реализуйте поиск по какому-нибудь полю базы данных (возраст, вес)

typedef struct {
    char name[20];
    int age;
} Info;

typedef struct Node {
    int table_number;
    Info info;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

int i = 0;
Info students[SIZE] = {
    {"Alexey", 18},
    {"Aleksandr", 19},
    {"Anastasiya", 17},
    {"Igor", 20},
    {"Sofiya", 18},
};

Node* database(int a, Node *parent) {
    Node* node;
    if (a == 0) {
        node = NULL;
    } else {
        node = (Node*) malloc(sizeof(Node));
        node->table_number = i;
        memcpy(node->info.name, students[i].name, 20);
        node->info.age = students[i++].age;
        node->parent = parent;
        node->left = database((a / 2), node);
        node->right = database((a - a / 2 - 1), node);
    }
    return node;
}

void printTree(Node *root) {
    if (root)
    {
        printf("%d %s, age: %d\n", root->table_number, root->info.name, root->info.age);
        if (root->left)
            printTree(root->left);
        if (root->right)
            printTree(root->right);
    }
}

void search_by_age(Node* students, int age) {
    if (students) {
        if (students->info.age == age)
            printf("%d %s, age: %d\n", students->table_number,
            students->info.name, students->info.age);
        search_by_age(students->left, age);
        search_by_age(students->right, age);
        }
}

int main(int argc, char* argv[]) {
    Node *d = database(SIZE, NULL);
    int age;
    
    printTree(d);
    printf("\nEnter age to search: ");
    scanf("%d", &age);
    search_by_age(d, age);
    return 0;
}
