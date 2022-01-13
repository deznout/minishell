cmake_minimum_required(VERSION 3.19.2)
project(minishell C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-lreadline")
include_directories("includes")

link_directories("~/.brew/opt/readline/lib")

FILE(GLOB LIBFT Lib/*.c)
FILE(GLOB KERNEL kernel/*.c)
FILE(GLOB BUILTINS builtins/*.c)


add_executable(minishell includes/minishell.h ${LIBFT} ${KERNEL} ${BUILTINS} main.c includes/builtins.h includes/includes.h includes/parser.h includes/logic.h builtins/unset.c builtins/cd.c builtins/cd_utils.c builtins/export.c builtins/export_print.c builtins/export_utils.c Lib/ft_split_free.c)
