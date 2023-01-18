NAME = megaphone
FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
SRC = $(wildcard ./*.cpp)
RM = rm -rf

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean all;

re : fclean

.PHONY : all fclean clean re