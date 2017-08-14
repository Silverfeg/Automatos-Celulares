#include<stdio.h>
#include<stdlib.h>

int **initial_condition(int order,int **matrix)
{
 int i,j;

 int center=((order-1)/2)+1;
 // Calculando o centro do autômato para inserir a primeira célula infectada
    
 for(i=0;i<order;i++)
 {
   for(j=0;j<order;j++)
   {
     if(i==center-1 && j==center-1)
     {
       matrix[i][j]=1;
     } else {    
             matrix[i][j]=0;
            }
   
   } // for i
 } //for j
   
return (matrix);
} // int **automata_initial(int order,int center,int **matrix)
