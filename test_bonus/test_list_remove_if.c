#include "../test_bonus.h"

extern void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
extern int  ft_strcmp(char *s1, char *s2);

void    test_list_remove_if1(){
    printf("========TEST 1: List remove if========\n");

    t_list  *node1 = malloc(sizeof(t_list));
    t_list  *node2 = malloc(sizeof(t_list));;
    t_list  *node3 = malloc(sizeof(t_list));;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    printf("risultato di List remove if =\n");
    printf("risultato di List remove if in assembly =\n");
    free(node1);
    free(node2);
    free(node3);

    printf("===================================\n\n");
}

void    test_list_remove_if2(){
    printf("========TEST 2: List remove if========\n");

    printf("risultato di List remove if =\n");
    printf("risultato di List remove if in assembly =\n");
    printf("======================================\n\n");
}

void    test_list_remove_if3(){
    printf("========TEST 3: List remove if========\n");
    t_list  *node1 = malloc(sizeof(t_list));
    node1->next = NULL;

    printf("risultato di List remove if =\n");
    printf("risultato di List remove if in assembly =\n");
    free(node1);
    printf("==========================================\n\n");
}

void    test_list_remove_if4(){
    printf("========TEST 4: List remove if========\n");
    t_list  *node1 = malloc(sizeof(t_list));
    t_list  *node2 = malloc(sizeof(t_list));

    node1->next = node2;
    node2->next = NULL;

    printf("risultato di List remove if =\n");
    printf("risultato di List remove if in assembly =\n");

    free(node1);
    free(node2);

    printf("===================================================\n\n");
}