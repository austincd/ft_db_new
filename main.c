#include "ft_db.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	t_dbinfo *dbmeta;

	if (argc >= 3)
	{
		if (ft_strequ(argv[1], "-c") && argc == 4)
		{
			close(ft_create_db(argv[2], ft_atoi(argv[3])));
			ft_print_status(ft_open_db(argv[2], &fd));
		}
		if (ft_strequ(argv[1], "-o") && argc == 3)
			ft_print_status(ft_open_db(argv[2], &fd));
		if (ft_strequ(argv[1], "-add_field") && argc == 5)
		{
			dbmeta = ft_open_db(argv[2], &fd);
			printf("fd is %d\n", fd); 
			ft_putstr("Field Name: ");
			ft_putstr(argv[3]);
			ft_putstr("is the ");
			ft_putstr(ft_itoa(ft_add_field(dbmeta, fd, argv[3], ft_atoi(argv[4]))));
			ft_putendl("th field.");
		}
	}
	else
	{
		ft_putendl("ERROR: No valid commands. Please check readme for instructions");
	}
	return (1);
}
