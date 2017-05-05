#include "ft_db.h"

long long ft_add_entry(t_dbinfo *dbmeta, int fd)
{
	long long	num_fields;
	long long	num_records;
	long long	counter;
	int			status;

	status = 1;
	if (dbmeta && fd)
	{
		counter = 0;
		ft_update_status(fd, dbmeta);
		num_fields = dbmeta->num_fields;
		num_records = dbmeta->num_entries;
		while (counter < num_fields && status == 1)
		{
			status = ft_create_field(dbmeta, fd, counter, num_records);
			++counter;
		}
		++dbmeta->num_entries;
		ft_write_dbmeta(dbmeta, fd);
		return (1);
	}
	return (-1);
}
