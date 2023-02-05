SRC = main.cpp Phonebook.cpp Contact.cpp

NAME = Phonebook

<<<<<<< HEAD:cpp00/ex01/Makefile
CC = c++ -Wall -Wextra -Werror -std=c++98 -g
=======
CC = c++ -Wall -Wextra -Werror -std=c++98
>>>>>>> 3f0fbdffc8eec61c732b8a52f63a5927ed0fdc52:cpp00/ex01/Makefile

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


