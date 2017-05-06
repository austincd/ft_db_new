#include "ft_db.h"

t_entry	*ft_find_entry(t_dbinfo *dbmeta, int fd, long long record, long long field)
{
	t_entry		*entry_ptr;
	long long	index;

	if (fd >= 0 && dbmeta)
	{
		if (field >=0 && field <= dbmeta->num_fields \
			&& record >= 0 && field <= dbmeta->num_records)
		{
			index = dbmeta->fields[field]->entries[record];
			printf("index is %lld\n", index);
			entry_ptr = (t_entry*)ft_memalloc(sizeof(t_entry));
			if (entry_ptr)
			{
			printf("hey\n");
				lseek(fd, dbmeta->offset + sizeof(t_entry) * index, SEEK_SET);
				read(fd, entry_ptr, sizeof(t_entry));
				entry_ptr->index = index;
				return (entry_ptr);
				/*	else
						free(entry_ptr);*/
			}
		}
	}
	return (NULL);
}
