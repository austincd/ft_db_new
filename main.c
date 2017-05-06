#include "ft_db.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int			fd;
	long long	field;
	long long	record;
	t_dbinfo	*dbmeta;
	void		*data;
	t_entry		*entry;

	data = ft_memalloc(256);
	if (argc >= 3)
	{
		dbmeta = ft_open_db(argv[2], &fd);
		ft_update_status(fd, dbmeta);
		ft_update_fields(fd, dbmeta);
		ft_refresh(dbmeta, fd);
		if (argc >= 5)
		{
			record = ft_atoi(argv[3]);
			field = ft_atoi(argv[4]);
		}
		if (ft_strequ(argv[1], "-c") && argc == 4)
		{
			close(fd);
			ft_print_status(ft_open_db(argv[2], &fd));
		}
		if (ft_strequ(argv[1], "-o") && argc == 3)
			ft_print_status(ft_open_db(argv[2], &fd));
		if (ft_strequ(argv[1], "-add_field") && argc == 5)
			ft_add_field(dbmeta, fd, argv[3], field);
		if (ft_strequ(argv[1], "-add_record") && argc == 3)
			ft_add_record(dbmeta, fd);
		if (ft_strequ(argv[1], "-edit") && argc == 6)
		{
			ft_strncpy(data, argv[5], 255);
			ft_edit_entry(dbmeta, fd, ft_atoi(argv[3]), ft_atoi(argv[4]), data);
		}
		if (ft_strequ(argv[1], "-print") && argc == 5)
		{
			close(fd);
			dbmeta = ft_open_db(argv[2], &fd);
			printf("field %lld \n", field);
			entry = ft_find_entry(dbmeta, fd, field, record);
			printf("entry is %p\n", entry);
			printf("hello %d\n", dbmeta->fields[field]->type_id);
			if (dbmeta->fields[field]->type_id == 1)
				printf("Record %lld, Field %lld = %d\n", record, field, *((int*)(entry->data)));
			if (dbmeta->fields[field]->type_id == 2)
				printf("Record %lld, Field %lld = %lld\n", record, field, *((long long*)(entry->data)));
			if (dbmeta->fields[field]->type_id == 3)
				printf("Record %lld, Field %lld = %c\n", record, field, *((char*)(entry->data)));
			if (dbmeta->fields[field]->type_id == 4)
				printf("Record %lld, Field %lld = %s\n", record, field, ((char*)(entry->data)));
		}
	}
	else
	{
		ft_putendl("ERROR: No valid commands. Please check readme for instructions");
	}
	return (1);
}
