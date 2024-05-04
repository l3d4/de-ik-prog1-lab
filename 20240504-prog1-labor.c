/* 
PROGRAMOZÁSI NYELVEK 1 LABOR
2024.05.04 TEOK II 108
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
Legnagyobb közös osztó
*/
int lnko(int a, int b)
{
    int r;
    do {
        r = a % b;
        a = b;
        b = r;
    } while (r != 0);

    return a;
}

/*
Tömb kiíratása
*/
void print_tomb(int t[], int meret)
{
    for (int i = 0; i < meret; i++)
    {
        printf("%d", t[i]);
        if (i < meret - 1)
        {
            printf(",");
        }
    }
    printf("\n");
}

/*
Maximum keresése tömbben. max = első elem és ehhez hasonlítom a tömb többi elemét. Ha nagyobbat talál, akkor kicseréli max értékét.
*/
int keres_max(int t[], int meret)
{
    int max = t[0];
    for (int i = 1; i < meret; i++)
    {
        if (t[i] > max)
        {
            max = t[i];
        }
    }

    return max;
}

/*
Tömb rendezése - cserés rendezés algoritmus alapján. 
Összehasonlítja a tömb első elemét a tömb összes többi mögötte álló elemével.
Ha valamelyik kisebb/nagyobb nála, akkor kicseréli a két elemet segédváltozó használatával.
Folytassuk ugyanezen az elven a sorozat második elemével, utoljára pedig az utolsó előttivel!
*/
void rendez_novekvo(int t[], int meret)
{
    for (int i = 0; i < meret-1; i++)
    {
        for (int j = i+1; j < meret; j++)
        {
            if (t[i] > t[j])
            {
                int tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }
        }
    }
}

/*
Tömbön belül vizsgálom, hogy az összes elemet párba állítva, csak relatív prímeket kapok. Ha van egy kivétel a tömbben, akkor már hamis.
*/
int is_relative_prim(int t[], int meret)
{
    int valasz = 1;
    for (int i = 0; i < meret-1; i++)
    {
        for (int j = i+1; j < meret; j++)
        {
            if (lnko(t[i], t[j]) != 1)
            {
                valasz = 0;
                break;
            }
        }
    }
    return valasz;
}

/*
Karaktertömben 
*/
void csere_szokozre(char s[])
{
    int hossz = strlen(s);
    for (int i = 0; i < hossz; i++)
    {
        if(!isalpha(s[i]))
        {
            s[i] = ' ';
        }
    }
}


// ****main****
int main()
{
    int nev[]={-5,9,1,33,52};
    printf("Max = %d\n", keres_max(nev,5));

    int meret = sizeof(nev)/sizeof(nev[0]);

    rendez_novekvo(nev,meret);
    print_tomb(nev, meret);

    printf("%d\n", is_relative_prim(nev, meret));

    return 0;
}