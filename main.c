#include "push_swap.h"

void sortlist_a(list_t * list_a, list_t * list_b, int depth)
{
	int median;
	if (depth<3)
	{
		smallsort_a(list_a, list_b, depth);
		return;
	}
	median = get_median(list_a, depth);
	int n  = push_small(list_a, list_b, median, depth);
	rr_n(list_a, depth-n);
	sortlist_a(list_a, list_b, depth-n);
	sortlist_b(list_b, list_a, n);
	pa_n(list_b, list_a, n);
}

void sortlist_b(list_t * list_b, list_t * list_a, int depth)
{
	int median;
	if (depth<3)
	{
		smallsort_b(list_b, list_a, depth);
		return;
	}
	median = get_median(list_b, depth);
	int n  = push_small(list_b, list_a, median, depth);
	rr_n(list_a, depth-n);
	sortlist_a(list_a, list_b, depth-n);
	sortlist_b(list_b, list_a, n);
	pa_n(list_b, list_a, n);
}
int get_median(list_t * list, int depth)
{
    long long sum =0;
    int i=0;
    node_t* ptr = list->head;
    while (i<depth)
    {
        sum+=ptr->val;
        ptr = ptr->next;
        i++;
    }
}

int push_small_toa(list_t*list_a, list_t* list_b, int median, int depth)
{
    int moved=0;
    int i=0;
    node_t* ptr = list_a->head;

    while (i<depth)
    {
        if (ptr->val < median)
        {
            pb(list_a, list_b,1)
            moved++;
        }
        else
        {
            ra(list_a,1)
        }
        i++;
    }
    return(moved);
}
void smallsort_a(list_t *list_a, list_t* list_b, int depth)
{
	if (depth < 2)
	return;
	if (list_a->head->val < list_a->head->next-> val)
	return;
	sa(list_a, 1);
}

void smallsort_b(list_t *list_b, list_t* list_a, int depth)
{
	if (depth < 2)
	return;
	if (list_b->head->val > list_b->head->next-> val)
	return;
	sb(list_b, 1);
}

//функция которая сделаут n раз rra 
void rr_n(list_t* list_a, int n)
{
    int i = 0;
    while (i <= n)
    {
        rra(list_a, 1);
        i++;
    }
    
}
int	main(int argc, char **argv)
{

	check_input(argc, argv);
	list_t list_a = new_list();
	// list_t list_b = new_list();
	fill_list_a(argc, argv, &list_a);
}
