#include <stdio.h>
#include <stdlib.h>


char Map[17][17];

int main(void) {
    int size;
    int Vcount, Xcount,Ccount;
    int i, j, k;
    printf("please enter the map size");
    scanf("%d", &size);
    int goldRate[size][size],foodRate[size][size],valu[size][size];
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            Map[i][j] = '1';}}

    printf("please enter the number of castles and coordinates");
    scanf("%d",&Ccount); //قرار گیری قلمرو ها
    for(k=1;k<=Ccount;k++){
        scanf("%d %d",&i, &j);
        Map[i-1][j-1]='C';}

    printf("please enter the number of villages, coordinates,gold rate and food rate");
    scanf("%d",&Vcount); //قرار گیری روستا ها و نرخ تولید
    for(k=1;k<=Vcount; k++){
        scanf("%d %d",&i, &j);
        Map[i-1][j-1]='V';
        scanf("%d %d",&goldRate[i-1][j-1], &foodRate[i-1][j-1]);}

    printf("please enter the number of blocked houses and coordinates");
    scanf("%d",&Xcount);//قرار گیری خانه های مسدود
    for(k=1;k<=Xcount;k++){
        scanf("%d %d",&i, &j);
        Map[i-1][j-1]='X';}

    for (i = 0; i < size; i++){ //ارزش دادن به خانه های خالی با عدد تصادفی از1 تا 4
        for (j = 0; j < size; j++){
            if (Map[i][j]=='1'){
                valu[i][j]= (rand() %4)+1;
            }}}
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            printf("%c ",Map[i][j]);}
        printf("\n");
    }
}