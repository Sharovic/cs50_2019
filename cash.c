#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float r;

do
{
  r = get_float("Change owed:");
  
}
while(r<0);
//printf("%f\n", r);
// Переводим доллар и центы в центы
int summa = round(r * 100);
//printf("%i\n", summa);
// Ищем количество монеток номиналами 25, 10, 5, 1 цент
//for

   int coins = summa / 25;
   int reminder = summa % 25; 
   coins += reminder / 10; 
   reminder %= 10;
   coins += reminder / 5; 
   reminder %= 5;
   coins += reminder / 1; 
   reminder %= 1;
   
printf("%i\n", coins);
}