#include <stdio.h>

void char_pointer_test(){
    printf("\n[char_pointer_test]\n");
    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    char * pvowles = &vowels;
    int i;

    // Print the addresses
    for (i=0; i<5; i++){
        printf("&vowels[%d] : %p / pvowels + %d : %p, vowels + %d : %p\n", i, &vowels[i], i, pvowles+i, i, vowels+i);
    }
    
    // Print the values
    for (i=0; i<5; i++){
        printf("&vowels[%d] : %c / *(pvowels + %d) : %c, *(vowels + %d) : %c\n", i, vowels[i], i, *(pvowles + i), i, *(vowels + i));
    }

    free(pvowles);
    free(vowels);
}

void dynamic_allocation_for_array(){
    printf("\n[dynamic_allocation_for_array]\n");
    int n = 5;
    char * pvowels = (char *) malloc(n * sizeof(char));
    int i;

    pvowels[0] = 'A';
    pvowels[1] = 'E';
    *(pvowels + 2) = 'I';
    *(pvowels + 3) = 'O';
    pvowels[4] = 'U';

    for (i=0; i<5; i++) printf("%c ", *(pvowels+i));
    printf('\n');
    // for (i=0; i<5; i++) printf("%c ", pvowels[i]);
    // printf('\n');

    free(pvowels);
}

void two_dimensional_array_test(){
    int nrows = 2;
    int ncols = 5;
    int i, j;

    char **pvowels = (char **) malloc(nrows * sizeof(char *));

    for (i=0; i<nrows; i++){
        pvowels[i] = (char *) malloc(ncols * sizeof(char));
    }

    pvowels[0][0] = 'A';
    pvowels[0][1] = 'E';
    pvowels[0][2] = 'I';
    pvowels[0][3] = 'O';
    pvowels[0][4] = 'U';

    pvowels[1][0] = 'a';
    pvowels[1][1] = 'e';
    pvowels[1][2] = 'i';
    pvowels[1][3] = 'o';
    pvowels[1][4] = 'u';

    for (i=0; i<nrows; i++){
        for (j=0; j<ncols; j++){
            printf("%c ", pvowels[i][j]);
        }
        printf("\n");
    }

    free(pvowels);
}

int ** generate_pascal_triangle(int row_num){
    int i, j;
    int ** pt = (int **) malloc(row_num * sizeof(int*));
    for (i=0; i<row_num; i++){
        pt[i] = (int *) malloc((i+1) * sizeof(int));
    }

    pt[0][0] = 1;
    if (row_num == 1) return pt;

    pt[1][0] = 1;
    pt[1][1] = 1;
    if (row_num == 2) return pt;

    for (i=2; i<row_num; i++){
        for (j=0; j<=i; j++){
            if (j==0 || j == i) {
                pt[i][j] = 1;
            } else {
                pt[i][j] = pt[i-1][j-1] + pt[i-1][j];
            }
        }
    }

    return pt;    
}

void print_pascal_triangle(int ** pt, int row_cnt){
    int i, j;
    for (i=0; i<row_cnt; i++){
        for (j=0; j<=i; j++){
            printf("%d ", pt[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // char_pointer_test();
    // dynamic_allocation_for_array();
    // two_dimensional_array_test();

    int rows = 7;
    int ** pascal_triangle = generate_pascal_triangle(rows);
    print_pascal_triangle(pascal_triangle, rows);
}