NAME = harlFilter
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
SRC = $(wildcard ./*.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)


re : fclean all

.PHONY : all fclean clean re