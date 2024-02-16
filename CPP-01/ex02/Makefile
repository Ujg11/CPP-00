NAME = zombie02
CPP = c++
FLAGS = -Wall -Wextra -Werror -g -pedantic -std=c++98 -fsanitize=address
RM = rm -rf
SRC = main.cpp


all : $(NAME)

$(NAME): $(SRC) Makefile
	$(CPP) $(FLAGS) -o $(NAME) $(SRC)

clean:
	$(RM) *.o
	@echo "$(NAME) object files cleaned successfully!"

fclean: clean
	$(RM) $(NAME)
	@echo "$(NAME) removed successfully!"

re: fclean all

.PHONY: all clean fclean re