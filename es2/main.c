/*
ordinamento bubble sort di un array senza le []
*/

#include <stdio.h>
#include <stdlib.h>

#define DIM 5

int main(int argc, char const *argv[])
{
    int *v;

    //malloc
    v = (int *)malloc(sizeof(int) * DIM);

    //caricamento vettore
    for (int i = 0; i < DIM; i++)
    {
        printf("%d: ", i + 1);
        scanf("%d", (v + i));
    }

    printf("\n");

    //variabile temporanea
    int temp = 0;

    //bubble sort di ordinamento crescente
    for (int i = 1; i < DIM; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (*(v + i) < *(v + j))
            {
                temp = *(v + i);
                *(v + i) = *(v + j);
                *(v + j) = temp;
            }
        }
    }

    //stampa vettore
    for (int i = 0; i < DIM; i++)
    {
        printf("%d ", *(v + i));
    }

    printf("\n");

    //liberazione memoria
    free(v);

    return 0;
}
