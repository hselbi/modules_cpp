SRC = phonebook.cpp

NAME = phonebook

CC = c++ -Wall -Wextra -Werror

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


