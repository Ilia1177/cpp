NAME 	= 	zombie
CC 		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	= 	main.cpp\
	   		Zombie.cpp\
	   		newZombie.cpp\
	   		randomChump.cpp
OBJS	=	$(SRCS:%.cpp=%.o)

all 	: $(NAME)

%.o		: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
	$(CC) $^ $(CFLAGS) -o $(NAME)

clean	:
	@echo "Cleaning object..."
	@rm -f $(OBJS)
	@echo "Folder is clean."

fclean	: clean
	@echo "Cleaning everything..."
	@rm -f $(NAME)
	@echo "Folder is like new."

re		: fclean all

.PHONY	: all clean fclean re 
