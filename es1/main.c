/*
Creare un programma in linguaggio C che legga il file vgsales.csv e lo importi in un array di strutture.
Ogni riga contiene i campi separati da virgole, per cui può essere comodo creare una funzione split
che dalla riga letta ritorni la struttura valorizzata.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 1024
#define L_VET 16600

// Rank,Name,Platform,Year,Genre,Publisher,NA_Sales,EU_Sales,JP_Sales,Other_Sales,Global_Sales
typedef struct
{
    int rank;
    char *name;
    char *platform;
    int year;
    char *genre;
    char *publisher;
    float na_sales;
    float eu_sales;
    float jp_sales;
    float other_sales;
    float global_sales;
} Game;

int main(int argc, char const *argv[])
{
    Game giochi[L_VET];
    Game *a;

    a = giochi;

    // APERTURA FILE
    FILE *fp;

    char riga[DIM];

    fp = fopen("vgsales.csv", "r");

    // CONTROLLO APERTURA FILE
    if (fp == NULL)
    {
        printf("errore file");
        return 0;
    }

    printf("SB: file aperto");

    int i = 0;

    // legge un intera stringa alla volta, 3 parametri: (array della riga, dimensione array, file)
    while (fgets(riga, DIM, fp)) // finche' non trova la fine del file
    {
        // strtok divide l'array della riga in token
        // -> passaggio struttura per indirizzo 
        (a + i)->rank = atoi(strtok(riga, ","));
        (a + i)->name = strtok(NULL, ",");
        (a + i)->platform = strtok(NULL, ",");
        (a + i)->year = atoi(strtok(NULL, ","));
        (a + i)->genre = strtok(NULL, ",");
        (a + i)->publisher = strtok(NULL, ",");
        (a + i)->na_sales = atof(strtok(NULL, ","));
        (a + i)->eu_sales = atof(strtok(NULL, ","));
        (a + i)->jp_sales = atof(strtok(NULL, ","));
        (a + i)->other_sales = atof(strtok(NULL, ","));
        (a + i)->global_sales = atof(strtok(NULL, "\n"));

        printf("\n\nrank: %d\nname: %s \nplatform: %s \nyear: %d \ngenre: %s \npublisher: %s \nna_sales: %.2f \neu_sales: %.2f \njp_sales: %.2f \nother_sales: %.2f \nglobal_sales: %.2f",
               (a + i)->rank, (a + i)->name, (a + i)->platform, (a + i)->year, (a + i)->genre, (a + i)->publisher, (a + i)->na_sales, (a + i)->eu_sales, (a + i)->jp_sales, (a + i)->other_sales, (a + i)->global_sales);

        i++;

        /*
        METODO ALTERNATIVO
        //. passaggio per valore
        (*a).rank = atoi(strtok(riga, ","));
        (*a).name = strtok(NULL, ",");
        (*a).platform = strtok(NULL, ",");
        (*a).year = atoi(strtok(NULL, ","));
        (*a).genre = strtok(NULL, ",");
        (*a).publisher = strtok(NULL, ",");
        (*a).na_sales = atof(strtok(NULL, ","));
        (*a).eu_sales = atof(strtok(NULL, ","));
        (*a).jp_sales = atof(strtok(NULL, ","));
        (*a).other_sales = atof(strtok(NULL, ","));
        (*a).>global_sales = atof(strtok(NULL, "\n"));

        printf("\n\nrank: %d\nname: %s \nplatform: %s \nyear: %d \ngenre: %s \npublisher: %s \nna_sales: %.2f \neu_sales: %.2f \njp_sales: %.2f \nother_sales: %.2f \nglobal_sales: %.2f",
               (*a).rank, (*a).name, (*a).platform, (*a).year, (*a).genre, (*a).publisher, (*a).na_sales, (*a).eu_sales, (*a).jp_sales, (*a).other_sales, (*a).global_sales);

        a++;
        */
    }
    
    // CHIUSURA FILE
    fclose(fp);
    return 1;
}
