#include "ft_db.h"

long long	ft_add_field(t_dbinfo *dbmeta, int fd, char *field_name, short id)
{
	long long	index;

	index = 0;
	ft_update_status(fd, dbmeta);
	ft_update_fields(fd, dbmeta);
	if (dbmeta->fields)
	{
		while(dbmeta->fields[index].type_id && index < dbmeta->field_cap)
			++index;
		if (index < dbmeta->field_cap)
		{
			dbmeta->fields[index].type_id = id;
			ft_strlcpy(dbmeta->fields[index].name, field_name, 32);
			dbmeta->fields[index].field_id = index;
			dbmeta->num_fields += 1;
			ft_write_fields(dbmeta, fd);
			ft_write_dbmeta(dbmeta, fd);
			return (index);
		}
		return (-2);
	}
	return (-1);
}
