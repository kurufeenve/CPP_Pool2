SRC = main.cpp \
	  Game.class.cpp \
	  Enemy.cpp \
	  GameObject.cpp \
	  Player.cpp \
	  list.cpp \
	  Bullet.cpp \
	  Star.class.cpp
 
INC = ./includes/Game.class.hpp \
	  ./includes/Enemy.hpp \
	  ./includes/GameObject.hpp \
	  ./includes/Player.hpp \
	  ./includes/list.hpp \
	  ./includes/Bullet.hpp \
	  ./includes/Star.class.hpp

SRC_DIR = ./src/
OBJ_DIR = ./obj/
OBJ = $(addprefix $(OBJ_DIR),$(SRC:.cpp=.o))
NAME = ft_retro
CFLAG = -Werror -Wextra -Wall
LIB = -lcurses -lncurses
CC = clang++
REMAKE = rmk

$(OBJ_DIR)%.o: %.cpp $(INC)
		@echo "\033[0;32mCreating object files\033[0m \033[31m$@\033[0m"
		@$(CC) $(CFLAG) -c $< -o $@

all: $(NAME)
$(NAME): $(OBJ)
		@echo "\033[0;32mCompile solution ...\033[0m"
		@$(CC) $(CFLAG) -o $(NAME) $(OBJ) $(LIB)
		@echo "\033[0;32mProgram compiled : \033[0m\033[31m$(NAME)\033[0m"

$(OBJ): $(OBJ_DIR)

$(OBJ_DIR):
		@mkdir $(OBJ_DIR)

clean:
		@echo "\033[0;32mCleaning object files ...\033[0m"
		@rm -rf $(OBJ_DIR)

fclean: clean
		@rm -f $(NAME)
		@echo "\033[31m$(NAME)\033[0m\033[0;32m was completely removed\033[0m"

re: $(REMAKE) fclean all
$(REMAKE):
		@echo "\033[0;32mRemaking project \033[0m\033[31m$(NAME)\033[0m"

vpath %.cpp $(SRC_DIR)
