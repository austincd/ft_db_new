#ifndef FT_DB_H
# define FT_DB_D
# include "libft/libft.h"

typedef struct	s_field{
	long long	which;
	long long	field;
	long long	record;
	long long	data_num;
	char		data_char;
	char		field_name[32];
	char		data_str[256];
}				t_field;
typedef struct	s_dbinfo{
	long long			num_fields;
	long long			num_entries;
	long long			field_cap;
}				t_dbinfo;

int						ft_create_db(char *filename, long long field_cap);
int						ft_update_status(int fd, t_dbinfo *dbmeta);
void					ft_print_status(t_dbinfo *dbmeta);
t_dbinfo				*ft_open_db(char *filename, int *fd);
long long				ft_add_field(t_dbinfo *dbmeta, int fd, char *field_name, short id);
t_field					*ft_find_field(t_dbinfo *dbmeta, int fd, long long field, long long record);
int						ft_write_dbmeta(t_dbinfo *dbmeta, int fd);
#endif
