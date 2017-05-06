#include "ft_db.h"

int	ft_refresh(t_dbinfo *dbmeta, int fd)
{
	void *temp1;
	void *temp2;

	if (dbmeta)
	{
		temp1 = dbmeta->fields;
		temp2 = dbmeta->records;
		ft_assemble_fields(dbmeta, fd);
		ft_assemble_records(dbmeta);
		if (dbmeta->fields)
		{
			free(temp1);
			free(temp2);
			return (1);
		}
		else
		{
			dbmeta->fields = temp1;
			dbmeta->records = temp2;
		}
	}
	return (-1);
}
