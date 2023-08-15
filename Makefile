# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 18:26:19 by alajara-          #+#    #+#              #
#    Updated: 2023/07/25 17:43:57 by alajara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#		#===========#
# 		||VARIABLES||
#		#===========#

# -=-=-=-=- NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

NAME        := push_swap
MKFL        := Makefile

# -=-=-=-=- CLRS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

DEF_CLR     := \033[0;39m
GRAY        := \033[0;90m
RED         := \033[0;91m
GREEN       := \033[0;92m
YELLOW      := \033[0;93m
BLUE        := \033[0;94m
MAGENTA     := \033[0;95m
CYAN        := \033[0;96m
WHITE       := \033[0;97m

# -=-=-=-=- PATH -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

SRC_DIR := source/
UTL_DIR := utils/

LIB_DIR	:= libft/

OBJ_DIR := .objs/
DEP_DIR := .deps/

# -=-=-=-=- CMND -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

CFLAGS	= -Wall -Wextra -Werror -W
#XFLAGS	= -fsanitize=address -g
DFLAGS	= -MT $@ -MMD -MP

AR	= ar -rcs
RM	= rm -f
MK	= mkdir -p
CP	= cp -f
I	= -I./$(LIB_DIR)

# -=-=-=-=- FILE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

LIBFT	= $(LIB_DIR)libft.a

SRCS	= push_swap.c \
		check_ps.c \
		movements.c \
		settings.c \
		algorithm.c

OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS	= $(addprefix $(DEP_DiIR), $(addsuffix .d, $(basename $(SRCS))))

# -=-=-=-=- RULE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

%.o: %.c Makefile
	@${CC} ${CFLAGS} ${XFLAGS} ${DFLAGS} $I -c $< -o $@

all : makelib $(NAME)

makelib:
	@$(MAKE) -C $(LIB_DIR)

$(NAME):: $(OBJS)
	$(CC) $(CFLAGS) $(XFLAGS) $(OBJS) $(GFLAGS) -L $(LIB_DIR) -lft -o $(NAME)
	@printf "\n\t$(WHITE)Program \033[1;31mTest $(WHITE)has been compiled!$(DEF_COLOR)\n"
	
$(NAME)::
	@printf "\t$(WHITE)Nothing more to be done for program \033[1;31mTest$(DEF_COLOR)\n"

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@$(RM) -rf $(OBJ_DIR) $(DEP_DIR)
	@echo "$(BLUE)  Test object and dependencies files cleaned.$(DEF_COLOR)"
	
fclean:
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(RM) -rf $(OBJ_DIR) $(DEP_DIR)
	@$(RM) $(NAME)
	@echo "$(WHITE) All objects, dependencies and executables removed.$(DEF_COLOR)"
	
re:
	@$(MAKE) fclean
	@$(MAKE) all
	@echo "$(GREEN) Cleaned and rebuilt everything for Test project.$(DEF_COLOR)"
	
$(OBJ_DIR)%.o: %.c $(MKFL)
	@$(MK) $(dir $@) $(dir $(subst $(OBJ_DIR),$(DEP_DIR), $@))
	@printf "\r$(GREEN)\tCompiling: $(YELLOW)$< $(DEF_CLR)                   \r"
	@$(CC) $(CFLAGS) $(DFLAGS) $I -c $< -o $@
	@mv $(patsubst %.o, %.d, $@) $(dir $(subst $(OBJ_DIR), $(DEP_DIR), $@))
	
-include $(DEPS)

.PHONY: all clean fclean re norm
