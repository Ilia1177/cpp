NAME 	= 	PmergeMe	
OS = $(shell uname)

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 
ifeq ($(OS), Darwin)
	CC 		=	/usr/local/bin/g++-15
else
	CC 		=	c++
endif

ifdef DETAILS
    CFLAGS += -DDETAILS=1
endif

SRC_DIR = srcs/
INC_DIR = incs/
OBJ_DIR	= objs/
INCS		= -I$(INC_DIR)
SRCS	= 	main.cpp\
			PmergeMe.cpp\

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

details	: fclean
	$(MAKE) all DETAILS=1

.PHONY	: all clean fclean re 
