#include "ft_db.h"

int		ft_write_entry(t_dbinfo *dbmeta, int fd, t_entry *entry, long long index)
{
	lseek(fd, dbmeta->offset + (index * sizeof(t_entry)), SEEK_SET);
	if (write(fd, entry, sizeof(t_entry)) == sizeof(t_entry))
		return (1);
	else
		return (-1);
}
