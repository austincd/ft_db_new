#include "ft_db.h"

int ft_update_status(int fd, t_dbinfo *dbmeta)
{
	long long	*llptr;
	int			llsize;

	llsize = sizeof(long long);
	if ((llptr = (long long*)ft_memalloc(llsize * 3)))
	{
		lseek(fd, 0, SEEK_SET);
		if (read (fd, llptr, llsize * 3) == llsize * 3)
		{
			if (llptr[0] != dbmeta->num_fields || \
				llptr[1] != dbmeta->num_records || \
				llptr[2] != dbmeta->field_cap)
			{
				dbmeta->num_fields = llptr[0];
				dbmeta->num_records = llptr[1];
				dbmeta->field_cap = llptr[2];
				ft_refresh(dbmeta, fd);
				dbmeta->offset = (llsize * 3) + dbmeta->field_cap * sizeof(t_field);
				return (1);
			}
			return (0);

		}
	}
	return (-1);
}

int ft_update_fields(int fd, t_dbinfo *dbmeta)
{
	int			llsize;
	t_field		*buff;
	long long	counter;

	counter = 0;
	llsize = sizeof(long long);
	if (dbmeta)
	{
		buff = (t_field*)ft_memalloc(sizeof(t_field));
		lseek(fd, llsize * 3, SEEK_SET);
		while (counter < dbmeta->field_cap)
		{
			read(fd, buff, sizeof(t_field));
			ft_strlcpy(dbmeta->fields[counter]->field_name, buff->field_name, 32);
			dbmeta->fields[counter]->type_id = buff->type_id;
			++counter;

		}
		return (1);
	}
	return (-1);
}
