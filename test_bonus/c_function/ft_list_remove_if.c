#include "../../test_bonus.h"

void list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *)){

    if (begin_list == NULL || *begin_list == NULL) return ;

    if (data_ref == NULL) return ;

    if (cmp == NULL) return ;

    if (free_fct == NULL) return;

    t_list  *current = *begin_list;
    t_list  *prev = NULL;

    while (current != NULL){
        if (cmp(current->data, data_ref) == 0){
            t_list  *next = current->next;
            if (current == *begin_list){
                *begin_list = next;
            }
            else{
                if (prev){
                    prev->next = next;
                }
            }
            free_fct(current->data);
            free(current);
            current= next;
        }else{
            prev = current;
            current = current->next;
        }
    }
}