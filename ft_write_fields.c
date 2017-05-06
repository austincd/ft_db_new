#include "ft_db.h"

int ft_write_fields(t_dbinfo *dbmeta, int fd)
{
	long long	counter;
	int			llsize;

	counter = 0;
	llsize = sizeof(long long);
	if (dbmeta)
	{
		if (dbmeta->fields)
		{
			lseek(fd, llsize * 3, SEEK_SET);
			while (counter < dbmeta->field_cap)
			{
				write(fd, dbmeta->fields[counter], sizeof(t_field));
				++counter;
			}
			return (1);
		}
	}
	return (-1);
}
