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
6. Számjegyek duplikálása
Írj egy double_digits nevű függvényt, mely visszaadja azt a sztringet, melyet a paraméterként megkapott sztring számjegyeinek megkettőzésével kapunk.
*/

char* double_digits(char* s) {
    int hossz = strlen(s);
    char* result = calloc(2*hossz,sizeof(char));
    int idx = 0; // másolás során helyiérték nyomon követése az új tömbben

    for (int i = 0; i<hossz; i++) {
        if (isdigit(s[i])) {
            result[idx++] = s[i];
            result[idx++] = s[i];
        } else {
            result[idx++] = s[i];
        }
    }
    result[idx] = '\0';
    
    return result;
}

void test_7f() {
    FILE* f_in = fopen("feladat7.txt", "r");
    
    char sor[300];

    while(fgets(sor, 300, f_in) != NULL) {
        int hossz = strlen(sor);
        sor[hossz-1] = '\0';

        if(strcmp(sor,"END") == 0) { // strcmp három értéket ad vissza
            break;
        }

        printf("Duplikált string = %s\n", double_digits(sor));
    }
}

int main() {
    test_7f();

    return 0;
}