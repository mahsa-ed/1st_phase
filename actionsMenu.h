//
// Created by mahsa on 1/25/2025.
//

#ifndef ACTIONSMENU_H
#define ACTIONSMENU_H

#include <stdio.h>
//#include "my_struct.h"
#include "printColorMap.h"
#include "file.h"
#include "war.h"

int Menu(char yourMap[][MAXSIZE],char enemyMap[][MAXSIZE],char firstMap[][MAXSIZE], int size,Ruler *wealth, Ruler *enemyWealth, Rates vRate[],Coordinates village[],char yoursign) {
    printf("SEE YOUR WEALTH!\n");
    printf("Gold: %d\n",wealth->gold);
    printf("Food: %d\n",wealth->food);
    printf("Soldiers: %d\n",wealth->soldiers);
    printf("Workers: %d\n",wealth->workers);
    printf("Goldrate: %d\n",wealth->goldrate);
    printf("Foodrate: %d\n",wealth->foodrate);

    colorMap(yourMap,size);

    printf("MENU:\n");
    printf("0.Exit\n");
    printf("1.Producing food (1 GOLD IS NEEDED)\n");
    printf("2.Hiring soldiers (2 GOLDS ARE NEEDED)\n");
    printf("3.Hiring workers (3 FOODS ARE NEEDED)\n");
    printf("4.Build a road\n");
    int choise;
    scanf("%d",&choise);
    switch (choise) {
        case 0: {
            return 1;
        }

        case 1: {
            printf("Amount of producing food(1 GOLD IS NEEDED):\n");
            int number;
            scanf("%d", &number);
            if(wealth->gold >=(1*number)){
                wealth->food+= number;
                wealth->gold-=(1*number);
                return 1;
            }
            printf("YOU DON'T HAVE ENOUGH GOLDS TO BUY %d FOODS!TRY AGAIN\n",number);
            return 0;
        }

        case 2: {
            printf("Numbers of soldiers(2 GOLDS ARE NEEDED):\n");
            int number;
            scanf("%d", &number);
            if(wealth->gold>=(2*number)) {
                wealth->soldiers+=number;
                wealth->gold-=(2*number);
                return 1;
            }
            printf("YOU DON'T HAVE ENOUGH GOLDS TO HIRE %d SOLDIER!TRY AGAIN\n",number);
            return 0;
        }

        case 3: {
            printf("Numbers of workers(3 FOODS ARE NEEDED):\n");
            int number;
            scanf("%d", &number);
            if(wealth->food>=(3*number)) {
                wealth->workers+=number;
                wealth->food-=(3*number);
                return 1;
            }
            printf("YOU DON'T HAVE ENOUGH FOODS TO HIRE %d WORKER!TRY AGAIN\n",number);
            return 0;
        }

        case 4: {
            int x,y;
            printf("Enter the coordinate of new road. x:  y:\n");
            scanf("%d %d",&x,&y);
            x--, y--;
            if (!CheckRoad(yourMap,x,y,yoursign)) {
                printf("UNABLE TO BUILD A ROAD!TRY AGAIN\n");
                return 0;
            }
            else {
                if(wealth->workers>=(yourMap[x][y]-'0')) {
                    yourMap[x][y]=yoursign;
                    enemyMap[x][y]=yoursign;
                    int Array[2];
                    int check=checkWar(yourMap,x,y,yoursign,Array);
                    if(check==-1){ //جنگ تمام عیار
                        if (wealth->soldiers > enemyWealth->soldiers)
                            return -1;
                        else {
                            destroyRoad(x, y, size,yoursign,firstMap,yourMap,enemyMap);
                            if(wealth->soldiers < enemyWealth->soldiers) {
                                enemyWealth->food+=wealth->food;
                                enemyWealth->gold+=wealth->gold;
                                wealth->food=0;
                                wealth->gold=0;
                                printf("You lost the war!\n");
                            }
                            else (printf("Equal war!\n"));
                        }
                    }
                    else if(check==0) { //جنگ ساده
                        int temp=simpleWar(wealth,enemyWealth);
                        if (temp==1) {
                            char enemysign;
                            if (yoursign=='R') enemysign='r';
                            else if (yoursign=='r') enemysign='R';
                            destroyRoad(Array[0], Array[1], size,enemysign,firstMap,yourMap,enemyMap);
                        }
                        else if(temp==0) {
                            destroyRoad(Array[0], Array[1], size,'R',firstMap,yourMap,enemyMap);
                            destroyRoad(Array[0], Array[1], size,'r',firstMap,yourMap,enemyMap);
                        }
                        else if(temp==-1) {
                            destroyRoad(Array[0], Array[1], size,yoursign,firstMap,yourMap,enemyMap);
                        }
                    }
                    CheckVillage(yourMap,enemyMap,x,y,&(wealth->goldrate),&(wealth->foodrate),village,vRate);
                }
                else {
                    yourMap[x][y]-=wealth->workers;
                }
                return 1;
            }
        }

        default: {
            printf("WRONG CHOISE!TRY AGAIN\n");
            return 0;
        }
    }
}

#endif //ACTIONSMENU_H
