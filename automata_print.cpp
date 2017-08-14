#include<stdio.h>
#include<stdlib.h>

void automata_print(int order,int **matrix)
{
      
 int i,j;
      
 for (i=0;i<order;i++)
 { 
   for (j=0;j<order;j++)
   {
     printf("%d\t",matrix[i][j]);
   }
 printf("\n");
 }
 
} // void automata_print(int **matrix,int order)
