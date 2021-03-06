# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/17 14:14:07 by bsemchuk          #+#    #+#              #
#*   Updated: 2018/03/19 18:44:50 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

BLACK ="\033[1;30m"
RED ="\033[1;31m"
GREEN ="\033[1;32m"
YELLOW = "\x1b[33m"
BLUE = "\x1b[34m"
MAGENTA = "\x1b[35m"
CYAN ="\033[1;35m"
PURPLE ="\033[1;36m"
WHITE ="\033[1;37m"
EOC ="\033[0;0m"
RESET = "\x1b[0m"

CC = @gcc

NAME = asm

CFLAGS = -g3 -Wall -Wextra -Werror

SRC =	src/bit_flags.c \
		src/label_validation.c \
		src/debug.c \
		src/finish_header.c \
		src/delete_comments.c \
		src/flush_arguments.c \
		src/flush_reg.c \
		src/flush_indir_char.c \
		src/flush_ind.c \
		src/label_exists.c \
		src/flush_dir_char.c \
		src/change_filename_extension.c \
		src/argtypes_into_tline.c \
		src/get_bytes_needed.c \
		src/deintegrate_split_trim.c \
		src/get_all_info_we_can_into_array_of_tlines.c \
		src/arguments_validation_and_codage_writing.c \
		src/get_codage_to_tline.c \
		src/validate_argument_types.c \
		src/get_parg_and_pparg.c \
		src/is_string_valid_int.c \
		src/is_header_valid.c \
		src/get_command_index_and_label_args_pointer.c \
		src/ft_write_value_big_endian.c \
		src/label_name_into_list.c \
		src/flush_header_structure.c \
		src/follow_labels.c \
		src/flush_dir.c \
		src/trim_args.c \
		src/find_end_name_or_comment.c \
		src/do_nothing.c \
		src/offset.c \
		src/lists.c \
		src/op.c \
		src/op_tab_f.c \
		src/read_lines.c \
		src/read_lines_extra.c \
		src/split_raw_line.c \
		src/useful.c \
		src/validate_instruction_args.c \
		src/header_validation.c \
		src/main.c \
		src/ft_strjoin_whitespace.c \
		src/space_before.c


LIB = libft/libft.a
PRINTLIB = ../ft_printf/libftprintf.a

OBJ = $(SRC:.c=.o)
SRAV = ./src/

all: $(NAME)
$(OBJS) : includes/asm.h ft_printf/includes/ft_printf.h

$(NAME): $(OBJ)
	@make -C libft/
	@make -C ../ft_printf/
	$(CC) $(CFLAGS) $(OBJ) $(PRINTLIB) $(LIB) -o $(NAME)
	@echo $(GREEN) "\t\tASSEMBLER compiled\n" $(RESET)

%.o: $(SRAV)%.c
	@gcc -c $< -o $@

clean:
	@make clean -C libft/
	@make clean -C ../ft_printf/
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft/
	@make fclean -C ../ft_printf/
	@rm -rf $(NAME)
	@echo $(RED) "\t\tASSEMBLER has been deleted\n" $(RESET)

re: clean all

