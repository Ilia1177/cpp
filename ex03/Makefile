NAME 	= 	animal	
CC 		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g -O0
SRC_DIR = source/
HDR_DIR = header/
OBJ_DIR	= objet/
INC		= -I$(HDR_DIR)
SRCS	= 	main.cpp\
	   		Character.cpp\
			Cure.cpp\
			Ice.cpp\
			AMateria.cpp
SRCS 	:= 	$(addprefix $(SRC_DIR), $(SRCS))
OBJS	=	$(SRCS:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

all 			: $(NAME)

$(OBJ_DIR)%.o	: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME)			: $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(INC) $(CFLAGS) $^ -o $(NAME)

clean			:
	@echo "Cleaning object..."
	@rm -rf $(OBJ_DIR)
	@echo "Folder is clean."

fclean			: clean
	@echo "Cleaning everything..."
	@rm -f $(NAME)
	@echo "Folder is like new."

re		: fclean all

.PHONY	: all clean fclean re 
