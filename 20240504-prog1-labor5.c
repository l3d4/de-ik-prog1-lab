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
Fájl kezelés
3.
Írjon eljárást, amely a be.txt fájlból legfeljebb 100 karaktert tartalmazó sorokat olvas be
állományvégjelig (EOF). Mindegyik sor egy-egy hallgató Neptun-kódját és nevét, valamint
az ebben a félévben a Magas szintű programozási nyelvek 1 című tárgyból a
számonkéréseken szerzett pontszámait tartalmazza, az adatokat egy-egy pontosvesszővel
választva el egymástól. A program soronként írja a standard kimenetre a hallgatók nevét és az
egy-egy hallgató által megszerzett pontok összegét! Egy lehetséges példa bemenet a
következő:
ABCDEF;Gipsz Jakab;1;0;2;2;0;3;4;0;5;5;0
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char sor[100];    

    FILE* f_in = fopen("be.txt", "r");
    int sum = 0;
    char nev[30];
    
    while(fgets(sor, 100, f_in) != NULL) {
        int hossz = strlen(sor);
        sor[hossz-1] = '\0'; // takarítás

        char* token;

        token = strtok(sor, ";"); // neptunkód
        token = strtok(NULL, ";"); // név
        strcpy(nev, token);
    

        while((token = strtok(NULL, ";")) != NULL) {
            sum += atoi(token);
            }
    
    printf("%s osszpont = %d\n", nev, sum);
    sum=0;
    }

    return 0;
}    


/*
int main() {
    char sor[100];
    FILE* f_in = fopen("be.txt", "r");
    int sum = 0;
    char nev[30];

    int pontszamok[11];
    while(fgets(sor, 100, f_in) != NULL) {
        int hossz = strlen(sor);
        sor[hossz-1] = '\0';

        char* neptun_kod = strtok(sor, ";");
        nev = strtok(NULL, ";");
        while(strtok(NULL, ";") != NULL) {
            for(int i = 0; i < sizeof(pontszamok)/sizeof(pontszamok[0]); i++) {
                pontszamok[i] = atoi(strtok(NULL, ";"));
            }
        }
    }

    for(int i = 0; i < sizeof(pontszamok)/sizeof(pontszamok[0]); i++) {
        sum = sum + pontszamok[i];
    }

    printf("%d\n", sum);

    return 0;
}
*/