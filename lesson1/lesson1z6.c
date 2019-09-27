//
//  lesson1z4.c
//  lesson1
//
//  Created by Александр Берлин on 27/09/2019.
//  Copyright © 2019 Александр Берлин. All rights reserved.
//

#include <stdio.h>

int main(int argc, char* argv[]) {
    int age = 1;
    do {
        if ((age < 1) || (age > 150)) printf("Incorrect number. Try again.\n");
        printf("Enter your age: ");
        scanf("%d", &age);
    } while ((age < 1) || (age > 150));
    if (age <= 20 && age == 1) printf("%d год.\n", age);
    else if (age <= 20 && age >= 2 && age <= 4) printf("%d года.\n", age);
    else if (age >= 5 && age <= 20) printf("%d лет.\n", age);
    else if (age > 20 && age % 10 == 1) printf("%d год.\n", age);
    else if (age > 20 && (age % 10 == 2 || age % 10 == 3 || age % 10 == 4)) printf("%d года.\n", age);
    else if (age > 20 && (age % 10 == 5 || age % 10 == 6 || age % 10 == 7 || age % 10 == 8 || age % 10 == 9 || age % 10 == 0)) printf("%d лет.\n", age);
    return 0;
}
