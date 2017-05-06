
NAME= ft_db

SRCS= ft_create_db.c ft_open_db.c ft_print_status.c ft_update_db.c main.c ft_find_entry.c ft_add_record.c ft_write_dbmeta.c ft_write_fields.c ft_add_field.c ft_add_entry.c ft_write_entry.c ft_edit_entry.c ft_assemble.c ft_return_field.c ft_return_record.c ft_refresh.c

OBJECTS= ft_create_db.o ft_open_db.o ft_print_status.o ft_update_db.o main.o ft_find_entry.o ft_add_record.o ft_write_dbmeta.o ft_write_fields.o ft_add_field.o ft_add_entry.o ft_write_entry.o ft_edit_entry.o ft_assemble.o ft_return_field.o ft_return_record.o ft_refresh.o

all: $(NAME)

$(NAME):
		gcc -c -Wall -Wextra -Werror $(SRCS)
		gcc -o $(NAME) $(OBJECTS) -L libft/ -l:libft.a

clean:
		rm $(OBJECTS)

fclean: clean
		rm ./ft_db

re: fclean all
