#include "ft_db.h"

t_record	*ft_return_record(t_dbinfo *dbmeta, long long record)
{
	t_record	*new;
	long long	counter;

	counter = 0;
	new = NULL;
	if (dbmeta && record < dbmeta->num_records)
	{
		new = (t_record*)ft_memalloc(sizeof(t_record));
		if (new)
		{
			new->entries = (long long*)ft_memalloc(sizeof(long long) \
			* dbmeta->num_records);
			while (counter < dbmeta->num_fields)
			{
				ft_longlongcat(new->entries, \
				dbmeta->fields[counter]->entries[record]);
				++counter;
			}
		}
	}
	return (new);
}
