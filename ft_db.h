#ifndef FT_DB_H
# define FT_DB_D
# include "libft/libft.h"
# include <stdio.h>

typedef struct		s_field{
	long long		field;
	char			field_name[32];
	int				type_id;
	long long		*entries;
	struct s_field	*next;
}					t_field;

typedef struct		s_record{
	long long		record;
	long long		*entries;
	struct s_record	*next;
}					t_record;

typedef struct	s_entry{
	long long			index;
	long long			field;
	long long			record;
	unsigned char		data[256];
	short				id;
}				t_entry;

typedef struct s_fieldinfo{
	long long	field_id;
	short		type_id;
	char		name[32];
}				t_finfo;

typedef struct	s_dbinfo{
	long long			num_fields;
	long long			num_records;
	long long			field_cap;
	long long			offset;
	t_field				**fields;
	t_record			**records;

}				t_dbinfo;

int						ft_create_db(char *filename, long long field_cap);
int						ft_update_status(int fd, t_dbinfo *dbmeta);
void					ft_print_status(t_dbinfo *dbmeta);
t_dbinfo				*ft_open_db(char *filename, int *fd);
long long				ft_add_field(t_dbinfo *dbmeta, int fd, char *field_name, short id);
t_entry					*ft_find_entry(t_dbinfo *dbmeta, int fd, long long field, long long record);
int						ft_write_dbmeta(t_dbinfo *dbmeta, int fd);
int						ft_write_fields(t_dbinfo *dbmeta, int fd);
int						ft_update_fields(int fd, t_dbinfo *dbmeta);
int						ft_add_entry(t_dbinfo *dbmeta, int fd, long long field_id, long long record_id);
long long				ft_add_record(t_dbinfo *dbmeta, int fd);
int				ft_write_entry(t_dbinfo *dbmeta, int fd, t_entry *entry, long long index);
int						ft_edit_entry(t_dbinfo *dbmeta, int fd, long long record, long long field, void *data);
t_record				*ft_return_record(t_dbinfo *dbmeta, long long record);
t_field					*ft_return_field(t_dbinfo *dbmeta, int fd, long long field);
long long				ft_assemble_records(t_dbinfo *dbmeta);
long long				ft_assemble_fields(t_dbinfo *dbmeta, int fd);
int						ft_refresh(t_dbinfo *dbmeta, int fd);
#endif
