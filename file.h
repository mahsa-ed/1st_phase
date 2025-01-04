//
// Created by mahsa on 12/5/2024.
//

#ifndef INC_1ST_PHASE_PRINTMAP_H
#define INC_1ST_PHASE_PRINTMAP_H

#endif //INC_1ST_PHASE_PRINTMAP_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my_struct.h"



void printMap(int size,char map[][MAXSIZE]){
    int i,j;
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            printf("%c ",map[i][j]);}
        printf("\n");
    }
}

int generate_number () {
    const double probs[9] = {0.65, 0.25, 0.05, 0.05, 0, 0, 0, 0, 0};
    double cdf[9];
    cdf[0] = probs[0];
    for (int i = 1; i < 9; ++i) {
        cdf[i] = cdf[i - 1] + probs[i];
    }

    double rand_val =(double)rand() /RAND_MAX ;

    for (int i = 0; i < 9; ++i) {
        if (rand_val < cdf[i]) {
            return i + 1;
        }
    }
    return -1;
}


void SeparatorLine(char sep,int n) {
    int i;
    for (i=0; i<n; i++)
        printf("%c",sep);
    printf("\n");
}

int CheckRoad(char Map[][MAXSIZE],int x,int y) { //***
    if (Map[x][y] !='1' && Map[x][y] !='2' && Map[x][y] !='3' && Map[x][y] !='4') return 0;
    int i;
    int rowDir[] = {1, -1, 0, 0};
    int colDir[] = {0, 0, 1, -1};
    char temp;
    for(i=0;i<4;i++) {
        temp=Map[x+rowDir[i]][y+colDir[i]];
        if(temp=='C' || temp=='R' || temp=='v') return 1;
    }
    return 0;
}
