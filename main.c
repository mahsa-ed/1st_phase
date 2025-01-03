#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"
#include "file.h"
#include "my_struct.h"
#include "findPath.h"

char Map[MAXSIZE][MAXSIZE];

int main(void) {
    srand (time (NULL) ) ;
    int size;
    int Vcount, Xcount, Ccount;
    int i, j, k;
    Ruler rulers;


    printf("please enter the map size ");
    scanf("%d", &size);
    int valu[size][size];
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            Map[i][j] = '1';
        }
    }

    printf("please enter the number of castles and coordinates ");
    scanf("%d", &Ccount); //قرار گیری قلمرو ها
    Coordinates Castle[Ccount];
    for (k = 0; k < Ccount; k++) {
        scanf("%d %d", &i, &j);
        Map[i - 1][j - 1] = 'C';
        Castle[k].x= i-1 ;
        Castle[k].y= j-1 ;
    }

    printf("please enter the number of villages, coordinates,gold rate and food rate ");
    scanf("%d", &Vcount); //قرار گیری روستا ها و نرخ تولید
    Coordinates Village[Vcount];
    Rates V[Vcount];
    for (k = 0; k < Vcount; k++) {
        scanf("%d %d", &i, &j);
        Map[i - 1][j - 1] = 'V';
        scanf("%d %d",&V[k].goldRate, &V[k].foodRate);
        Village[k].x = i-1;
        Village[k].y = j-1;
    }

    printf("please enter the number of blocked houses and coordinates ");
    scanf("%d", &Xcount);//قرار گیری خانه های مسدود
    for (k = 0; k < Xcount; k++) {
        scanf("%d %d", &i, &j);
        Map[i - 1][j - 1] = 'X';
    }

    printMap(size,Map);
    for(k=0;k<Ccount;k++) {
        for(j=0;j<Vcount;j++) {
            Map[Castle[k].x][Castle[k].y] = '1';
            Map[Village[j].x][Village[j].y] = '1';
            findPath(Map,size,Castle[k].x,Castle[k].y,Village[j].x,Village[j].y);
            Map[Castle[k].x][Castle[k].y] = 'C';
            Map[Village[j].x][Village[j].y] = 'V';
        }
    }
    printMap(size,Map);

    for (i = 0; i < size; i++) { //ارزش دادن به خانه های خالی با عدد تصادفی از1 تا 4
        for (j = 0; j < size; j++) {
            if (Map[i][j] == '1') {
                char temp;
                valu[i][j] = generate_number();
                temp= valu[i][j]+'0';
                Map[i][j] = temp;
            }
        }
    }

    rulers.soldiers=0;
    rulers.food=0;
    rulers.workers=1;
    rulers.gold=5;
    rulers.goldrate=1;
    rulers.foodrate=0;
    int choise;
    printf("How many soldiers do you want?\n");
    int target_soldiers;
    scanf("%d",&target_soldiers);
    while(rulers.soldiers < target_soldiers) {
        rulers.gold+=rulers.goldrate;
        rulers.food+=rulers.foodrate;
        printf("MENU:\n");
        printf("0.Exit\n");
        printf("1.Producing foodrate\n");
        printf("2.Hiring soldiers\n");
        printf("3.Hiring workers\n");
        scanf("%d",&choise);
        switch (choise) {
            case 0:
                exit(0);
            case 1: {
                printf("Amount of producing foodrate(1 GOLD IS NEEDED):\n");
                int number;
                scanf("%d", &number);
                if(rulers.gold >=number*1){
                    rulers.foodrate+= number;
                    rulers.gold-=(number*1);
                }
                else printf("YOU DON'T HAVE ENOUGH GOLDS TO BUY FOODS!\n");
                break;
            }
            case 6: {
                printf("Amount of producing goldrate:\n");
                int goldrate;
                scanf("%d", &goldrate);
                rulers.goldrate=goldrate;
                break;
            }
            case 2: {
                printf("Numbers of soldiers(2 GOLDS ARE NEEDED):\n");
                int soldiers;
                scanf("%d", &soldiers);
                if(rulers.gold>=2)rulers.soldiers=soldiers;
                else printf("YOU DON'T HAVE ENOUGH GOLDS TO HIRE A SOLDIER!\n");
                break;
            }
            case 3: {
                printf("Numbers of workers(3 FOODS ARE NEEDED):\n");
                int workers;
                scanf("%d", &workers);
                if(rulers.food>=3)rulers.workers+=workers;
                else printf("YOU DON'T HAVE ENOUGH FOODS TO HIRE A WORKER!\n");
                break;
            }
            default:
                printf("Wrong choice!\n");
        }
    }
}
