SRCS = ./main.cpp \
	./DiamondTrap.cpp \
	./ClapTrap.cpp \
	./ScavTrap.cpp \
	./FragTrap.cpp 

CC = c++
NAME = DiamondTrap

CFLANG = -Wall -Wextra -Werror -std=c++98 -Whadow -Wno-shadow
OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re