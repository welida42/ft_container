SRCS = main.cpp tests/test_speed.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = run_tests
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = clang++

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

test:		$(NAME)
			./run_tests

.PHONY:		clean fclean re all