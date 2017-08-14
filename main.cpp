/* Code developed by Silas dos Santos Vergilio
   Data of creation: 24/09/2011
   Last update: 14/10/2011
*/

// Declaration of libraries

#include<stdio.h> // Biblioteca principal
#include<conio.h> 
#include<time.h> // Biblioteca usada para número aleatórios

//Declaration of the functions

#include "automata_order.cpp"
#include "automata_allocation.cpp"
#include "initial_condition.cpp"
#include "automata_print.cpp"
#include "automata_dynamics.cpp"
#include "automata_cci.cpp"
#include "automata_ccj.cpp"
#include "automata_update.cpp"

typedef struct parameters
{
    int days;               // Tempo que já passou desde o início do autômato
    float prob;            // Probabilidade de infecção
    int order;            // Ordem da matriz quadrada
    int ini_dens_infected;// Número total de infectados
    
} parameters;

// Main  - CONTEM A ESTRUTURA DE DADOS CENTRAL (PARAMETERS) E FAZ SUA INICIALIZACAO



int main()
{

 // Declaração de variáveis
 parameters automata;
 int **matrix;
 int **matrix_aux;
 int i,j;
                
 puts("Bem vindo ao Autômato Celular de Thaís\n"); // Apresentação do programa
 automata.order = automata_order(automata.order);     
    
 automata.ini_dens_infected=1;
 automata.days=10;
 
        
             
 puts("Entre com a probabilidade de infecção de cada membro");
 scanf("%f",&automata.prob);
 while(automata.prob<0 || automata.prob>1)
 {
   puts("Probabilidade inválida, tente novamente");
   scanf("%f",&automata.prob);
 } // while    

    
 matrix = automata_allocation(automata.order); 
 matrix_aux = automata_allocation(automata.order);
    
 initial_condition(automata.order,matrix);
 automata_print(automata.order,matrix);
 
 puts("");  
 
 for(int day=0;day<automata.days;day++)
 {
   automata_dynamics(automata.order, automata.prob, automata.days, matrix, matrix_aux);
   // Chamando a função do programa que mostra o autômato uma vez.
   automata_update(automata.order,matrix,matrix_aux);
   automata_print(automata.order,matrix);
   puts("");  
 }
    
 //automata_print(automata.order,matrix);
 //automata_update(automata.order,matrix,matrix_aux);
    
getch();
return 0;
} // main
