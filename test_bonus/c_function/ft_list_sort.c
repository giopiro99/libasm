#include "../../test_bonus.h"

//void list_sort(t_list **begin_list, int (*cmp)(void*, void*)) per togliere alert
void list_sort(t_list **begin_list, int (*cmp)()){

    if (begin_list == NULL || *begin_list == NULL) return;

    if (cmp == NULL) return ;

    while (1){
        t_list  *current = *begin_list;
        bool    has_swapped = false;
        while (current->next != NULL){
            if ((cmp)(current->data, current->next->data) > 0){
                has_swapped = true;
                void    *swap = current->data;
                current->data = current->next->data;
                current->next->data = swap;
            }

            current = current->next;
        }
        if (!has_swapped) return;
    }
}