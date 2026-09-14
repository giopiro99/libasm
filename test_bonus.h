#ifndef TEST_BONUS_H
# define TEST_BONUS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_list
{
    void            *data;
    struct s_list   *next;
} t_list;

/*======TEST PER ATOI======*/
int atoi_base(char *str, char *base);
void    test_atoi_base1();
void    test_atoi_base2();
void    test_atoi_base3();
void    test_atoi_base4();

/*======TEST PER LIST PUSH FRONT======*/
void    list_push_front(t_list **begin_list, void *data);
void    test_list_push_front1();
void    test_list_push_front2();
void    test_list_push_front3();
void    test_list_push_front4();
void    test_atoi_base5();

/*======TEST PER LIST SIZE======*/
int list_size(t_list *begin_list);
void    test_list_size1();
void    test_list_size2();
void    test_list_size3();
void    test_list_size4();

/*======TEST PER LIST SORT======*/
void list_sort(t_list **begin_list, int (*cmp)());
void    test_list_sort1();
void    test_list_sort2();
void    test_list_sort3();
void    test_list_sort4();
void    test_my_list_sort1();
void    test_my_list_sort2();
void    test_my_list_sort3();
void    test_my_list_sort4();
#endif