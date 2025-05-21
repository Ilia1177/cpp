NAME = the_job_of_your_dream
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Account.cpp\
	   test.cpp\

OBJS = $(SRCS:%.cpp=%.o)

all 	: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $^ $(CFLAGS) -o $(NAME)

%.o		: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@


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
