NAME 	= 	point
CC 		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	= 	main.cpp	\
	   		Fixed.cpp	\
			Point.cpp	\
			bsp.cpp
INCLUDE	=	-I./Fixed.hpp -I./Point.hpp

OBJS	=	$(SRCS:%.cpp=%.o)

all 	: $(NAME)

%.o		: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME) $(INCLUDE)

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
