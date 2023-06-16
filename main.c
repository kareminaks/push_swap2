#include "push_swap.h"

void sortlist_a(list_t * list_a, list_t * list_b, int depth)
{
	int median;
	if (depth<3)
	{
		smallsort_a(list_a, depth);
		return;
	}
	median = get_median(list_a, depth);
	printf("median: %d\n", median);
	int n  = push_small_tob(list_a, list_b, median, depth);
	rra_n(list_a, depth-n);
	sortlist_a(list_a, list_b, depth-n);
	sortlist_b(list_b, list_a, n);
	pa_n(list_a, list_b, n);
}

void sortlist_b(list_t * list_b, list_t * list_a, int depth)
{
	int median;
	if (depth<3)
	{
		smallsort_b(list_b, depth);
		return;
	}
	median = get_median(list_b, depth);
	int n  = push_big_toa(list_b, list_a, median, depth);
	rrb_n(list_a, depth-n);
	sortlist_a(list_a, list_b, n);
	sortlist_b(list_b, list_a, depth-n);
	pb_n(list_b, list_a, n);
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

int push_big_toa(list_t*list_b, list_t* list_a, int median, int depth)
{
    int moved=0;
    int i=0;
    node_t* ptr = list_b->head;

    while (i<depth)
    {
		ptr = list_b->head;
        if (ptr->val > median)
        {
            pa(list_a, list_b,1);
            moved++;
        }
        else
        {
            rb(list_b,1);
        }
        i++;
    }
    return(moved);
}

int push_small_tob(list_t*list_a, list_t* list_b, int median, int depth)
{
    int moved=0;
    int i=0;
    node_t* ptr = list_a->head;

    while (i<depth)
    {
		ptr = list_a->head;
        if (ptr->val <= median)
        {
            pb(list_b, list_a,1);
            moved++;
        }
        else
        {
            ra(list_a,1);
        }
        i++;
    }
    return(moved);
}

void smallsort_a(list_t *list_a, int depth)
{
	if (depth < 2)
	return;
	if (list_a->head->val < list_a->head->next-> val)
	return;
	sa(list_a, 1);
}

void smallsort_b(list_t *list_b, int depth)
{
	// printf("smallsort (depth %d)\n", depth);
	if (depth < 2)
	return;

	// printf("head %d prev %d\n", list_b->head->val, list_b->head->next-> val);
	// print_list(list_b);

	if (list_b->head->val > list_b->head->next-> val)
	return;
	sb(list_b, 1);
}

//функция которая сделаут n раз rra 
void rra_n(list_t* list_a, int n)
{
    int i = 0;
    while (i < n)
    {
        rra(list_a, 1);
        i++;
    }
}
//функция которая сделаут n раз rrb
void rrb_n(list_t* list_b, int n)
{
    int i = 0;
    while (i < n)
    {
        rrb(list_b, 1);
        i++;
    }
}


void pa_n(list_t * list_a, list_t * list_b, int n)
{
	int i =0;
	while (i<n)
	{
		pa(list_a, list_b,1);
		i++;
	}
}

void pb_n(list_t * list_b, list_t * list_a, int n)
{
	int i =0;
	while (i<n)
	{
		pb(list_b, list_a,1);
		i++;
	}
}
int	main(int argc, char **argv)
{

	check_input(argc, argv);
	list_t list_a = new_list();
	list_t list_b = new_list();
	fill_list_a(argc, argv, &list_a);
	sortlist_a( &list_a ,&list_b, argc-1);
}

void print_list( list_t * list)
{
	if (!list)
	{
		printf("nil");
		return;
	}
	printf("head=%p tail=%p\n", list->head, list->tail);
	if (list->head == 0)
		return;

	if (list->head->prev)
		printf("ACHTUNG: head->prev != 0\n");
	if (list->tail->next)
		printf("ACHTUNG: tail->next != 0\n");
	node_t* ptr=list->head;
	while (ptr!= 0)
	{
		printf("%d ", ptr->val);
		ptr=ptr->next;
	}
		printf("\n");
}