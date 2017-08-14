/* Code developed by Silas dos Santos Vergilio
   Data of creation: 24/09/2011
   Last update: 14/10/2011
*/

// Declaration of libraries

#include<stdio.h> // Biblioteca principal
#include<conio.h> 
#include<time.h> // Biblioteca usada para n�mero aleat�rios

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
    int days;               // Tempo que j� passou desde o in�cio do aut�mato
    float prob;            // Probabilidade de infec��o
    int order;            // Ordem da matriz quadrada
    int ini_dens_infected;// N�mero total de infectados
    
} parameters;

// Main  - CONTEM A ESTRUTURA DE DADOS CENTRAL (PARAMETERS) E FAZ SUA INICIALIZACAO



int main()
{

 // Declara��o de vari�veis
 parameters automata;
 int **matrix;
 int **matrix_aux;
 int i,j;
                
 puts("Bem vindo ao Aut�mato Celular de Tha�s\n"); // Apresenta��o do programa
 automata.order = automata_order(automata.order);     
    
 automata.ini_dens_infected=1;
 automata.days=10;
 
        
             
 puts("Entre com a probabilidade de infec��o de cada membro");
 scanf("%f",&automata.prob);
 while(automata.prob<0 || automata.prob>1)
 {
   puts("Probabilidade inv�lida, tente novamente");
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
   // Chamando a fun��o do programa que mostra o aut�mato uma vez.
   automata_update(automata.order,matrix,matrix_aux);
   automata_print(automata.order,matrix);
   puts("");  
 }
    
 //automata_print(automata.order,matrix);
 //automata_update(automata.order,matrix,matrix_aux);
    
getch();
return 0;
} // main
