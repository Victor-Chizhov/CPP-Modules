NAME =  form

SRCS =	./main.cpp ./Bureaucrat.cpp ./Form.cpp

OBJS = $(SRCS:.cpp=.o)

CPPFLAGS = -Werror -Wextra -Wall -std=c++98 #-fsanitize=address -g

CPP = c++

all: $(NAME)

%.o : %.cpp 
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CPP) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(NAME) $(OBJS)

fclean: clean

re: fclean all

.PHONY:	all clean fclean re