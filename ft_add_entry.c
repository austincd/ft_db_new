#include "ft_db.h"

int ft_add_entry(t_dbinfo *dbmeta, int fd, long long field_id, long long record_id)
{
	t_entry	*new;

	new = NULL;
	if (dbmeta && fd)
	{
		if (dbmeta->fields)
		{
			if ((dbmeta->fields[field_id]->type_id))
			{
				new = (t_entry*)ft_memalloc(sizeof(t_entry));
				if (new)
				{
					new->id = dbmeta->fields[field_id]->type_id;
					new->field = field_id;
					new->record = record_id;
					ft_bzero(new->data, 256);
					lseek(fd, 0, SEEK_END);
					if (write(fd, new, sizeof(t_entry)) == sizeof(t_entry))
						return (1);
				}
			}
		}
	}
	return (-1);
}
