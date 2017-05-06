#include "ft_db.h"

t_field		*ft_return_field(t_dbinfo *dbmeta, int fd, long long field)
{
	long long	counter;
	int			entry_size;
	t_entry		*buff;
	t_field		*new;

	entry_size = sizeof(t_entry);
	buff = (t_entry*)ft_memalloc(sizeof(t_entry));
	new = (t_field*)ft_memalloc(sizeof(t_field));
	if (new)
	{
		new->entries = (long long*)ft_memalloc(sizeof(long long) \
						* dbmeta->num_records);

		lseek(fd, sizeof(long long) * 3 + field * (sizeof(t_field)), SEEK_SET);
		if (new->entries)
		{
			lseek(fd, dbmeta->offset, SEEK_SET);
			while (read(fd, buff, entry_size) == entry_size)
			{
				if ((buff->field) == field)
					ft_longlongcat(new->entries, counter);
				++counter;
			}
		}
	}
	return (new);
}
