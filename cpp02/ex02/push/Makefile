SRCS = ./main.cpp Fixed.cpp

CC = c++
NAME = fixes_point_oper

CFLANG = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g
OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLANG) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re