
NAME= ft_db

SRCS= ft_create_db.c ft_open_db.c ft_print_status.c ft_update_db.c main.c ft_find_field.c ft_add_field.c ft_write_dbmeta.c ft_write_fields.c ft_create_field.c ft_add_entry.c ft_write_field.c ft_edit_field.c

OBJECTS= ft_create_db.o ft_open_db.o ft_print_status.o ft_update_db.o main.o ft_find_field.o ft_add_field.o ft_write_dbmeta.o ft_add_entry.o ft_create_field.o ft_write_fields.o ft_write_field.o ft_edit_field.o

all: $(NAME)

$(NAME):
		gcc -c -Wall -Wextra -Werror $(SRCS)
		gcc -o $(NAME) $(OBJECTS) -L libft/ -l:libft.a

clean:
		rm $(OBJECTS)

fclean: clean
		rm ./ft_db

re: fclean all
