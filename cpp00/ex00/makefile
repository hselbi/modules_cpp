SRC = megaphone.cpp

NAME = megaphone

CC = c++ -Wall -Wextra -Werror -std=c++98

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


