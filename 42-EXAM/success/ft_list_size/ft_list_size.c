
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
	int count = 1;
	t_list *next = begin_list->next;

	while (next)
	{
		next = next->next;
		count++;
	}
	return count;
}
