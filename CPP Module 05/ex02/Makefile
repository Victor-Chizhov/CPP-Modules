NAME =   form28B

SRCS =	./main.cpp ./Bureaucrat.cpp ./AForm.cpp ./ShrubberyCreationForm.cpp ./RobotomyRequestForm.cpp ./PresidentialPardonForm.cpp

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