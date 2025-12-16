NAME = AForm
RM = rm -rf
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -MMD -MP
SRC = Bureaucrat.cpp \
	  AForm.cpp \
	  PresidentialPardonForm.cpp \
	  RobotomyRequestForm.cpp \
	  ShrubberyCreationForm.cpp \
	  Intern.cpp \
	  main.cpp

OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.d)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ) $(DEP)

fclean : clean
	$(RM) $(NAME)

re : fclean all

-include $(DEP)

.PHONY : all clean fclean re