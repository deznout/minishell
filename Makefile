NAME     = minishell

CFLAGS   = -Wall -Wextra -Werror
RFLAGS   = -lreadline -L ~/.brew/opt/readline/lib
CC	     = gcc

HEADER   = minishell.h

INC       = includes
BUILT_DIR = ./builtins/
KER_DIR   = ./kernel/
OBJS_DIR  = ./objects/
READ_INC = ~/.brew/opt/readline/include/readline/

LIB_DIR  = ./Lib/
LIBFT    = ${LIB_DIR}libft.a

BUILT_FILES = env.c exit.c echo.c pwd.c cd.c cd_utils.c \
			  unset.c export.c export_print.c export_utils.c help.c

KER_FILES  = dups.c env_utils.c init.c errors.c loop.c redirects.c  \
			 lst.c parser.c parser_utils.c pipes_utils.c pipes.c utils.c signals.c

KER  = $(addprefix $(KER_DIR), $(KER_FILES))
BUILT = $(addprefix $(BUILT_DIR), $(BUILT_FILES))
OBJS = $(addprefix $(OBJS_DIR), $(KER_FILES:.c=.o))
OBJS += $(addprefix $(OBJS_DIR), $(BUILT_FILES:.c=.o))

VPATH = ${KER_DIR} ${BUILT_DIR}

all: ${NAME}

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

${LIBFT}:
	@make -C $(LIB_DIR)

$(OBJS_DIR)%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIB_DIR) -I$(INC) -I$(READ_INC) -c $< -o $@
	@printf "\033[0;33mObject %-40.100s [\033[0;32m✔\033[0;33m]\r" $@

${NAME}: $(LIBFT) $(OBJS_DIR) $(OBJS) $(BUILT) $(KER) main.c
	@$(CC) ${CFLAGS} ${LIBFT} -I$(INC) -I$(LIB_DIR) -I$(READ_INC) $(RFLAGS) ${OBJS} main.c -o ${NAME}
	@printf '\033[1;32m%-100.100s\n\033[0m' '${NAME} compiled successfully!'

clean:
	@rm -rf $(OBJS_DIR)
	@make clean -C $(LIB_DIR)
	@printf '\033[1;35mObjects files deleted\n\033[0m'

fclean: clean
	@make fclean -C $(LIB_DIR)
	rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re