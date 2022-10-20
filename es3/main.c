/*
- Creare un file .csv con COGNOME, NOME, NASCITA (annomesegiorno formato int)
- scorre il file con la funzione FGETS e STRTOK
- stampare in ordine DECRESCENTE (dal più grande al più piccolo) utilizzando i puntatori e allocazione dinamica (MALLOC)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUNG 1024

// struttutra persona
typedef struct
{
    char *surname;
    char *name;
    int date;
} Persona;

int readFile(FILE *fp, char *riga, int lung)
{
    int i = 0;

    while (fgets(riga, lung, fp))
    {
        i++;
    }

    return i;
}

void oridnaDecrescente(Persona *p, int dim)
{
    for (int i = dim - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if ((p + i)->date < (p + j)->date)
            {
                Persona temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
        }
    }
}

void printStruct(Persona *p, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        printf("surname: %s, name: %s, date: %d\n", (p + i)->surname, (p + i)->name, (p + i)->date);
    }
}

void spezzoRiga(FILE *fp, char *riga, int lung, Persona *p, int dim)
{
    int i = 0;

    while (fgets(riga, LUNG, fp))
    {
        (p + i)->surname = strdup(strtok(riga, ","));
        (p + i)->name = strdup(strtok(NULL, ","));
        (p + i)->date = atoi(strtok(NULL, ","));

        i++;
    }

    printf("\n");
}

int main(int argc, char const *argv[])
{
    Persona *p;
    char *riga;
    int dim;

    FILE *fp;
    fp = fopen("file.csv", "r");

    if (fp == NULL)
    {
        printf("errore file");
        return 0;
    }
    else
    {
        // malloc
        riga = (char *)malloc(sizeof(char) * LUNG);

        // numero righe nel file
        dim = readFile(fp, riga, LUNG);
        fclose(fp);

        fp = fopen("file.csv", "r");

        if (fp == NULL)
        {
            printf("errore file");
            return 1;
        }
        else
        {
            // malloc vet p numero di persone presenti nel file
            p = (Persona *)malloc(sizeof(Persona) * dim);

            int i = 0;

            // spezzo le righe e le assegno alla struttura Persona
            spezzoRiga(fp, riga, LUNG, p, dim);

            // ordinamento struttura per date
            oridnaDecrescente(p, dim);

            // stampa struttura
            printStruct(p, dim);
        }
    }

    free(riga);
    free(p);

    fclose(fp);

    return 2;
}
