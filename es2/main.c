/*
ordinamento bubble sort di un array senza le []
*/

#include <stdio.h>
#include <stdlib.h>

//lettura della lunghezza
int leggiNum()
{
    int n;

    do
    {
        scanf("%d", &n);
    } while (n < 0);

    return n;
}

// bubble sort di ordinamento crescente
void bubbleSort(int *v, int dim)
{
    int temp = 0;

    for (int i = 1; i < dim; i++)
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
}

void stampaVet(int *v, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        printf("%d ", *(v + i));
    }

    printf("\n");
}

int main(int argc, char const *argv[])
{
    int *v;
    int dim;

    printf("lunghezza: ");
    dim = leggiNum();

    // malloc
    v = (int *)malloc(sizeof(int) * dim);

    //caricamento vettore
    for (int i = 0; i < dim; i++)
    {
        printf("%d: ", i + 1);
        scanf("%d", (v + i));
    }

    printf("\n");

    bubbleSort(v, dim);
    stampaVet(v, dim);
    
    //liberazione memoria
    free(v);

    return 0;
}
