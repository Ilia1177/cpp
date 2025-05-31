NAME = phone_book 
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = PhoneBook.cpp\
	   Contact.cpp\
	   main.cpp\

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
