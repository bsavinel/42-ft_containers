# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/17 11:00:11 by bsavinel          #+#    #+#              #
#    Updated: 2022/07/17 20:06:59 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
########						Comilation Tools						########
################################################################################

TEST_FT = test_ft
TEST_STD = test_std

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

ifeq (ft, $(filter ft, $(MAKECMDGOALS)))
	CPPFLAGS += -D NAMESPACE_USE=ft
	NAME = test_ft
endif

ifeq (std, $(filter std, $(MAKECMDGOALS)))
	CPPFLAGS += -D NAMESPACE_USE=std
	NAME = test_std
endif

ifeq (sanitize, $(filter sanitize, $(MAKECMDGOALS)))
	CPPFLAGS += -g3 -fsanitize=address
endif

################################################################################
########							Sources 							########
################################################################################

SRCS_PATH 	=	testeur/srcs/

INCS =	-I testeur/includes		\
		-I includes				\
		-I includes/containers	\
		-I includes/utils		\

SRCS =	main.cpp					\
		containers/vector_test.cpp	\
		containers/stack_test.cpp	\
		containers/map_test.cpp		\
		containers/set_test.cpp		\
		utils/enable_if_test.cpp	\
		utils/equal_test.cpp		\
		utils/is_integral_test.cpp	\
		utils/lexi_comp_test.cpp	\
		utils/pair_test.cpp			\

################################################################################
########						Objects/Dependences						########
################################################################################

OBJS_PATH =	objs/

OBJS =	$(addprefix $(OBJS_PATH), $(SRCS:.cpp=.o))		
DEPS =	$(OBJS:.o=.d)

################################################################################
########							Others								########
################################################################################

RM = rm -rf

################################################################################
########							Colors								########
################################################################################

BLUE		=	\033[0;34m
RED			=	\033[0;31m
GREEN		=	\033[0;32m
NO_COLOR	=	\033[m

################################################################################
########							Rules								########
################################################################################

all:
	make -C . $(TEST_STD)
	make -C . $(TEST_FT)

bonus: all

testeur: $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME) $(INCS)

$(TEST_STD):
	make -C . clean
	make -C . testeur std
	echo "$(BLUE)$(TEST_STD): $(GREEN)Success $(NO_COLOR)"

$(TEST_FT):
	make -C . clean
	make -C . testeur ft
	echo "$(BLUE)$(TEST_FT): $(GREEN)Success $(NO_COLOR)"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) -MMD -c $< -o $@ $(INCS) 

clean :
	$(RM) $(OBJS_PATH)

fclean : clean
	$(RM) log_test
	$(RM) $(TEST_FT)
	$(RM) $(TEST_STD)
	$(RM) libft/libft.a

re : fclean 
	 make all

test: all
	mkdir -p log_test
	./$(TEST_STD) >log_test/log_std.txt
	./$(TEST_FT) >log_test/log_ft.txt
	diff log_test/log_ft.txt log_test/log_std.txt && echo "$(GREEN)Tout est ok$(NO_COLOR)" || echo "$(RED)Erreur$(NO_COLOR)"

fsanitize_test:
	make -C . fclean
	make -C . testeur std sanitize
	echo "$(BLUE)$(TEST_STD): $(GREEN)Success $(NO_COLOR)"
	make -C . clean
	make -C . testeur ft sanitize
	echo "$(BLUE)$(TEST_FT): $(GREEN)Success $(NO_COLOR)"
	make -C . test

val_test:
	make -C . fclean
	make -C . all
	mkdir -p log_test
	./$(TEST_STD) >log_test/log_std.txt
	valgrind --log-file=log_test/out_valgrind.txt ./$(TEST_FT) >log_test/log_ft.txt || echo -n ""
	diff log_test/log_ft.txt log_test/log_std.txt && echo "$(GREEN)Tout est ok$(NO_COLOR)" || echo "$(RED)Erreur$(NO_COLOR)"
	echo "$(BLUE)"
	cat log_test/out_valgrind.txt
	echo "$(NO_COLOR)"

sanitize:
	echo -n  ""

std:
	echo -n  ""

ft:
	echo -n  ""

-include $(DEPS)

.PHONY: all clean fclean re bonus val_test test

.SILENT: