#include "ft_db.h"
#include <stdio.h>

void ft_print_status(t_dbinfo *dbmeta)
{
	if (dbmeta)
	{
		ft_putendl("Printing info...");
		printf("Fields: %lld/%lld\nEntries: %lld", dbmeta->num_fields, dbmeta->field_cap, dbmeta->num_entries);
/*		ft_putstr("Fields: ");
		ft_putstr(ft_itoa(dbmeta->num_fields));
		ft_putchar('/');
		ft_putendl(ft_itoa(dbmeta->field_cap));
		ft_putstr("Entries: ");
		ft_putendl(ft_itoa(dbmeta->num_entries));*/
	}
}
