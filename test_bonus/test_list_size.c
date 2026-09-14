#include "../test_bonus.h"

extern int ft_list_size(t_list *begin_list);

void    test_list_size1(){
    printf("========TEST 1: List Size========\n");

    t_list  *node1 = malloc(sizeof(t_list));
    t_list  *node2 = malloc(sizeof(t_list));;
    t_list  *node3 = malloc(sizeof(t_list));;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    int     result = list_size(node1);
    printf("risultato di list size =%d\n", result);
    result = ft_list_size(node1);
    printf("risultato di list size in assembly =%d\n", result);
    free(node1);
    free(node2);
    free(node3);

    printf("===================================\n\n");
}

void    test_list_size2(){
    printf("========TEST 2: List Size========\n");

    int     result = list_size(NULL);
    printf("risultato di list size =%d\n", result);
    result = ft_list_size(NULL);
    printf("risultato di list size in assembly =%d\n", result);
    printf("======================================\n\n");
}

void    test_list_size3(){
    printf("========TEST 3: List Size========\n");
    t_list  *node1 = malloc(sizeof(t_list));
    node1->next = NULL;

    int     result = list_size(node1);
    printf("risultato di list size =%d\n", result);
    result = ft_list_size(node1);
    printf("risultato di list size in assembly =%d\n", result);
    free(node1);
    printf("==========================================\n\n");
}

void    test_list_size4(){
    printf("========TEST 4: List Size========\n");
    t_list  *node1 = malloc(sizeof(t_list));
    t_list  *node2 = malloc(sizeof(t_list));

    node1->next = node2;
    node2->next = NULL;

    int     result = list_size(node1);
    printf("risultato di list size =%d\n", result);
    result = ft_list_size(node1);
    printf("risultato di list size in assembly =%d\n", result);

    free(node1);
    free(node2);

    printf("===================================================\n\n");
}