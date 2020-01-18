# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:13:46 by odrinkwa          #+#    #+#              #
#    Updated: 2019/12/15 17:31:31 by odrinkwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
NAME_VISU = visu

SRC_DIR := ./sources
INC_DIR := ./includes
INCMLX_DIR := ./fdf_lib/mlx
INCLIBFT_DIR := ./libft/includes
OBJ_DIR := ./objects
LIB_DIR := ./libft

SRC_COMMON := initialize.c load_map.c load_map1.c load_map2.c destroy.c \
	auxf.c calc_ways.c solve.c bfs.c prepare_data.c \
	prepare_data1.c prepare_data2.c going_ants.c going_ants1.c \
	print_anthill.c destroy1.c\
	start_assign_data.c load_and_prepare_data.c

SRC_TO_VISU := lemin_keyhooks.c draw_anthill.c draw_anthill1.c \
	load_ant_im.c draw_ants.c tlemin_mlx_init.c start_assign_data_lm.c \
	ants_move.c change_step.c start_assign_anthill.c put_all_anthill.c \
	lemin_mouse.c ants_image.c
	
SRC  := main.c $(SRC_COMMON)

HDRS := includes/lemin.h
HDRS_VISU := includes/lemin_mlx.h
OBJ  := $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJECTS = $(SOURCES:.c=.o)


SRC_VISU := visu.c $(SRC_COMMON) $(SRC_TO_VISU)
OBJ_VISU = $(addprefix $(OBJ_DIR)/,$(SRC_VISU:.c=.o))

FDF_SRC_DIR := ./fdf_lib/sources
FDF_HDR_DIR := ./fdf_lib/includes
FDF_OBJ_DIR := ./fdf_lib/objects

FDF_SRC := fdf_initialize_mlx.c fdf_destroy_mlx.c \
	fdf_make_map_points.c draw_surface.c \
	fdf_color.c fdf_draw_point.c \
	fdf_put_main_image.c \
	fdf_put_pixel.c fdf_put_line.c fdf_put_circle.c fdf_put_box.c \
	fdf_projection.c fdf_projection_get_point.c \
	fdf_projection_iso_transform.c \
	fdf_rotation.c fdf_rotation_matrix.c fdf_rotation_matrix1.c \
	fdf_hook_mouse.c fdf_hook_keyhook.c \
	fdf_legend.c \
	fdf_calc_hzoom.c fdf_clear_image.c

FDF_HDR := ./fdf_lib/includes/fdf.h

FDF_OBJ := $(FDF_SRC:.c=.o)
FDF_OBJ_WITH_PATH := $(addprefix $(FDF_OBJ_DIR)/, $(FDF_OBJ))


CC := gcc
CFLAGS := -O2 -g3 -Wall -Wextra #-Werror
MLXPARAMS := -L ./fdf_lib/mlx -lmlx -framework OpenGL -framework AppKit
LIBFT_NODEBUG :=

L_FT := libft

include $(L_FT)/libft_base.mk
TMP = $(subst ./, /, $(ALL_LIBFT))
FULL_ALL_LIBFT = $(addprefix $(L_FT),$(TMP))

SRC_LIB = $(addprefix $(L_FT)/,$(LIBFT_SRC))

HEADER_LIB = $(INCLIBFT_DIR)/libft.h

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME) $(NAME_VISU)

test:
	@echo $(FULL_ALL_LIBFT)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(FDF_OBJ_DIR)
	$(MAKE) -C libft clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_VISU)
	$(MAKE) -C $(L_FT) fclean

re: fclean all


$(FDF_OBJ_DIR):
	mkdir -p $(FDF_OBJ_DIR)

$(FDF_OBJ_DIR)/%.o:$(FDF_SRC_DIR)/%.c $(FDF_HDR)
#	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -I $(INCLIBFT_DIR) -o $@ -c $<
	$(CC) $(CFLAGS) $(LIB_INC) -I $(FDF_HDR_DIR) -I $(INCLIBFT_DIR) -I $(INCMLX_DIR) -o $@ -c $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(HDRS)
#	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -I $(INCLIBFT_DIR) -o $@ -c $<
	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -I $(INCLIBFT_DIR) -I $(FDF_HDR_DIR) -I $(INCMLX_DIR) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER_LIB) $(HDRS) $(FULL_ALL_LIBFT) $(FDF_OBJ_DIR) $(FDF_OBJ_WITH_PATH)
	$(MAKE) -C $(L_FT) $(LIBFT_NODEBUG)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -I $(INCLIBFT_DIR) -L libft -lft
#	$(CC) $(CFLAGS) $(OBJ) $(FDF_OBJ_WITH_PATH) -o $(NAME) -I $(INCLIBFT_DIR) -I $(INCMLX_DIR) -L libft -lft $(MLXPARAMS)

$(NAME_VISU): $(OBJ_DIR) $(OBJ_VISU) $(HEADER_LIB) $(HDRS) $(FULL_ALL_LIBFT) $(FDF_OBJ_DIR) $(FDF_OBJ_WITH_PATH)
	$(MAKE) -C $(L_FT) $(LIBFT_NODEBUG)
#	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -I $(INCLIBFT_DIR) -L libft -lft
	$(CC) $(CFLAGS) $(OBJ_VISU) $(FDF_OBJ_WITH_PATH) -o $(NAME_VISU) -I $(INCLIBFT_DIR) -I $(INCMLX_DIR) -L libft -lft $(MLXPARAMS)

nodebug: CFLAGS = -Wall -Wextra -O3 #-Werror

nodebug: LIBFT_NODEBUG = nodebug

nodebug: all
