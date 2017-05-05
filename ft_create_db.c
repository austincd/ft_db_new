#include "ft_db.h"

int	ft_create_db(char *filename, long long field_cap)
{
	int		new;
	void	*temp;
	int		llsize;
	int		size;

	new = -1;
	llsize = sizeof(long long);
	size = field_cap * (llsize + 32);
	if (filename)
	{
		new = ft_create_file(ft_strjoin(filename, ".ftdb"));
		if (new > 0)
		{
			temp = ft_memalloc((llsize * 3) + 32);
			write(new, temp, llsize * 2);
			write(new, &field_cap, llsize * 1);
			while (size)
				size -= write(new, temp, llsize + 32);
			free(temp);
			return (new);
		}
	}
	return (-1);
}
