#include "ft_db.h"

long long	ft_assemble_fields(t_dbinfo *dbmeta, int fd)
{
	t_field		**field_array;
	long long	counter;

	counter = 0;
	if (dbmeta)
	{
		field_array = (t_field**)ft_memalloc(sizeof(t_field*) * dbmeta->field_cap);
		if (field_array)
		{
			while (counter < dbmeta->field_cap)
			{
				field_array[counter] = ft_return_field(dbmeta, fd, counter);
				if (counter > 0)
					field_array[counter - 1]->next = field_array[counter];
				++counter;
			}
			dbmeta->fields = field_array;
			return (counter);
		}
	}
	return (-1);
}

long long	ft_assemble_records(t_dbinfo *dbmeta)
{
	t_record	**record_array;
	long long	counter;

	counter = 0;
	record_array = NULL;
	if (dbmeta)
	{
		record_array = (t_record**)ft_memalloc(sizeof(t_record*) * dbmeta->num_records);
		if (record_array)
		{
			while (counter < dbmeta->num_records)
			{
				record_array[counter] = ft_return_record(dbmeta, counter);
				if (counter > 0)
					record_array[counter - 1]->next = record_array[counter];
				++counter;
			}
			return (counter);
		}
	}
	return (-1);
}
