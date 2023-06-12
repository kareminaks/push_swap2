#include "push_swap.h"


//creates new node
node_t* new_node(int value)
 {
    node_t* head = (node_t *) malloc(sizeof(node_t));
    if (!head) return 0;
    head->val = value;
    head->next = NULL;
    head->prev = NULL;
    return head;
}

//creates new list
list_t new_list(void)
{
    list_t res;
    res.head = 0;
    res.tail = 0;
    return(res);
}
