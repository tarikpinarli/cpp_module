NAME        = exam

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++17

SRCS        = main.cpp Warlock.cpp ASpell.cpp ATarget.cpp Dummy.cpp Fwoosh.cpp
OBJS_DIR    = obj
OBJS        = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

HEADERS     =  Warlock.hpp ASpell.hpp ATarget.hpp Dummy.hpp Fwoosh.hpp

GREEN       = \033[0;32m
RED  		= \033[0;31m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Compilation completed!$(RESET)"

$(OBJS_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	@echo "$(GREEN)Object files deleted.$(RESET)"

fclean: clean
	rm -f $(NAME)
	@echo "$(GREEN)Executable file deleted.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
