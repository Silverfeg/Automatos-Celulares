#include<stdio.h>
#include<stdlib.h>

int automata_ccj(int j,int order)
{
     if(j<0)return (order-1);
     if(j>(order-1))return 0;
     return j;
}
