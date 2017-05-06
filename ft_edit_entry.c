#include "ft_db.h"

int	ft_edit_entry(t_dbinfo *dbmeta, int fd, long long record, long long field, void *data)
{
	long long	index;
	t_entry		*entry;

	entry = NULL;
	if (dbmeta && fd >= 0)
	{
		entry = ft_find_entry(dbmeta, fd, record, field);
		if (entry)
		{
			printf("hello\n");
			index = entry->index;
			ft_memcpy(entry->data, data, 256);
			printf("dbmeta->num_fields = %lld\n", dbmeta->num_fields);
			ft_write_entry(dbmeta, fd, entry, index);
			printf("dbmeta->num_fields = %lld\n", dbmeta->num_fields);
			return (1);
		}
	}
	return (-1);
}
