#include "ft_db.h"

int ft_write_fields(t_dbinfo *dbmeta, int fd)
{
	long long	to_write;
	int			llsize;
	int			status;
	void		*temp;

	to_write = 0;
	llsize = sizeof(long long);
	if (dbmeta)
	{
		if (dbmeta->fields)
		{
			to_write = sizeof(t_finfo) * dbmeta->field_cap;
			lseek(fd, llsize * 3, SEEK_SET);
			temp = dbmeta->fields;
			while (to_write)
			{
				if (to_write > 512)
					status = write(fd, temp, 512);
				else
					status = write(fd, temp, to_write);
				temp += status;
				to_write -= status;
			}
			return (1);
		}
	}
	return (-1);
}
