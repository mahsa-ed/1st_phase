//
// Created by mahsa on 12/5/2024.
//

#ifndef INC_1ST_PHASE_PRINTMAP_H
#define INC_1ST_PHASE_PRINTMAP_H

#endif //INC_1ST_PHASE_PRINTMAP_H
#include <stdio.h>
#include "raylib.h"
void printMap(int size,char map[][17]){
    int i,j;
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            printf("%c ",map[i][j]);}
        printf("\n");
    }
}
