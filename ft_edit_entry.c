#include "ft_db.h"

int	ft_edit_entry(t_dbinfo *dbmeta, int fd, long long record, long long field, void *data)
{
	long long	index;
	long long	temp;
	t_entry		*entry;

	entry = NULL;
	temp = 0;
	if (dbmeta && fd >= 0)
	{
		entry = ft_find_entry(dbmeta, fd, record, field);
		if (entry)
		{
			printf("hello\n");
			index = entry->index;
			if (dbmeta->fields[field]->type_id == 1 ||
				dbmeta->fields[field]->type_id == 2)
			{
				temp = ft_atoi((char*)data);
				ft_bzero(data, 256);
				ft_memmove(data, &temp, sizeof(int));
			}
			ft_memcpy(entry->data, data, 256);
			printf("dbmeta->num_fields = %lld\n", dbmeta->num_fields);
			ft_write_entry(dbmeta, fd, entry, index);
			printf("dbmeta->num_fields = %lld\n", dbmeta->num_fields);
			return (1);
		}
	}
	return (-1);
}
