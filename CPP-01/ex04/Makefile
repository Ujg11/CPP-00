# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 14:33:06 by ojimenez          #+#    #+#              #
#    Updated: 2024/02/20 12:22:53 by ojimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace
CPP = c++
FLAGS = -Wall -Wextra -Werror -g -pedantic -std=c++98 -fsanitize=address
RM = rm -rf
SRC = main.cpp

D_OBJ = obj
OBJ = $(addprefix $(D_OBJ)/, $(SRC:.cpp=.o))
DEP = $(addprefix $(D_OBJ)/, $(SRC:.cpp=.d))

all : dir $(NAME)

-include $(DEP)

dir:
	@mkdir -p $(D_OBJ)

#construimos los objetos en el directorio $(D_OBJ)/
#-MMD -c se usa para generar archivos de dependencia y compilar. El $< se refiera al archivo fuente y $@ al objeto
$(D_OBJ)/%.o: %.cpp Makefile
		$(CPP) $(FLAGS) -MMD -MP -c $< -o $@
		echo "file: $< to $@"

#Construimos el archivo ejecutable a partir de los objetos
$(NAME): $(OBJ) Makefile
		$(CPP) $(FLAGS) $(OBJ) -o $(NAME)
		echo "Project $(NAME) successfully compiled!!"

clean:
		$(RM) $(D_OBJ)
		echo "$(NAME) object files cleaned successfully!"

fclean: clean
		$(RM) $(NAME)
		echo "All removed successfully!"

re: fclean all

.PHONY: all clean fclean re dir