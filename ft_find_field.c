#include "ft_db.h"

t_field	*ft_find_field(t_dbinfo *dbmeta, int fd, long long field, long long record)
{
	t_field		*field_ptr;
	long long	counter;
	long long	status;
	int			llsize;

	llsize = sizeof(long long);
	field_ptr = NULL;
	if (fd >= 0 && dbmeta)
	{
		if (field >=0 && field <= dbmeta->num_fields \
			&& record >= 0 && field <= dbmeta->num_entries)
		{
			field_ptr = (t_field*)ft_memalloc(sizeof(t_field));
			lseek (fd, (llsize * 3) + (dbmeta->field_cap * sizeof(t_finfo)), SEEK_SET);
			while ((status = read(fd, field_ptr, sizeof(t_field))) == sizeof(t_field))		{
				field_ptr->which = counter;
				if (field_ptr->field == field && field_ptr->record == record)
					return (field_ptr);
				++counter;
			}
		}
	}
	return (field_ptr);
}
