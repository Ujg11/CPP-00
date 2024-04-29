# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/03 18:58:16 by ojimenez          #+#    #+#              #
#    Updated: 2024/03/07 14:04:49 by ojimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = interface
CPP = c++
FLAGS = -Wall -Wextra -Werror -g -pedantic -std=c++98 #-fsanitize=address
RM = rm -rf

#SOURCE
SRC = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
INC = AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp

#DIRECTORIES
D_OBJ = obj
OBJ = $(addprefix $(D_OBJ)/, $(SRC:.cpp=.o))
DEP = $(addprefix $(D_OBJ)/, $(SRC:.cpp=.d))

all : dir $(NAME)

-include $(DEP)

dir:
	@mkdir -p $(D_OBJ)

$(D_OBJ)/%.o: %.cpp Makefile
		$(CPP) $(FLAGS) -MMD -c $< -o $@
		echo "file: $< to $@"
	
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
