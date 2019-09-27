//
//  lesson1z3.c
//  lesson1
//
//  Created by Александр Берлин on 27/09/2019.
//  Copyright © 2019 Александр Берлин. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {
    float a, b, c, x1, x2;
    printf("Enter a, b and c:\n");
    scanf("%f %f %f", &a, &b, &c);
    float d = b * b - 4 * a * c;
    if (d > 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        printf("Equation has 2 roots: %f and %f\n", x1, x2);
    } else if (d == 0) {
        x1 = -b / (2 * a);
        printf("Equation has 1 root: %f\n", x1);
    } else printf("Equation has no roots.\n");
    return 0;
}
