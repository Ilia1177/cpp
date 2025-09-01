NAME 	= 	bureaucrat	
OS = $(shell uname)

ifeq ($(OS), Darwin)
        CFLAGS	= -Wall -Wextra -Werror -std=c++98 
        CC		= /usr/local/bin/g++-15
else
        CC		= c++
        CFLAGS	= -Wall -Wextra -Werror -std=c++98 
endif
SRC_DIR = srcs/
INC_DIR = incs/
OBJ_DIR	= objs/
INCS		= -I$(INC_DIR)
SRCS	= 	main.cpp\
	   		Bureaucrat.cpp\
			AForm.cpp\
			PresidentialPardonForm.cpp\
			RobotomyRequestForm.cpp\
			ShrubberyCreationForm.cpp

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
	@echo "Objects removed."

fclean			: clean
	@echo "Cleaning everything..."
	@rm -f $(NAME)
	@rm -f *_shrubbery
	@echo "Binary removed."

re		: fclean all

.PHONY	: all clean fclean re 
