#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int shift(char c);

int main(int argc, string argv[])
{   
// Проверка, что введено только 1 параметр
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
	    return 1;
    }

// Проверка, что введен ключ, а не цифры или что-то другое
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]) == false)
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
    }

// Переводим ключ в массив int key (можно было в цикле проверки на цифры,
// но для наглядности сделаю отдельно) 
    int key[strlen(argv[1])];
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            key[i] = shift(argv[1][i]);
//            printf("ключ %i\n", key[i]);
        }

// Вводим строку для кодировки
    string p = get_string("plaintext: ");

// Заготовка для вывода кодированого сообщения
    printf("ciphertext: ");

// Кодировка
int j = 0;
int keyc = key[j];    
    for (int i = 0, n = strlen(p); i < n; i++)
    {
            char chiper;
            if ( (p[i] >= 'a')&&(p[i] <= 'z') )  
                {
                    chiper = ((p[i] + 1 - 'a' + keyc) % 26);
                    j += 1;
                    if (j == (strlen(argv[1])) )
                        {
                            j = 0;
                            keyc = key[0];
                        }
                    else
                        {    
                            keyc = key[j];                    
                        }
                    if (chiper < 97)
                        {
                            chiper += 96;
                        }
                }
            else if (  p[i] >= 'A' && p[i] <= 'Z' )
                {
                    chiper = ((p[i] + 1 - 'A' + keyc) % 26);
                    j += 1;
                    if (j == (strlen(argv[1])) )
                        {
                            j = 0;
                            keyc = key[0];
                        }
                    else
                        {    
                            keyc = key[j];                    
                        }
                    if (chiper < 65)
                        {
                            chiper += 64;                      
                        }
                }
            else
                {
                    chiper = p[i];
                }
            printf("%c", chiper);
                
    }
    printf("\n"); 
}

int shift(char c)
{
    char symb;
//    printf("понижаем %c %i\n", c, c);
    if (c >= 'a' && c <= 'z' ) {
        symb = 'a';
    } else {
        symb = 'A';
    }
    int chiper = c - symb;
//    printf("chiper: %i \n", chiper);
    return chiper;
}
