#include<stdio.h> // Biblioteca principal
#include<stdlib.h>

// Função usada para obter a ordem da matriz
int automata_order(int x)
{
 int order;
 
 printf("Entre com a ordem da matriz - um número ímpar\n");
 scanf("%d",&order); 
 if(order<=2 || order>=100)
 { // Eliminating impossible value for the order
   printf("Ordem inválidade, tente novamente\n");
   scanf("%d",&order); 
 } //if
                    
return order; 
} // fim da função
        
        
