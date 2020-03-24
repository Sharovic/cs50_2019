#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, string argv[])
{   
// Проверка, что введено только 1 параметр
    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");
	    return 1;
    }

// Переводим ключ в цифру   
    int key = atoi(argv[1]);

// Проверка на то, что введенный параметр число
    if ( key == 0 )
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }

// Вводим строку для кодировки
    string p = get_string("plaintext: ");

// Заготовка для вывода кодированого сообщения
    printf("ciphertext: ");

// Кодировка    
    for (int i = 0, n = strlen(p); i < n; i++)
    {
            char chiper;
            if ( (p[i] >= 'a')&&(p[i] <= 'z') )  
                {
                    chiper = ((p[i] + 1 - 'a' + key) % 26);
                    if (chiper < 97)
                        {
                            chiper += 96;
                        }
                }
            else if (  p[i] >= 'A' && p[i] <= 'Z' )
                {
                    chiper = ((p[i] + 1 - 'A' + key) % 26);
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
