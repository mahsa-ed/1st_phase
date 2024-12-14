#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"
#include "file.h"
#define MAXSIZE 17

char Map[MAXSIZE][MAXSIZE];
struct coordinates { //*
    int x;
    int y;
}; //*

int main(void) {
    srand (time (NULL) ) ;
    int size;
    int Vcount, Xcount, Ccount;
    int i, j, k;
    struct coordinates castle[10];
    struct coordinates village[15];


    printf("please enter the map size ");
    scanf("%d", &size);
    int goldRate[size][size], foodRate[size][size], valu[size][size];
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            Map[i][j] = '1';
        }
    }

    printf("please enter the number of castles and coordinates ");
    scanf("%d", &Ccount); //قرار گیری قلمرو ها
    for (k = 1; k <= Ccount; k++) {
        scanf("%d %d", &i, &j);
        Map[i - 1][j - 1] = 'C';
        castle[k-1].x= i-1 ; //*
        castle[k-1].y= j-1 ; //*
    }

    printf("please enter the number of villages, coordinates,gold rate and food rate ");
    scanf("%d", &Vcount); //قرار گیری روستا ها و نرخ تولید
    for (k = 1; k <= Vcount; k++) {
        scanf("%d %d", &i, &j);
        Map[i - 1][j - 1] = 'V';
        scanf("%d %d", &goldRate[i - 1][j - 1], &foodRate[i - 1][j - 1]);
        village[k-1].x = i-1;
        village[k-1].y = j-1;
    }

    printf("please enter the number of blocked houses and coordinates ");
    scanf("%d", &Xcount);//قرار گیری خانه های مسدود
    for (k = 1; k <= Xcount; k++) {
        scanf("%d %d", &i, &j);
        Map[i - 1][j - 1] = 'X';
    }

    for (i = 0; i < size; i++) { //ارزش دادن به خانه های خالی با عدد تصادفی از1 تا 4
        for (j = 0; j < size; j++) {
            if (Map[i][j] == '1') {
                valu[i][j] = generate_number();
            }
        }
    }
    printMap(size,Map);
}