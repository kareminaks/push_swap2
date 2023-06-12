#include "push_swap.h"

int	main(int argc, char **argv)
{

	check_input(argc, argv);
	list_t list_a = new_list();
	// list_t list_b = new_list();
	fill_list_a(argc, argv, &list_a);
}
