NAME        = span

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

SRCS        = main.cpp Span.cpp
OBJS_DIR    = obj
OBJS        = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

HEADERS     = Span.hpp

GREEN       = \033[0;32m
RED  		= \033[0;31m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Compilation completed!$(RESET)"

$(OBJS_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJS_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(GREEN)Object files deleted.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)Executable file deleted.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
