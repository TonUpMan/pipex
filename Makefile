GREEN =\033[32m
RESET =\033[0m

SRC_DIR = src
#SRC_BONUS_DIR = src_bonus
OBJ_DIR = obj
#OBJ_BONUS_DIR = obj_bonus

SRCS := main.c \
	parsing.c \
	utils.c \
	path_utils.c \
	child_utils.c \


#SRCS_BONUS := 

	
SRCS := $(SRCS:%.c=$(SRC_DIR)/%.c)	
#SRCS_BONUS := $(SRCS_BONUS:%.c=$(SRC_BONUS_DIR)/%.c)

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
#OBJ_BONUS := $(SRCS_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)


NAME = pipex


CC = clang

CFLAGS = -Wall -Wextra -Werror -I include -g

all: $(NAME)

$(NAME): $(OBJS)
	@echo "LIBFT COMPILATION :\c"
	@${MAKE} -C ./libft >/dev/null
	@echo "$(GREEN)COMPILED$(RESET)"
	@echo "Pipex : \c"
	@${CC} ${OBJS} ./libft/libft.a -o ${NAME}
	@echo "$(GREEN)COMPILED$(RESET)"
#	@echo "Norm error detected : \c"
#	@echo | norminette | grep "Error" | wc -l


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c -o $@ $<


clean: 
	@echo "All files.o :\c" 
	@${MAKE} -C ./libft clean >/dev/null
	@rm -rf $(OBJS) $(OBJ_DIR)
	@echo "$(GREEN)REMOVED$(RESET)"

fclean: clean
	@echo "exec :\c"
	@${MAKE} -C ./libft fclean >/dev/null
	@rm -f $(NAME)
	@echo "$(GREEN)REMOVED$(RESET)"

re: fclean all

PHONY.: re fclean clean all