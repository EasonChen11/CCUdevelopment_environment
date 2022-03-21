#include <stdio.h>
const char A_list[][3]={"  ","  ","A=","  ","  "};
const char B_list[][3]={"  ","B=","  "};
const char C_list[][3]={"  ","C=","  "};
int C[3][3]={0};
void func(const int A[5][5], const int B[3][3], int row, int colum);

void print_square5(int **square);
void print_square3(int **square,char a) ;
int main() {
    const int A[][5]={{1,1,1,0,0},
                      {0,1,1,1,0},
                      {0,0,1,1,1},
                      {0,0,1,1,0},
                      {0,1,1,0,0}
    };
    const int B[][3]={{1,0,1},
                      {0,1,0},
                      {1,0,1}
    };
    print_square5(A);
    print_square3(B, 'B');
    print_square3(C, 'C');
    func(A, B, 0, 0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void print_square5(int ** square) {
    for (int i = 0; i < 5; ++i) {
        printf("%s",A_list[i]);
        for (int j = 0; j < 5; ++j) {
                printf("%d",square[i][j]);
        }
        printf("\n");
    }
}
void print_square3(int **square,char a) {
    for (int i = 0; i < 3; ++i) {
        if(a=='B')
            printf("%s",B_list[i]);
        else
            printf("%s",C_list[i]);
        for (int j = 0; j < 3; ++j) {
            printf("%d",square[i][j]);
        }
        printf("\n");
    }
}

void func(const int A[5][5], const int B[3][3], int row, int colum) {
    if(row==3 && colum==3)
        return;
    for (int i = row; i < row+3; ++i) {
        for (int j = colum; j < colum+3; ++j) {
            C[i][j]+=A[i][j]*B[i][j];
        }
    }
    if(colum==2)
        func(A, B, row + 1, 0);
    else
        func(A, B, row, colum + 1);
}
