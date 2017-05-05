#include "ft_db.h"

int	ft_edit_field(t_dbinfo *dbmeta, int fd, long long record, long long field, void *data)
{
	long long	which;
	t_field		*field_ptr;

	field_ptr = NULL;
	if (dbmeta && fd >= 0)
	{
		field_ptr = ft_find_field(dbmeta, fd, field, record);
		which = field_ptr->which;
		ft_write_field(dbmeta, fd, which, data);
		return (1);
	}
	return (-1);
}
