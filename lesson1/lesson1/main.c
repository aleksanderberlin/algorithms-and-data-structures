//
//  main.c
//  lesson1
//
//  Created by Александр Берлин on 27/09/2019.
//  Copyright © 2019 Александр Берлин. All rights reserved.
//

#include <stdio.h>

int main() {
    float m, h;
    printf("Enter weigth: ");
    scanf("%f.0", &m);
    printf("Enter height: ");
    scanf("%f.0", &h);
    printf("Your body mass index is %.3f\n", m/(h*h));
    return 0;
}
