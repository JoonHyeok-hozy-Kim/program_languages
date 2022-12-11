#include <stdio.h>


int main() {

    float averages;
    int i;
    int j;

    int grades[2][5];

    grades[0][0] = 80;
    grades[0][1] = 70;
    grades[0][2] = 65;
    grades[0][3] = 89;
    grades[0][4] = 90;

    grades[1][0] = 85;
    grades[1][1] = 80;
    grades[1][2] = 80;
    grades[1][3] = 82;
    grades[1][4] = 87;

    for (i=0; i<2; i++){
        averages = 0;
        for (j=0; j<5; j++){
            averages += grades[i][j];
        }
        printf("average : %f\n", averages/5);
    }

}