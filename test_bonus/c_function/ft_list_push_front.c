#include "../../test_bonus.h"
#include <stdlib.h>

void    list_push_front(t_list **begin_list, void *data){
    if (!begin_list){
        return ;
    }

    t_list  *new_node = malloc(sizeof(t_list));
    if (!new_node) return ;

    new_node->data = data;
    new_node->next = *begin_list;
    *begin_list = new_node;
    return ;
}