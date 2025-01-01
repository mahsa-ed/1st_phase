//
// Created by mahsa on 12/14/2024.
//

#ifndef INC_1ST_PHASE_MY_STRUCT_H
#define INC_1ST_PHASE_MY_STRUCT_H

typedef struct {
    int x, y;
} coordinates;

typedef struct {
    int front, rear;
    coordinates items[17];
} Queue;

#endif //INC_1ST_PHASE_MY_STRUCT_H

