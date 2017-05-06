#include "ft_db.h"

long long	ft_delete_record(t_dbinfo *dbmeta, int fd, long long record_id)
{
	int		counter;
	t_entry	*empty;

	empty = (t_entry*)ft_memalloc(sizeof(t_entry));
	counter = 0;
	if (dbmeta)
	{
		while (counter < dbmeta->num_fields)
		{
			ft_write_entry(dbmeta, fd, empty, dbmeta->records[record_id]->entries[counter]);
			++counter;
		}
	}
}

long long	ft_delete_field(t_dbinfo *dbmeta, int fd, long long field_id)
{	int		counter;
	t_entry	*empty;

	empty = (t_entry*)ft_memalloc(sizeof(t_entry));
	counter = 0;
	if (dbmeta)
	{
		while (counter < dbmeta->num_records)
		{
			ft_write_entry(dbmeta, fd, empty, dbmeta->fields[field_id]->entries[counter]);
			++counter;
		}
	}
}
