NAME =			push_swap
CHECKER =		checker

LIBFT_DIR =		./libft
LIBFT = 		$(LIBFT_DIR)/libft.a

PS_DIR =		./src
PS_SRC =		$(PS_DIR)/push_swap.c $(PS_DIR)/bigsort.c $(PS_DIR)/other_sort.c\
				$(PS_DIR)/stack_creator.c $(PS_DIR)/stack_operations.c $(PS_DIR)/utils.c\
				$(PS_DIR)/checks_n_error.c $(PS_DIR)/instructions_push.c\
				$(PS_DIR)/instructions_rotate.c $(PS_DIR)/instructions_swap.c\
				$(PS_DIR)/instructions_rrotate.c
				
B_DIR =			./bonus
B_SRC =			$(B_DIR)/checker.c $(PS_DIR)/instructions_push.c $(PS_DIR)/instructions_rotate.c\
				$(PS_DIR)/instructions_swap.c $(PS_DIR)/instructions_rrotate.c\
				$(PS_DIR)/stack_creator.c $(PS_DIR)/checks_n_error.c $(PS_DIR)/stack_operations.c

OBJ_DIR	=		./ofiles
PS_OBJ = 		$(PS_SRC:$(PS_DIR)/%.c=$(OBJ_DIR)/%.o)
B_OBJ =			$(B_SRC:$(B_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

# Colors
GREEN		=		\033[0;32m
UGREEN		=		\033[4;32m
RED			=		\033[0;31m
YELLOW		=		\033[0;33m
LILA		=		\033[0;35m
NC			=		\033[0m # No color

all: ascii_art

bonus: ascii_art_bonus

ascii_art:
	@if ! $(MAKE) -q $(NAME); then \
		printf "$(LILA)\n"; \
		printf "██████╗ ██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗ \n"; \
		printf "██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗\n"; \
		printf "██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝\n"; \
		printf "██╔═══╝ ██║   ██║╚════██║██╔══██║        ╚════██║██║███╗██║██╔══██║██╔═══╝ \n"; \
		printf "██║     ╚██████╔╝███████║██║  ██║███████╗███████║╚███╔███╔╝██║  ██║██║     \n"; \
		printf "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     \n"; \
		printf "		     					   				MRUBAL-C\033[0m\n"; \
		echo "$(YELLOW)\nCreating program...$(GREEN)"; \
		$(MAKE) -s $(NAME); \
	else \
		echo "$(GREEN)[$(NAME)] is already up to date.$(NC)"; \
	fi

ascii_art_bonus:
	@if ! $(MAKE) -q $(CHECKER); then \
		printf "$(LILA)\n"; \
		printf "$(LILA)\n"; \
		printf "██████╗ ██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗ \n"; \
		printf "██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗\n"; \
		printf "██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝\n"; \
		printf "██╔═══╝ ██║   ██║╚════██║██╔══██║        ╚════██║██║███╗██║██╔══██║██╔═══╝ \n"; \
		printf "██║     ╚██████╔╝███████║██║  ██║███████╗███████║╚███╔███╔╝██║  ██║██║     \n"; \
		printf "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     \n"; \
		printf "					▗▄▄▖▗▖ ▗▖▗▄▄▄▖ ▗▄▄▖▗▖ ▗▖▗▄▄▄▖▗▄▄▖ \n"; \
		printf "					▌   ▐▌ ▐▌▐▌   ▐▌   ▐▌▗▞▘▐▌   ▐▌ ▐▌\n"; \
		printf "					▌   ▐▛▀▜▌▐▛▀▀▘▐▌   ▐▛▚▖ ▐▛▀▀▘▐▛▀▚▖\n"; \
		printf "					▚▄▄▖▐▌ ▐▌▐▙▄▄▖▝▚▄▄▖▐▌ ▐▌▐▙▄▄▖▐▌ ▐▌\n"; \
		printf "		     						 MRUBAL-C\033[0m\n"; \
		echo "$(YELLOW)\nCreating bonus program...$(GREEN)"; \
		$(MAKE) -s $(CHECKER); \
	else \
		echo "$(GREEN)[$(CHECKER)] is already up to date.$(NC)"; \
	fi

$(NAME): $(PS_OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(PS_OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)Program created 👍: $(NAME)$(NC)"

$(CHECKER): $(B_OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(B_OBJ) -L$(LIBFT_DIR) -lft -o $(CHECKER)
	@echo "$(GREEN)Checker created 👍: $(CHECKER)$(NC)"

$(OBJ_DIR)/%.o: $(PS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(B_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) -r $(OBJ_DIR)

fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(RED)Removing program... 🧹$(NC)"
	@$(RM) $(NAME)
	@$(RM) $(CHECKER)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(GREEN)Full clean complete 🗑️$(NC)"

a: all bonus

re: fclean all

rebonus: fclean bonus

ra: fclean a

.PHONY: all bonus clean fclean a re rebonus ra
