//
//  lesson1z7.c
//  lesson1
//
//  Created by Александр Берлин on 27/09/2019.
//  Copyright © 2019 Александр Берлин. All rights reserved.
//

#include <stdio.h>

int main(int argc, char* argv[]) {
    int x1 = 1, y1 = 1, x2 = 1, y2 = 1;
    do {
        if (x1 < 1 || x1 > 8 || y1 < 1 || y1 > 8) printf("Incorrect coordinates. Try again.\n");
        printf("Enter coordinates (x and y) of 1st dot: ");
        scanf("%d %d", &x1, &y1);
    } while(x1 < 1 || x1 > 8 || y1 < 1 || y1 > 8);
    do {
        if (x2 < 1 || x2 > 8 || y2 < 1 || y2 > 8) printf("Incorrect coordinates. Try again.");
        printf("Enter coordinates (x and y) of 2nd dot: ");
        scanf("%d %d", &x2, &y2);
    } while(x2 < 1 || x2 > 8 || y2 < 1 || y2 > 8);
    if ((x1 + y1) % 2 == (x2 + y2) % 2) printf("Dots have same colour.\n");
    else printf("Dots don't have same colour.\n");
    return 0;
}
