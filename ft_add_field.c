#include "ft_db.h"

long long	ft_add_field(t_dbinfo *dbmeta, int fd, char *field_name, short id)
{
	void		*ptr;
	long long	counter;
	int			llsize;
	int			ssize;

	counter = 0;
	llsize = sizeof(long long);
	ssize = sizeof(short);
	ptr = ft_memalloc(llsize + ssize + 32);
	lseek(fd, llsize * 3, SEEK_SET);
	while (read(fd, ptr, (llsize + ssize + 32)) == llsize + ssize + 32 && counter < dbmeta->field_cap)
	{
		if (!(*(short*)(ptr + llsize)))
		{
			(*(short*)(ptr + llsize)) = id;
			ft_strlcpy(ptr + llsize + ssize, field_name, 32);
			dbmeta->num_fields = counter + 1;
			ft_write_dbmeta(dbmeta, fd);
			return (counter);
		}
		++counter;
	}
	return (-1);
}
