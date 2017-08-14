#include<stdio.h>
#include<stdlib.h>

int **automata_update(int order,int **matrix,int **matrix_aux)
{
    int i,j;
    
    for(i=0;i<order;i++){
    for(j=0;j<order;j++){
                            
    matrix[i][j]=matrix_aux[i][j];
    } // for i
    } // for j
    printf("\n");
       
} // automata_update
