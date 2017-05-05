#include "ft_db.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	long long field;
	long long record;
	t_dbinfo *dbmeta;
	void		*data;
	t_field		*field_ptr;

	data = ft_memalloc(256);
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
		}
		if (ft_strequ(argv[1], "-add_entry") && argc == 3)
		{
			dbmeta = ft_open_db(argv[2], &fd);
		}
		if (ft_strequ(argv[1], "-edit") && argc == 6)
		{
			dbmeta = ft_open_db(argv[2], &fd);
			ft_strncpy(data, argv[5], 255);
			ft_edit_field(dbmeta, fd, ft_atoi(argv[3]), ft_atoi(argv[4]), data);
		}
		if (ft_strequ(argv[1], "-print") && argc == 5)
		{
			record = ft_atoi(argv[3]);
			field = ft_atoi(argv[4]);
			dbmeta = ft_open_db(argv[2], &fd);
			ft_update_status(fd, dbmeta);
			ft_update_fields(fd, dbmeta);
			field_ptr = ft_find_field(dbmeta, fd, field, record);
			if (dbmeta->fields[field].type_id == 1)
				printf("Record %lld, Field %lld = %d\n", record, field, *((int*)(field_ptr->data)));
			if (dbmeta->fields[field].type_id == 2)
				printf("Record %lld, Field %lld = %lld\n", record, field, *((long long*)(field_ptr->data)));
			if (dbmeta->fields[field].type_id == 3)
				printf("Record %lld, Field %lld = %c\n", record, field, *((char*)(field_ptr->data)));
			if (dbmeta->fields[field].type_id == 4)
				printf("Record %lld, Field %lld = %s\n", record, field, ((char*)(field_ptr->data)));
			
		}
	}
	else
	{
		ft_putendl("ERROR: No valid commands. Please check readme for instructions");
	}
	return (1);
}
