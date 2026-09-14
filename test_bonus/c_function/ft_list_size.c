#include "../../test_bonus.h"

int list_size(t_list *begin_list){

    int     list_size = 0;
    t_list  *current = begin_list;
    while (current != NULL){
        list_size++;
        current = current->next;
    }

    return (list_size);
}