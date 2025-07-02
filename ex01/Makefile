NAME 	= 	bureaucrat	
CC 		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRC_DIR = srcs/
INC_DIR = incs/
OBJ_DIR	= objs/
INCS		= -I$(INC_DIR)
SRCS	= 	main.cpp\
	   		Bureaucrat.cpp\

SRCS 	:= 	$(addprefix $(SRC_DIR), $(SRCS))
OBJS	=	$(SRCS:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

all 			: $(NAME)

$(OBJ_DIR)%.o	: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME)			: $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCS) $^ -o $(NAME)

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
