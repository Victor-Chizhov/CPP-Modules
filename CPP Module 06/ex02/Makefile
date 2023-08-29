NAME =  baseABC

SRCS =	./main.cpp ./Base.cpp ./A.cpp ./B.cpp ./C.cpp

OBJS = $(SRCS:.cpp=.o)

CPPFLAGS = -Werror -Wextra -Wall -std=c++98

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