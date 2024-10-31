GREEN = \033[0;32m
RED = \033[0;31m
RST = \033[0m

NAME = phonebook

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -rf

FILES = main.cpp \
PhoneBook.cpp \
Contacts.cpp \

OBJ = $(FILES:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)  ✔  PHONEBOOK is successfully compiled!$(RST)"

clean:
	@$(RM) $(OBJ)
	@echo "$(RED)Object files removed!$(RST)"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re