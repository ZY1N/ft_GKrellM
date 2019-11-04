NAME	:= ft_gkrellm
CC		:= clang++
FLAGS	:= -std=c++98 -Wall -Wextra -Werror

FILES	:= *.cpp
OBJ		:= $(FILES:.cpp=.o)

all		: $(NAME)

$(NAME)	: #$(OBJ)
	$(CC) $(FLAGS) $(FILES) -lncurses -o $(NAME)

#%.o: %.cpp
#	$(CC) $(FLAGS) -c $< -o $@

clean	:
	rm -rf $(OBJ)

fclean	: clean
	rm -rf $(NAME)

re		: fclean all

.PHONY: all, clean, fclean, re