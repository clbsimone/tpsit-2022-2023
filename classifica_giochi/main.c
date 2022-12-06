#include <stdio.h>
#include <stdlib.h>

#define DIM 10
typedef struct node {
    char nome[DIM];
    int punteggio;
    struct node *next;
} Node;

void inserimentoOrdinato(Node **head, Node *element) {
    Node *curr = *head, *prev = NULL;

    while (curr != NULL) {
        if (element->punteggio >= curr->punteggio)
            break;

        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL)
        *head = element;
    else
        prev->next = element;

    element->next = curr;
}

void printList(Node *head) {
    printf("\n\n");

    while (head != NULL) {
        printf("%s -> %d\n", head->nome, head->punteggio);
        head = head->next;
    }
}

void freeList(Node *testa) {
    Node *tmp;

    while (testa != NULL) {
        tmp = testa;
        testa = testa->next;
        free(tmp);
    }
}

int main(int argc, char const *argv[]) {
    Node *head = NULL;
    Node *new_node = NULL;
    int n_giochi;

    printf("n giochi:");
    scanf("%d", &n_giochi);

    for (int i = 0; i < n_giochi; i++) {
        new_node = (Node *) malloc(sizeof(Node));

        printf("nome: ");
        scanf("%s", new_node->nome);

        printf("punteggio: ");
        scanf("%d", &new_node->punteggio);

        inserimentoOrdinato(&head, new_node);
    }

    printList(head);
    freeList(head);

    return 0;
}
