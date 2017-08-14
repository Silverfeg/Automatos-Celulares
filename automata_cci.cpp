#include<stdio.h>
#include<stdlib.h>

int automata_cci(int i, int order)
{
     if(i<0)return (order-1);
     if(i>(order-1))return 0;
     return i;
}
