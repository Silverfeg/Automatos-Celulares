#include<stdio.h>
#include<stdlib.h>

int **automata_allocation(int order)
{

 int i,j;
 int **matrix;
 
 matrix = (int **)calloc(order,sizeof(int *));
 
 for (i = 0; i <order; i++) matrix[i] = (int *)calloc(order,sizeof(int));
 
return(matrix);
   
} // matrix_allocation 
