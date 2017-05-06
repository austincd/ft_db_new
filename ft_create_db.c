#include "ft_db.h"

int	ft_create_db(char *filename, long long field_cap)
{
	int		new;
	void	*temp;
	int		llsize;
	int		size;

	new = -1;
	llsize = sizeof(long long);
	size = field_cap * sizeof(t_field);
	if (filename)
	{
		new = ft_create_file(ft_strjoin(filename, ".ftdb"));
		if (new > 0)
		{
			temp = ft_memalloc((llsize * 3) + sizeof(t_field));
			write(new, temp, llsize * 2);
			write(new, &field_cap, llsize * 1);
			while (size)
				size -= write(new, temp, sizeof(t_field));
			free(temp);
			return (new);
		}
	}
	return (-1);
}
