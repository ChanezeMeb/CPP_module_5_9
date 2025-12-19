NAME = swap
CX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = ex00.cpp
OBJS = $(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CX) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:	%.cpp whatever.hpp
	$(CX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re