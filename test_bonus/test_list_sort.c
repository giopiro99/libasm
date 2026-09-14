#include "../test_bonus.h"

extern int  ft_list_sort(t_list **begin_list, int (*cmp)());
extern int  ft_strcmp(char *str1, char *str2);

void    test_my_list_sort1(){
    printf("========TEST 1: My List Sort========\n");

    t_list  *node1 = malloc(sizeof(t_list));
    t_list  *node2 = malloc(sizeof(t_list));;
    t_list  *node3 = malloc(sizeof(t_list));;

    node1->next = node2;
    node1->data = "3";
    node2->next = node3;
    node2->data = "1";
    node3->next = NULL;
    node3->data = "0";

    ft_list_sort(&node1, ft_strcmp);
    t_list  *current = node1;
    while (current != NULL){
        printf("%s\n", (char *)current->data);
        current = current->next;
    }

    free(node1);
    free(node2);
    free(node3);

    printf("===================================\n\n");
}

void    test_my_list_sort2(){
    printf("========TEST 2: My List Sort========\n");
    t_list  *node1 = malloc(sizeof(t_list));
    t_list  *node2 = malloc(sizeof(t_list));;
    t_list  *node3 = malloc(sizeof(t_list));;
    t_list  *node4 = malloc(sizeof(t_list));;
    t_list  *node5 = malloc(sizeof(t_list));;
    t_list  *node6 = malloc(sizeof(t_list));;

    node1->next = node2;
    node1->data = "9";
    node2->next = node3;
    node2->data = "3";
    node3->next = node4;
    node3->data = "2";
    node4->next = node5;
    node4->data = "8";
    node5->next = node6;
    node5->data = "1";
    node6->next = NULL;
    node6->data = "0";

    ft_list_sort(&node1, ft_strcmp);
    t_list  *current = node1;
    while (current != NULL){
        printf("%s\n", (char *)current->data);
        current = current->next;
    }

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);

    printf("======================================\n\n");
}

void    test_my_list_sort3(){
    printf("========TEST 3: My List Sort========\n");
    t_list  *node1 = malloc(sizeof(t_list));
    node1->next = NULL;
    node1->data = "1";

    ft_list_sort(&node1, (ft_strcmp));

    t_list  *current = node1;
    while (current != NULL){
        printf("%s\n", (char *)current->data);
        current = current->next;
    }

    free(node1);

    printf("==========================================\n\n");
}

void    test_my_list_sort4(){
    printf("========TEST 4: My List Sort========\n");
    t_list  *node1 = malloc(sizeof(t_list));
    t_list  *node2 = malloc(sizeof(t_list));

    node1->next = node2;
    node1->data = "2";
    node2->next = NULL;
    node2->data = "1";

    ft_list_sort(&node1, (ft_strcmp));

    t_list  *current = node1;
    while (current != NULL){
        printf("%s\n", (char *)current->data);
        current = current->next;
    }

    free(node1);
    free(node2);

    printf("===================================================\n\n");
}

/*======================================================================================================================================*/
/*======================================================================================================================================*/
/*======================================================================================================================================*/


void    test_list_sort1(){
    printf("========TEST 1: List Sort========\n");

    t_list  *node1 = malloc(sizeof(t_list));
    t_list  *node2 = malloc(sizeof(t_list));;
    t_list  *node3 = malloc(sizeof(t_list));;

    node1->next = node2;
    node1->data = "3";
    node2->next = node3;
    node2->data = "1";
    node3->next = NULL;
    node3->data = "0";

    ft_list_sort(&node1, ft_strcmp);
    t_list  *current = node1;
    while (current != NULL){
        printf("%s\n", (char *)current->data);
        current = current->next;
    }

    free(node1);
    free(node2);
    free(node3);

    printf("===================================\n\n");
}

void    test_list_sort2(){
    printf("========TEST 2: List Sort========\n");
    t_list  *node1 = malloc(sizeof(t_list));
    t_list  *node2 = malloc(sizeof(t_list));;
    t_list  *node3 = malloc(sizeof(t_list));;
    t_list  *node4 = malloc(sizeof(t_list));;
    t_list  *node5 = malloc(sizeof(t_list));;
    t_list  *node6 = malloc(sizeof(t_list));;

    node1->next = node2;
    node1->data = "9";
    node2->next = node3;
    node2->data = "3";
    node3->next = node4;
    node3->data = "2";
    node4->next = node5;
    node4->data = "8";
    node5->next = node6;
    node5->data = "1";
    node6->next = NULL;
    node6->data = "0";

    ft_list_sort(&node1, ft_strcmp);
    t_list  *current = node1;
    while (current != NULL){
        printf("%s\n", (char *)current->data);
        current = current->next;
    }

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);

    printf("======================================\n\n");
}

void    test_list_sort3(){
    printf("========TEST 3: List Sort========\n");
    t_list  *node1 = malloc(sizeof(t_list));
    node1->next = NULL;
    node1->data = "1";

    ft_list_sort(&node1, (ft_strcmp));

    t_list  *current = node1;
    while (current != NULL){
        printf("%s\n", (char *)current->data);
        current = current->next;
    }

    free(node1);
    printf("==========================================\n\n");
}

void    test_list_sort4(){
    printf("========TEST 4: List Sort========\n");
    t_list  *node1 = malloc(sizeof(t_list));
    t_list  *node2 = malloc(sizeof(t_list));

    node1->next = node2;
    node1->data = "2";
    node2->next = NULL;
    node2->data = "1";

    ft_list_sort(&node1, (ft_strcmp));

    t_list  *current = node1;
    while (current != NULL){
        printf("%s\n", (char *)current->data);
        current = current->next;
    }

    free(node1);
    free(node2);

    printf("===================================================\n\n");
}