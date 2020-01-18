# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_base.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 15:24:49 by hwolf             #+#    #+#              #
#    Updated: 2019/11/24 14:20:14 by odrinkwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_SRC_DIR	= ./sources/
LIBFT_INC_DIR	= ./includes/
LIBFT_OBJ_DIR	= ./objects/

LIBFT_HDR		= libft.h terminal_draw.h ft_timer.h

LIBFT_SRC		= ft_atoi.c ft_bzero.c ft_dictadd.c ft_dictclearzero.c \
	ft_dictdelbykey.c ft_dictdelelement.c ft_dictgetoraddvalue.c \
	ft_dictgetvalue.c ft_dictnew.c ft_free.c ft_getnbr_base.c ft_isalnum.c \
	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
	ft_lstadd.c ft_lstaddback.c ft_lstdel.c ft_lstdeli.c ft_lstdelone.c \
	ft_lstfind.c ft_lsti.c ft_lstiter.c ft_lstlen.c ft_lstmap.c \
	ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_outbuff_dst.c \
	ft_outbuff.c ft_pow.c ft_printstrsplit.c ft_putchar_fd.c ft_putchar.c \
	ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c \
	ft_putstr.c ft_skip_digits.c ft_strcat.c ft_strchr.c ft_strclr.c \
	ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
	ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
	ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
	ft_strnequ.c ft_strnew.c ft_strnjoin.c ft_strnstr.c ft_strrchr.c \
	ft_strset.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	ft_tolower.c ft_toupper.c ft_zerostr.c get_next_line.c ft_nbrlen.c \
	ft_isint.c ft_del_strsplit.c ft_dlist.c ft_dlist1.c \
	ft_queue.c ft_queue1.c ft_max_min_intarray.c \
	ft_intlen.c ft_print_intmatrix.c ft_delmatrix.c ft_vector.c \
	ft_realloc.c \
	ft_timer.c ft_timer1.c \
	ft_sort_bubble.c ft_sort_quick.c

LIBFT_OBJ		= $(LIBFT_SRC:.c=.o)

PRF_SRC_DIR		= ./sources/printf_src/
PRF_HDR_DIR		= ./includes/printf_hdr/
PRF_OBJ_DIR 	= ./objects/printf_obj/

PRINTF_HDR		= ft_options.h ft_outbuff_dst.h ft_outbuff.h ft_printf.h \
		prf_arg_mode.h prf_double.h prf_extend_dollar.h \
		prf_get_item_by_size.h prf_global_bak.h prf_handle_comma_flag.h \
		prf_handle_spec.h prf_handle_stars.h prf_print_output.h \
		prf_printf_spec.h prf_read_spec.h prf_spectostr_funcs.h

PRINTF_SRC	= arg_mode.c bn_auxfunc.c bn_fix.c bn_fstr.c bn_init.c \
	bn_oppow.c bn_opsub.c bn_opsummul.c bn_outp.c bn_round.c change_fd.c \
	change_outstr.c dbl_input.c double.c extend_dollar.c \
	ft_printf.c get_item_by_size.c global_bak.c handle_comma_flag.c \
	handle_spec.c handle_stars.c print_output.c read_spec.c \
	spectostr_bighex.c spectostr_bin.c spectostr_char.c \
	spectostr_float.c spectostr_lowhex.c spectostr_oct.c \
	spectostr_percent.c spectostr_ptr.c spectostr_sdec.c \
	spectostr_string.c spectostr_udec.c bn_auxfunc1.c

PRINTF_OBJ	= $(PRINTF_SRC:.c=.o)

FULL_LIBFT_HDR	= $(addprefix $(LIBFT_INC_DIR),$(LIBFT_HDR))
FULL_LIBFT_SRC	= $(addprefix $(LIBFT_SRC_DIR),$(LIBFT_SRC))
FULL_PRINTF_HDR	= $(addprefix $(PRF_HDR_DIR),$(PRINTF_HDR))
FULL_PRINTF_SRC = $(addprefix $(PRF_SRC_DIR),$(PRINTF_SRC))

ALL_LIBFT = $(FULL_LIBFT_HDR)
ALL_LIBFT += $(FULL_LIBFT_SRC)
ALL_LIBFT += $(FULL_PRINTF_HDR)
ALL_LIBFT += $(FULL_PRINTF_SRC)
