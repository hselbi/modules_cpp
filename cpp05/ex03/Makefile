SRCS = 	Bureaucrat.cpp Form.cpp		\
		ShrubberyCreationForm.cpp	\
		RobotomyRequestForm.cpp 	\
		main.cpp Intern.cpp			\
		PresidentialPardonForm.cpp

CC = c++
NAME = Form

CFLANG = -Wall -Wextra -Werror -std=c++98
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