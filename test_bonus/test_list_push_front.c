#include "../test_bonus.h"
#include <stdio.h>
#include <stdlib.h>

extern void ft_list_push_front(t_list **begin_list, void *data);

void    test_list_push_front1(){
    printf("========TEST 1: Lista vuota========\n");
    t_list *head = NULL;
    char *str = "Primo e unico nodo";

    ft_list_push_front(&head, str);
    
    if (head)
        printf("Data in testa: %s\n", (char *)head->data);
    else
        printf("ERRORE: head e' ancora NULL\n");
    printf("===================================\n\n");
}

void    test_list_push_front2(){
    printf("========TEST 2: Lista popolata========\n");
    t_list *head = NULL;
    char *str1 = "Vecchio capolista";
    char *str2 = "Nuovo capolista";
    
    ft_list_push_front(&head, str1);
    ft_list_push_front(&head, str2);
    
    if (head && head->next) {
        printf("Nodo 1 (Testa): %s\n", (char *)head->data);
        printf("Nodo 2 (Next) : %s\n", (char *)head->next->data);
    }
    printf("======================================\n\n");
}

void    test_list_push_front3(){
    printf("========TEST 3: begin_list e' NULL========\n");
    char *str = "Non devo crashare";

    ft_list_push_front(NULL, str);
    
    printf("Se leggi questo, il check anti-NULL in ASM funziona.\n");
    printf("==========================================\n\n");
}

void    test_list_push_front4(){
    printf("========TEST 4: Ordine multiplo e Indirizzi========\n");
    t_list *head = NULL;
    
    ft_list_push_front(&head, "Terzo (Inserito per primo)");
    ft_list_push_front(&head, "Secondo (Inserito per secondo)");
    ft_list_push_front(&head, "Primo (Inserito per ultimo, ora in testa)");
    
    t_list *tmp = head;
    int i = 0;
    while (tmp) {
        // Stampo non solo il dato, ma anche l'indirizzo fisico in RAM
        printf("Nodo %d: %-40s | RAM: %p\n", i, (char *)tmp->data, (void *)tmp);
        tmp = tmp->next;
        i++;
    }
    printf("===================================================\n\n");
}