/*
ordinamento bubble sort di un array senza le []
*/

#include <stdio.h>
#include <stdlib.h>

#define DIM 5

int main(int argc, char const *argv[])
{
    int *v;
    
    v = (int *)malloc(sizeof(int) * DIM);

    for (int i = 0; i < DIM; i++)
    {
        printf("%d: ", i + 1);
        scanf("%d", (v + i));
    }

    printf("\n");

    int temp = 0;

    for (int i = 0; i < DIM - 1; i++)
    {
        for (int j = 0; j < DIM - i - 1; j++)
        {
            if (*(v + i) > *(v + i + 1))
            {
                temp = *(v + i);
                *(v + i) = *(v + i + 1);
                *(v + i + 1) = temp;
            }
        }
    }

    for (int i = 0; i < DIM; i++)
    {
        printf("%d ", *(v + i));
    }

    printf("\n");

    free(v);
    return 0;
}
