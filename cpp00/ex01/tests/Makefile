SRC = main.cpp phonebook.cpp

NAME = phonebook

CC = c++ -Wall -Wextra -Werror -g

all: ${NAME}

%.o: %.c
	$(CC) -c $< -o $@

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME) 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all


