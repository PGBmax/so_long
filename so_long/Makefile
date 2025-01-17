NAME = so_long

SOURCES =	src/moves/ft_hook.c \
			src/moves/remove_collec.c \
			src/textures/ft_load_png.c \
			src/textures/ft_tex_data.c \
			src/textures/ft_tex_player.c \
			src/textures/ft_tex_walls.c \
			src/flood_fill.c \
			src/free_all.c \
			src/ft_check_map.c \
			src/ft_error.c \
			src/ft_loops.c \
			src/ft_parsing.c \
			src/ft_show_textures.c \
			src/ft_walls.c \
			src/main.c \
			src/map.c \
			includes/ft_printf/ft_printf.c \
			includes/ft_printf/ft_utils.c \
			includes/GNL/get_next_line.c \
			includes/GNL/get_next_line_utils.c
SOURCESBONUS =	bonus/flood_fill.c \
				bonus/free_all.c \
				bonus/ft_check_map.c \
				bonus/ft_error.c \
				bonus/frames/ft_collec.c \
				bonus/frames/ft_digit.c \
				bonus/frames/ft_player.c \
				bonus/moves/ft_ghost_moves.c \
				bonus/moves/ft_ghost_moves2.c \
				bonus/moves/ft_hook.c \
				bonus/moves/ft_utils_ghost.c \
				bonus/ft_loops.c \
				bonus/ft_parsing.c \
				bonus/ft_show_textures.c \
				bonus/ft_walls.c \
				bonus/main.c \
				bonus/map.c \
				bonus/textures/ft_load_png.c \
				bonus/textures/ft_tex_data.c \
				bonus/textures/ft_tex_ghost.c \
				bonus/textures/ft_tex_player.c \
				bonus/textures/ft_tex_walls.c \
				includes/ft_printf/ft_printf.c \
				includes/ft_printf/ft_utils.c \
				includes/GNL/get_next_line.c \
				includes/GNL/get_next_line_utils.c


OBJECTS = $(SOURCES:.c=.o)
OBJECTSBONUS = $(SOURCESBONUS:.c=.o)

INCLUDES = -Iincludes/ -I$(LIBMLX)/include

LIBMLX = ./MLX42
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

CFLAGS = -Wall -Werror -Wextra -g

%.o : %.c
	@cc $(CFLAGS) $(INCLUDES) $< -o $@ -c

all	: mlx $(NAME)

mlx :
	@if ls | grep -q "MLX42"; then \
		clear; \
		echo "\033[32;47;1m** MLX42 already exist **\033[1;m"; \
	else \
		git clone https://github.com/codam-coding-college/MLX42.git; \
		cmake ./MLX42 -B ./MLX42/build; \
		make -C ./MLX42/build --no-print-directory -j4; \
		make --directory ./MLX42/build; \
	fi

$(NAME) : $(OBJECTS)
		@cc $(CFLAGS) $(INCLUDES) $(OBJECTS) $(LIBS) -o $(NAME)
		@echo "\e[97mCompiled Mandatory ✅\e[97m"

clean:
		@rm -f $(OBJECTS) $(OBJECTSBONUS)
		@echo "\e[97mCleaned objects ✅\e[97m"

fclean: clean
		@rm -f $(NAME)
		@echo "\e[97mCleaned executables ✅\e[97m"

bonus : mlx $(OBJECTSBONUS)
		@cc $(CFLAGS) $(INCLUDES) $(OBJECTSBONUS) $(LIBS) -o $(NAME)
		@echo "\e[97mCompiled Bonus ✅\e[97m"

re : fclean all
