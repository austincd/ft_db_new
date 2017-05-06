#include "ft_db.h"
#include <stdio.h>

void ft_print_status(t_dbinfo *dbmeta)
{
	long long counter;

	counter = 0;
	if (dbmeta)
	{
		ft_putendl("Printing info...");
		printf("Fields: %lld/%lld\nEntries: %lld", dbmeta->num_fields, dbmeta->field_cap, dbmeta->num_records);
		while (counter < dbmeta->num_fields)
		{
			printf("dbmeta->fields[%lld] is: \n \"%s\"\n with a type_id of:\n %d\n", counter, dbmeta->fields[counter]->field_name, dbmeta->fields[counter]->type_id);
			++counter;
		}
/*		ft_putstr("Fields: ");
		ft_putstr(ft_itoa(dbmeta->num_fields));
		ft_putchar('/');
		ft_putendl(ft_itoa(dbmeta->field_cap));
		ft_putstr("Entries: ");
		ft_putendl(ft_itoa(dbmeta->num_entries));*/
	}
}
