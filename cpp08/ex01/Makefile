SRCS = 	main.cpp Span.cpp

CC = c++
NAME = Span

CFLANG = -Wall -Wextra -Werror -std=c++98 

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