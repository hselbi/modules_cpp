SRCS = main.cpp BitcoinExchange.cpp

NAME = btc

CC = c++
CFLANG = -Wall -Wextra -Werror -g -fsanitize=address -std=c++98
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLANG) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re