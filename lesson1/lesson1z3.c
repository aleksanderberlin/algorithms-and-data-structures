//
//  less1z2.c
//  lesson1
//
//  Created by Александр Берлин on 27/09/2019.
//  Copyright © 2019 Александр Берлин. All rights reserved.
//

#include <stdio.h>

int main(int argc, char* argv[]) {
    int a, b;
    printf("Enter A and B:\n");
    scanf("%d %d", &a, &b);
    printf("A = %d, B = %d\n", a, b);
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
    printf("A = %d, B = %d\n", a, b);
    return 0;
}
