#include "ft_db.h"

int ft_create_field(int fd, char *name, short id)
{
	void	*new;
	if (name && fd && id)
	{
		if (id == 1)
			new = (t_field_d*)ft_memalloc(sizeof(t_field_d));
		else if (id == 2)
			new = (t_field_ud*)ft_memalloc(sizeof(t_field_ud));
		else if (id == 3)
			new = (t_field_c*)ft_memalloc(sizeof(t_field_c));
		else if (id == 4)
			new = (t_field_s16*)ft_memalloc(sizeof(t_field_s16));
		else if (id == 5)
			new = (t_field_s256*)ft_memalloc(sizeof(t_field_s256));
		else if (new)
			{
			new->id = id;
			return (1);
			}
	}
	return (-1);
}
