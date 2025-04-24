# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/28 14:30:44 by edvieira          #+#    #+#              #
#    Updated: 2025/04/24 10:44:04 by edvieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


C++ = c++
C++_FLAGS = -Wall -Wextra -Werror -std=c++98
INFILES = 	tests.cpp\
			Account.cpp\

OBJFILES = $(INFILES:.cpp=.o)

NAME = account

all: $(NAME)

$(NAME):$(OBJFILES)
	$(C++) $(C++_FLAGS) $(OBJFILES) -o $(NAME)

%.o: %.cpp
	$(C++) $(C++_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
