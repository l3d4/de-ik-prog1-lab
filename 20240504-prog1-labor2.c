/* 
PROGRAMOZÁSI NYELVEK 1 LABOR
2024.05.04 TEOK II 108
https://elearning.unideb.hu/pluginfile.php/165380/mod_resource/content/1/Gyak2.pdf
Sztring kezelés
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
1. Írjunk eljárást, amely paraméterként megkap egy karaktereket tartalmazó, tetszőleges
méretű egydimenziós tömböt, és a tömb nem betű karaktereit kicseréli szóközre!
*/
void csere_szokozre(char s[])
{
    int hossz = strlen(s);
    for (int i=0; i<hossz; i++)
    {
        if(!isalpha(s[i]))
        {
            s[i] = ' ';
        }
    }
}

/*
2. Írjunk függvényt, amely egy paraméterként megkapott sztringben szóközzel felülírja a
nem betű karaktereket és visszaadja az új sztringet!
- STACK vs HEAP
- ha egy tömböt adok át, akkor a tömb nevét adom, mert az egy mutató a tömbre, ami a tömb első [0] helyére mutat
- hossz+1 >> a strlen(s) nem számolja a sztringet lezáró NULL értéket
- calloc lefoglalja a memória területet, hány darabot és mekkora darabok
*/
char* csere_szokozre2(char s[])
{
    int hossz = strlen(s);
    char* result = calloc(hossz+1, sizeof(char)); 
    
    int i;
    for(i=0; i<hossz;i++)
    {
        if(! isalpha(s[i]))
        {
            result[i] = '*';
        }
        else
        {
            result[i] = s[i];
        }
    }
result[i] = '\0';

return result;
}


// ****main****
int main()
{
    char szoveg[30];
    scanf("%s",szoveg);
//    csere_szokozre(szoveg);
    char* r = csere_szokozre2(szoveg);

    printf("%s\n",r);

    return 0;
}