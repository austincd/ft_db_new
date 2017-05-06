#include "ft_db.h"
#include <stdio.h>

int	ft_write_dbmeta(t_dbinfo *dbmeta, int fd)
{
	int			llsize;
	int			total;
	long long	num_fields;

	num_fields = dbmeta->num_fields;
	total = 0;
	llsize = sizeof(long long);
	printf("dbmeta->num_fields is: %lld\n", dbmeta->num_fields);
	total = lseek(fd, 0, SEEK_SET);
	printf("total is %d\n", total);
	total += write(fd, &num_fields, llsize);
	printf("fd is: %d\n", fd);
	printf("total is %d\n", total);
	total += write(fd, &dbmeta->num_records, llsize);
	total += write(fd, &dbmeta->field_cap, llsize);
	if (total == llsize * 3)
		return (1);
	else
		return (-1);
}
