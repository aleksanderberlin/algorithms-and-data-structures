//
//  lesson2.c
//  lesson2
//
//  Created by Александр Берлин on 30/09/2019.
//  Copyright © 2019 Александр Берлин. All rights reserved.
//
//1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
//
//2. Реализовать функцию возведения числа a в степень b:
//a. без рекурсии;
//b. рекурсивно;
//c. *рекурсивно, используя свойство чётности степени.
//
//3. Исполнитель Калькулятор преобразует целое число, записанное на экране. У исполнителя две команды, каждой команде присвоен номер:
//  1) Прибавь 1        2) Умножь на 2
//  Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза. Сколько существует программ, которые число 3 преобразуют в число 20? а) с использованием массива; б) с использованием рекурсии.

#include <stdio.h>
#include <stdlib.h>

#define START 3
#define END 20

void bintodec(unsigned int a) {
    if (a == 1) printf("Binary: 1");
    else {
        bintodec(a / 2);
        printf("%d", a % 2);
    }
}

int pow_no_recursion(int a, int b) {
    int result = 1;
    for(int i = 0; i < b; i++) result *= a;
    return result;
}

int pow_with_recursion(int a, int b) {
    if (b == 1) return a;
    else return a * pow_with_recursion(a, b-1);
}

int pow_with_double_degree(int a, int b) {
    if (b == 1) return a;
    else if (b % 2 == 0) return pow_with_double_degree(a * a, b / 2);
    else return a * pow_with_double_degree(a, b-1);
}

int calculator_with_recursion(int num) {
    if (num == END) return 1;
    else if (num > END) return 0;
    else return calculator_with_recursion(num + 1) + calculator_with_recursion(num * 2);
}

int main(int argc, const char * argv[]) {
    unsigned int num;
    int base, degree;
    printf("Z. 1\nEnter decimal number: ");
    scanf("%d", &num);
    bintodec(num);
    
    printf("\n\nZ. 2\nEnter number and degree: ");
    scanf("%d %d", &base, &degree);
    printf("%d^%d (no recursion) = %d\n", base, degree, pow_no_recursion(base, degree));
    printf("%d^%d (with recursion) = %d\n", base, degree, pow_with_recursion(base, degree));
    printf("%d^%d (with double degree) = %d\n", base, degree, pow_with_double_degree(base, degree));
    printf("\nZ.3\nAmount of ways (with recursion): %d\n", calculator_with_recursion(START));
    
    return 0;
}
