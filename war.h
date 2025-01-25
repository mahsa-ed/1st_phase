//
// Created by mahsa on 1/25/2025.
//

#ifndef WAR_H
#define WAR_H

#include <stdio.h>
#include "my_struct.h"

void destroyRoad(){}

void simpleWar(){}

int checkWar(char Map[][MAXSIZE],int x, int y,char yourSign){
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
        if (Map[x+rowDir[i]][y+colDir[i]]==enemyC) {
            return -1;// -1= all out war
        }
    }
    for(i=0;i<4;i++) {
        if(Map[x+rowDir[i]][y+colDir[i]]==enemyR) {
            return 0; // 0= simple war
        }
    }
    for(i=0;i<4;i++) {
        if(Map[x+rowDir[i]][y+colDir[i]]=='v'){
            int newX=x+rowDir[i];
            int newY=y+colDir[i];
            for(int j=0;j<4;j++) {
                if(Map[newX+rowDir[j]][newY+colDir[j]]==enemyR) {
                    return 0; // 0= simple war
                }
            }
        }
    }
    return 1;// 1= no war
}


#endif //WAR_H
