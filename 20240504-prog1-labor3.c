/* 
PROGRAMOZÁSI NYELVEK 1 LABOR
2024.05.04 TEOK II 108
https://elearning.unideb.hu/pluginfile.php/165380/mod_resource/content/1/Gyak2.pdf
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

/*
5. Szóközök eltávolítása (állományjelig olvasás) - P105101e
*/
char* delete_spaces(char* s) {
    int hossz = strlen(s);
    char* result = calloc(hossz+1, sizeof(char)); // strlen nem számolja bele a '\0'-át, de a memória foglaláshoz szükség van rá = hossz+1
    int idx = 0;

    for(int i=0; i<hossz; i++) {
        if(s[i] != ' ') {
            result[idx++] = s[i]; // idx értéke kezdetileg 0, ha ++ postfixként van akkor a kifejezés végrehajtása után növeli. Eredeti értékkel meghívja a tömböt és utána növeli eggyel. idx "követi" a helyiértéket a másolás során az új tömbben
        }
    }
    result[idx] = '\0'; // Utolsó másolt karakter után '\0'

    return result;
}

void test_5f() {
    FILE* f_in = fopen("feladat5.txt", "r");
    char sor[300];

    while(fgets(sor,300,f_in) != NULL) {
        int hossz = strlen(sor);
        sor[hossz-1] = '\0';

        printf("Tisztított szöveg = %s\n", delete_spaces(sor));
    }
}

int main()
{
//    beolvas_4f();
    test_5f();

    return 0;
}

