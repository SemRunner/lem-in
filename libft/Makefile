# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:13:46 by odrinkwa          #+#    #+#              #
#    Updated: 2019/11/30 17:31:37 by odrinkwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
L_FT 		?= .
FT_NAME		= $(NAME)
HD_NAME		= libft.h

FT_LNK 		= -L $(L_FT) -l ft
FT_INC		= -I $(L_FT)/includes
FT_INC_PRF	= -I $(L_FT)/includes/printf_hdr
FT_LIB		= $(L_FT)/$(FT_NAME)

LIB_LNK		= $(FT_LNK)
LIB_INC		= $(FT_INC)

include libft_base.mk

OBJ			= $(addprefix $(LIBFT_OBJ_DIR), $(LIBFT_OBJ))
OBJ 		+= $(addprefix $(PRF_OBJ_DIR), $(PRINTF_OBJ))

CFLAGS 		= -Wall -Wextra -Werror -g3 -O2

CC			= gcc

.PHONY: all clean fclean re

all: $(LIBFT_OBJ_DIR) $(NAME)

clean:
	rm -rf $(PRF_OBJ_DIR)
	rm -rf $(LIBFT_OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

$(LIBFT_OBJ_DIR):
	mkdir -p $(LIBFT_OBJ_DIR)
	mkdir -p $(PRF_OBJ_DIR)

$(LIBFT_OBJ_DIR)%.o: $(LIBFT_SRC_DIR)%.c $(FULL_LIBFT_HDR)
	$(CC) $(CFLAGS) $(FT_INC) $(FT_INC_PRF) -o $@ -c $<

$(PRF_OBJ_DIR)%.o: $(PRF_SRC_DIR)%.c $(FULL_PRINTF_HDR)
	$(CC) $(CFLAGS) $(FT_INC) $(FT_INC_PRF) -o $@ -c $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

nodebug: CFLAGS := -Wall -Wextra -Werror -O3

nodebug: all
