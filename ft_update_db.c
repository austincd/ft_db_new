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
				llptr[1] != dbmeta->num_entries || \
				llptr[2] != dbmeta->field_cap)
			{
				dbmeta->num_fields = llptr[0];
				dbmeta->num_entries = llptr[1];
				dbmeta->field_cap = llptr[2];
				return (1);
			}
			return (0);
		}
	}
	return (-1);
}
