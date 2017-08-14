#include<stdio.h> // Main library of the function
#include<stdlib.h> 
#include<time.h>  // Library to use random numbers
#include<conio.h>
#include<math.h>

void automata_dynamics(int order,float prob,int days,int **matrix,int **matrix_aux)
{
     
 int automata_cci(int i, int order);
 int automata_ccj(int j, int order);
           
 srand((unsigned)time(NULL)); // Tornando os números aleatórios "mais aleatórios"
 int i,j;                       // Variáveis para percorrer a matriz
 int infected;                 // Número de infectados na matriz
 int k,h,nvi;
 float p,r;

 for(i=0;i<order;i++)
 {
   for(j=0;j<order;j++)
   {
     switch(matrix[i][j])
     {
       case 0:       
         nvi=0;  
         for(k=-1;k<=1;k++)
         {
           for(h=-1;h<=1;h++)
           {
             if( matrix[automata_cci(i+k,order)][automata_ccj(j+h,order)] == 1 ) nvi++;
           }
         }
         p=1-pow(1-prob,nvi); 
         //outra opcao de p é p=prob*nvi/8.0
         r=0.01*(rand()%101); 
         if(r<p) matrix_aux[i][j]=1;   
      
       break;

       case 1:
         matrix_aux[i][j]=1;
       break;
     } // switch                     
     
   } // j
 } // i
  
}//void automata_dynamics(int order,float prob,int days,int **matrix,int **matrix_aux) 
