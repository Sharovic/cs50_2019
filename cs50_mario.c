#include <cs50.h>
#include <stdio.h>

int main(void)
{ 
//Проверка на вхождение от 1 до 8
  int h;
  do 
  {
     h = get_int("Height: ");
     
  }
  while(!((h>=1)&&(h<=8))); 
//  printf("%i\n", h);   
// Получили максимальную высоту башенки

// Рисуем башенку
 for (int i = 0; i < h; i++)
 {
     for (int k = h - 1; k > i; k--)
     {
         printf("%s", " ");
     }
     for (int j = 0; j <= i; j++)
     {
         printf("#");
     }
     printf("\n");
 }

}


Марио сложный вариант с двумя башенками

#include <cs50.h>
#include <stdio.h>

int main(void)
{ 
//Проверка на вхождение от 1 до 8
  int h;
  do 
  {
     h = get_int("Height: ");
     
  }
  while(!((h>=1)&&(h<=8))); 

// Получили максимальную высоту башенки

// Рисуем башенку
 for (int i = 0; i < h; i++)
 {
     for (int k = h - 1; k > i; k--)
     {
         printf("%s", " ");
     }
     for (int j = 0; j <= i; j++)
     {
         printf("#");
     }
// Пробел между башенками
     printf("  "); 
// Вторая башенка 
     for (int j = 0; j <= i; j++)
    {
         printf("#");
     }
// Точки для второй башенки
//     for (int k = h - 1; k > i; k--)
//     {
//         printf("%s", " ");
//     }
     printf("\n");
 }

}