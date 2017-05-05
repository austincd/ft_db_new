#include "ft_db.h"

int		ft_write_field(t_dbinfo *dbmeta, int fd, long long which_field, void *data)
{
	long long	offset;
	t_field		*field_ptr;

	offset = sizeof(long long) * 3;
	offset += sizeof(t_finfo) * dbmeta->field_cap;
	offset += sizeof(t_field) * which_field;
	lseek(fd, offset, SEEK_SET);
	field_ptr = (t_field*)ft_memalloc(sizeof(t_field));
	read(fd, field_ptr, sizeof(t_field));
	ft_memcpy(field_ptr->data, data, 256);
	lseek(fd, offset, SEEK_SET);
	write(fd, field_ptr, sizeof(t_field));
	return (1);
}
