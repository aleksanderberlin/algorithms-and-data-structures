//
//  lesson1z9.c
//  lesson1
//
//  Created by Александр Берлин on 27/09/2019.
//  Copyright © 2019 Александр Берлин. All rights reserved.
//

#include <stdio.h>

int main(int argc, char* argv[]) {
    unsigned int n, k;
    int div = 0;
    printf("Enter two numbers to divide (N and K): ");
    scanf("%d %d", &n, &k);
    while (n > k) {
        div += 1;
        n -= k;
    }
    printf("N divide K = %d (quotioent) and %d (remainder).\n", div, n);
    return 0;
}
