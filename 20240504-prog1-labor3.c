/* 
PROGRAMOZÁSI NYELVEK 1 LABOR
2024.05.04 TEOK II 108
https://elearning.unideb.hu/pluginfile.php/165380/mod_resource/content/1/Gyak2.pdf
Sztring kezelés 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
4. Írjon programot, amely állományvégjelig (EOF) végigolvassa a standard bemenet
sorait, és a standard kimenetre írja a nagybetűvel kezdődő sorok közül a
leghosszabbnak a hosszát (egy egész számot)!
Linuxon Ctrl+D -vel lehet befejezni az inputot és kiértékeltetni az eredményt.
*/
void beolvas_4f()
{
    char sor[100];
    int max = 0;
    char max_sor[100]; // Leghosszabb sor tárolása

    while(fgets(sor, 100, stdin) != NULL)
    {
        int hossz = strlen(sor);
        sor[hossz-1] = '\0'; // Enter (\n) kicserélése

        if(isupper(sor[0]))
        {
            if(hossz > max)
            {
                max = hossz;
                strcpy(max_sor,sor);
            }
        }
    }
    printf("A leghosszabb nagybetűvel kezdődő sor = %s\n Ennek hossza: %d\n", max_sor, max); // Enter beleszámítódik "Sor" hossz=4
}

int main()
{
    beolvas_4f();

    return 0;
}

