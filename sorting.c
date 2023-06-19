#include "push_swap.h"

void sortlist_a(list_t * list_a, list_t * list_b, int depth,list_t *command_list)
{
	int median;
	if (depth<3)
	{
		smallsort_a(list_a, depth,command_list);
		return;
	}
	median = get_median(list_a, depth);
	// printf("median: %d\n", median);
	int n  = push_small_tob(list_a, list_b, median, depth,command_list);
	// printf("rra_n: limit=%d\n",depth-n);
	rra_n(list_a, depth-n,command_list);
	sortlist_a(list_a, list_b, depth-n,command_list);
	sortlist_b(list_b, list_a, n,command_list);
	pa_n(list_a, list_b, n,command_list);
}

void sortlist_b(list_t * list_b, list_t * list_a, int depth,list_t *command_list)
{
	int median;
	if (depth<3)
	{
		smallsort_b(list_b, depth,command_list);
		return;
	}
	median = get_median(list_b, depth);
	int n  = push_big_toa(list_b, list_a, median, depth,command_list);
	rrb_n(list_b, depth-n,command_list);
	sortlist_a(list_a, list_b, n,command_list);
	sortlist_b(list_b, list_a, depth-n,command_list);
	pb_n(list_b, list_a, n,command_list);
}

int get_median(list_t * list, int depth)
{
    long long sum =0;
    int i=0;
    node_t* ptr = list->head;
    while (i < depth)
    {
        sum+=ptr->val;
        ptr = ptr->next;
        i++;
    }
	return(sum/(long long)depth);
}

int push_big_toa(list_t*list_b, list_t* list_a, int median, int depth,list_t *command_list)
{
    int moved=0;
    int i=0;

    while (i<depth)
    {
        if (list_b->head->val > median)
        {
            pa(list_a, list_b,1,command_list);
            moved++;
        }
        else
        {
            rb(list_b,1,command_list);
        }
        i++;
    }
    return(moved);
}

int push_small_tob(list_t*list_a, list_t* list_b, int median, int depth,list_t *command_list)
{
    int moved=0;
    int i=0;
    node_t* ptr = list_a->head;

    while (i<depth)
    {
		ptr = list_a->head;
        if (ptr->val <= median)
        {
            pb(list_b, list_a,1,command_list);
            moved++;
        }
        else
        {
            ra(list_a,1,command_list);
        }
        i++;
    }
    return(moved);
}

void smallsort_a(list_t *list_a, int depth,list_t *command_list)
{
	if (depth < 2)
	return;
	if (list_a->head->val < list_a->head->next-> val)
	return;
	sa(list_a, 1,command_list);
}

void smallsort_b(list_t *list_b, int depth,list_t *command_list)
{
	// printf("smallsort (depth %d)\n", depth);
	if (depth < 2)
	return;

	// printf("head %d prev %d\n", list_b->head->val, list_b->head->next-> val);
	// print_list(list_b);

	if (list_b->head->val > list_b->head->next-> val)
	return;
	sb(list_b, 1,command_list);
}

//функция которая сделаут n раз rra 
void rra_n(list_t* list_a, int n,list_t *command_list)
{
    int i = 0;
    while (i < n)
    {
        rra(list_a, 1,command_list);
        i++;
    }
}
//функция которая сделаут n раз rrb
void rrb_n(list_t* list_b, int n,list_t *command_list)
{
    int i = 0;
    while (i < n)
    {
        rrb(list_b, 1,command_list);
        i++;
    }
}


void pa_n(list_t * list_a, list_t * list_b, int n,list_t *command_list)
{
	int i =0;
	while (i<n)
	{
		pa(list_a, list_b,1,command_list);
		i++;
	}
}

void pb_n(list_t * list_b, list_t * list_a, int n,list_t *command_list)
{
	int i =0;
	while (i<n)
	{
		pb(list_b, list_a,1,command_list);
		i++;
	}
}