#include "ft_db.h"

long long ft_add_record(t_dbinfo *dbmeta, int fd)
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
		num_records = dbmeta->num_records;
		while (counter < num_fields && status == 1)
		{
			status = ft_add_entry(dbmeta, fd, counter, num_records);
			++counter;
		}
		++dbmeta->num_records;
		ft_write_dbmeta(dbmeta, fd);
		return (1);
	}
	return (-1);
}
