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

typedef struct {
    int soldiers;
    int goldrate;
    int foodrate;
    int workers;
    int gold;
    int food;
}Ruler;

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
    rulers.workers=1;
    rulers.goldrate=5;
        while (1) {
        int choise;
        printf("MENU:\n");
        printf("0.Exit\n");
        printf("1.Producing food\n");
        printf("2.Producing gold\n");
        printf("3.Hiring soldiers\n");
        printf("4.Hiring workers\n");
        scanf("%d",&choise);
        switch (choise) {
            case 0:
                exit(0);
            case 1: {
                printf("Amount of producing food:\n");
                int food;
                scanf("%d", &food);
                rulers.food=food;
                break;
            }
            case 2: {
                printf("Amount of producing gold:\n");
                int gold;
                scanf("%d", &gold);
                rulers.gold=gold;
                break;
            }
            case 3: {
                printf("Numbers of soldiers:\n");
                int soldiers;
                scanf("%d", &soldiers);
                rulers.soldiers=soldiers;
                break;
            }
            case 4: {
                printf("Numbers of workers:\n");
                int workers;
                scanf("%d", &workers);
                rulers.workers+=workers;
                break;
            }
            default:
                printf("Wrong choice!\n");
        }
    }
}
