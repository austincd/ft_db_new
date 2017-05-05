#include "ft_db.h"

int ft_create_field(t_dbinfo *dbmeta, int fd, long long field_id, long long record_id)
{
	t_field	*new;

	new = NULL;
	if (dbmeta && fd)
	{
		if (dbmeta->fields)
		{
			if ((dbmeta->fields[field_id].type_id))
			{
				new = (t_field*)ft_memalloc(sizeof(t_field));
				if (new)
				{
					new->id = dbmeta->fields[field_id].type_id;
					new->field = field_id;
					new->record = record_id;
					ft_bzero(new->data_str, 256);
					lseek(fd, 0, SEEK_END);
					if (write(fd, new, sizeof(t_field)) == sizeof(t_field))
						return (1);
				}
			}
		}
	}
	return (-1);
}
