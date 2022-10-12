# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/17 11:00:11 by bsavinel          #+#    #+#              #
#    Updated: 2022/10/12 20:19:36 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
########						Comilation Tools						########
################################################################################

TEST_FT = test_ft
TEST_STD = test_std

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

ifeq (sanitize, $(filter sanitize, $(MAKECMDGOALS)))
	CPPFLAGS += -fsanitize=address
endif

################################################################################
########							Sources 							########
################################################################################

SRCS_PATH 	=	testeur/srcs/

INCS =	-I testeur/includes		\
		-I includes/containers	\
		-I includes/utils		\

SRCS_11 =	utils/enable_if_test.cpp	\
			utils/is_integral_test.cpp	\

SRCS_98 =	main.cpp					\
			containers/vector_test.cpp	\
			containers/stack_test.cpp	\
			containers/map_test.cpp		\
			containers/set_test.cpp		\
			utils/equal_test.cpp		\
			utils/lexi_comp_test.cpp	\
			utils/pair_test.cpp			\
			benchmark_utils.cpp			\

################################################################################
########						Objects/Dependences						########
################################################################################

OBJS_PATH =	objs/

OBJS_STD =	$(addprefix $(OBJS_PATH), $(SRCS_98:.cpp=_std.o) $(SRCS_11:.cpp=_std11.o))
OBJS_FT =	$(addprefix $(OBJS_PATH), $(SRCS_98:.cpp=_ft.o) $(SRCS_11:.cpp=_ft11.o))
DEPS =	$(OBJS_STD:.o=.d) \
		$(OBJS_FT:.o=.d)

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

all: $(TEST_STD) $(TEST_FT)

bonus: all

$(TEST_STD): $(OBJS_STD)
	$(CC) $(CPPFLAGS) $(OBJS_STD) -o $(TEST_STD) $(INCS)
	echo "$(BLUE)$(TEST_STD): $(GREEN)Success $(NO_COLOR)"

$(TEST_FT): $(OBJS_FT)
	$(CC) $(CPPFLAGS) $(OBJS_FT) -o $(TEST_FT) $(INCS)
	echo "$(BLUE)$(TEST_FT): $(GREEN)Success $(NO_COLOR)"


############################
# NB_NAMESPACE -> 0 = ft   #
# NB_NAMESPACE -> 1 = std  #
############################

$(OBJS_PATH)%_std.o: $(SRCS_PATH)%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) -D NAME_USE=std -MMD -c $< -o $@ $(INCS)

$(OBJS_PATH)%_std11.o: $(SRCS_PATH)%.cpp
	mkdir -p $(dir $@)
	$(CC) -Wall -Wextra -Werror -D NAME_USE=std -MMD -c $< -o $@ $(INCS)

$(OBJS_PATH)%_ft.o: $(SRCS_PATH)%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) -D NAME_USE=ft -MMD -c $< -o $@ $(INCS)

$(OBJS_PATH)%_ft11.o: $(SRCS_PATH)%.cpp
	mkdir -p $(dir $@)
	$(CC) -Wall -Wextra -Werror -D NAME_USE=ft -MMD -c $< -o $@ $(INCS)

clean :
	$(RM) $(OBJS_PATH)

fclean : clean
	$(RM) log_test
	$(RM) $(TEST_FT)
	$(RM) $(TEST_STD)
	$(RM) libft/libft.a

re : fclean 
	 make -C . all

test: all
	mkdir -p log_test
	./$(TEST_STD) >log_test/log_std.txt || true
	./$(TEST_FT) >log_test/log_ft.txt || true
	diff log_test/log_ft.txt log_test/log_std.txt && echo "$(GREEN)Tout est ok$(NO_COLOR)" || echo "$(RED)Erreur$(NO_COLOR)"

fsanitize:
	make -C . fclean
	make -C . all sanitize

fsanitize_test:
	make -C . fclean
	make -C . all sanitize
	make -C . test

val_test:
	make -C . re
	mkdir -p log_test
	./$(TEST_STD) >log_test/log_std.txt || true
	valgrind --log-file=log_test/out_valgrind.txt ./$(TEST_FT) >log_test/log_ft.txt || echo -n "" || true
	diff log_test/log_ft.txt log_test/log_std.txt && echo "$(GREEN)Tout est ok$(NO_COLOR)" || echo "$(RED)Erreur$(NO_COLOR)"
	echo "$(BLUE)"
	cat log_test/out_valgrind.txt
	echo "$(NO_COLOR)"

################################################################################
#####                              Flags                                   #####
################################################################################

sanitize:
	echo -n  ""

################################################################################
#####                              Utils                                   #####
################################################################################

-include $(DEPS)

.PHONY: all clean fclean re bonus val_test test sanitize

.SILENT: