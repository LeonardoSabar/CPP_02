CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes
NAME = fixed
SRC_DIR = src
INCLUDES_DIR = includes
SRC = $(SRC_DIR)/Fixed.cpp $(SRC_DIR)/main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX)