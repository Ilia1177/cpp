NAME 	= 	addresses
CC 		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	= 	main.cpp
OBJS	=	$(SRCS:%.cpp=%.o)

all 	: $(NAME)

%.o		: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
	$(CC) $^ $(CFLAGS) -o $(NAME)

clean	:
	@echo "Deleting objects..."
	@rm -f $(OBJS)
	@echo "Objects removed."

fclean	: clean
	@echo "Deleting executable..."
	@rm -f $(NAME)
	@echo "Executable removed."

re		: fclean all

.PHONY	: all clean fclean re 
