NAME = Bureaucrat
RM = rm -rf
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -MMD -MP
SRC = Bureaucrat.cpp \
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

#Pour gérer les dépendances en C++ :

# Ajouter -MMD -MP dans CXXFLAGS
# Créer une variable DEP (les fichiers .d)
# Inclure ces .d avec -include
# Les supprimer dans clean