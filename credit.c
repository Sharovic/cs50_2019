#include <cs50.h>
#include <stdio.h>
#include <math.h>

// считаем количество цифр в кредитке
int ccd(long number);

int main(void)
{

    long  number = get_long("Enter card mumder:");

// Проверка на начальные цифры. Принадлежность к платежной системы. 
        if (((number >= 340000000000000)&&(number <= 349999999999999))||((number >= 370000000000000)&&(number <= 379999999999999)))
        {
            printf("AMER\n");
        }
        else if (((number >= 5100000000000000)&&(number <= 5199999999999999))||((number >= 5200000000000000)&&(number <= 5299999999999999))||((number >= 5300000000000000)&&(number <= 3299999999999999))||((number >= 5400000000000000)&&(number <= 5499999999999999))||((number >= 5500000000000000)&&(number <= 5599999999999999)))
        {
            printf("MASTER\n");
        }
        else if (((number >= 4000000000000)&&(number <= 4999999999999))||((number >= 4000000000000000)&&(number <= 4999999999999990)))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
// Конец проверки на начальные цыфры. Принадлежность к платежной системы.

// считаем количество цифр в кредитке
    int ccd1 = ccd(number);
// printf("Количестов цифер в кредитке: %i\n", ccd1);

    long n = number;
    long n1; 
    long c = ccd1;
// Алгоритм Луна
//    for (int c = ccd1; (c != 0)&&( c != 1); c -=2 )
//        {
//            n1 = n % (pow(10, c-2));
//            n1 = n1 / (pow(10, c-1));
//            printf("Номер %lo счетчик %i\n", n, c);
//        }

     do
        {
            n = (n % 100)/10;
            n1 = number/c;
            c *= 100;
            n = n1;
            printf("Номер %ld счетчик %ld\n", n, c);
        }   
    while (n > 10);
//{
//    int odd = round(s%10);
//    printf("%lo\n", s);
//    printf("test");
//}
// Конец алгоритма Луна



}

// считаем количество цифр в кредитке
int ccd(long number)
{
    int count = 0;
    long cc = number;
    do
    {
        cc /=10;
        count++;
//        printf("count: %i cc %ld\n", count, cc);
    }
    while (cc > 0);
//printf("Количестов цифер в кредитке: %i\n", count);
return count;    
}
