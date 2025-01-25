//
// Created by mahsa on 1/25/2025.
//

#ifndef WAR_H
#define WAR_H

#include <stdio.h>
#include "my_struct.h"

void destroyRoad(int x, int y, int size, char sign, char Map[][MAXSIZE], char map1[][MAXSIZE],char map2[][MAXSIZE]) {
    int i,j;
    if(map1[x][y]==sign) {
        map1[x][y]=Map[x][y];
        map2[x][y]=Map[x][y];
    }
    for(i=x+1,j=y; i<size && map1[i][j]==sign; i++) {
        map1[i][j]=Map[i][j];
        map2[i][j]=Map[i][j];
    }
    for(i=x-1,j=y; i>=0 && map1[i][j]==sign; i--) {
        map1[i][j]=Map[i][j];
        map2[i][j]=Map[i][j];
    }
    for(i=x, j=y+1; j<size && map1[i][j]==sign; j++) {
        map1[i][j]=Map[i][j];
        map2[i][j]=Map[i][j];
    }
    for(i=x, j=y-1; j>=0 && map1[i][j]==sign; j--) {
        map1[i][j]=Map[i][j];
        map2[i][j]=Map[i][j];
    }
}

int simpleWar(Ruler *yourWlt,Ruler *enemyWlt) {
    if (yourWlt->soldiers > enemyWlt->soldiers) {
        printf("You win the war!\n");
        yourWlt->food+=enemyWlt->food;
        yourWlt->gold+=enemyWlt->gold;
        enemyWlt->food=0;
        enemyWlt->gold=0;
        return 1;
    }
    if (yourWlt->soldiers == enemyWlt->soldiers) {
        printf("Equal war!\n");
        return 0;
    }
    if(yourWlt->soldiers < enemyWlt->soldiers){
        printf("You lose the war!\n");
        enemyWlt->food+=yourWlt->food;
        enemyWlt->gold+=yourWlt->gold;
        yourWlt->food=0;
        yourWlt->gold=0;
        return -1;
    }
}

int checkWar(char map[][MAXSIZE],int x, int y,char yourSign,int Array[]){
    char enemyR, enemyC;
    int i;
    if(yourSign == 'R') {
        enemyC= 'c';
        enemyR= 'r';
    }
    else {
        enemyC='C';
        enemyR='R';
    }
    int rowDir[] = {1, -1, 0, 0};
    int colDir[] = {0, 0, 1, -1};
    for(i=0;i<4;i++) {
        if (map[x+rowDir[i]][y+colDir[i]]==enemyC) {
            return -1;// -1= all out war
        }
    }
    for(i=0;i<4;i++) {
        if(map[x+rowDir[i]][y+colDir[i]]==enemyR) {
            Array[0]=x;
            Array[1]=y;
            return 0; // 0= simple war
        }
    }
    for(i=0;i<4;i++) {
        if(map[x+rowDir[i]][y+colDir[i]]=='v'){
            int newX=x+rowDir[i];
            int newY=y+colDir[i];
            for(int j=0;j<4;j++) {
                if(map[newX+rowDir[j]][newY+colDir[j]]==enemyR) {
                    Array[0]=newX;
                    Array[1]=newY;
                    return 0; // 0= simple war
                }
            }
        }
    }
    return 1;// 1= no war
}


#endif //WAR_H
