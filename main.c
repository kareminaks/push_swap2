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
	int n  = push_small(list_a, list_b, median, depth)
	rra_n(list_a, depth-n)
	sortlist_a(list_a, list_b, depth-n)
	sortlist_b(list_b, list_a, n)
	pa_n(list_b, list_a, n)
}

void sortlist_b(list_t * list_b, list_t * list_a, int depth)
{
	int median;
	if (depth<3)
	{
		smallsort_b(list_a, list_b, depth);
		return;
	}
	median = get_median(list_a, depth);
	int n  = push_small(list_a, list_b, median, depth)
	rra_n(list_a, depth-n)
	sortlist_a(list_a, list_b, depth-n)
	sortlist_b(list_b, list_a, n)
	pa_n(list_b, list_a, n)
}
int get_median(list_t * list, int depth)
{

}

int push_small(list_t*list_a, list_t* list_b, int median, int depth)
{

}
void smallsort_a(list_t *list_a, int depth)
{
	if (depth < 2)
	return;
	if (list_a->head->val < list_a->head->next-> val)
	return;
	sa();
}

void rra_n функция которая сделаут n раз rra 
int	main(int argc, char **argv)
{

	check_input(argc, argv);
	list_t list_a = new_list();
	// list_t list_b = new_list();
	fill_list_a(argc, argv, &list_a);
}
