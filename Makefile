
# Files
NAME			= cub3d
AUX				= $(AUX_DIR)aux.a

# Directories
AUX_DIR			= ./aux/
SRC_DIR			= ./srcs/
CUB_DIR			= ./cub/
PARS_DIR		= ./parsing/
EXIT_DIR		= ./free_error_exit/
OBJ_DIR			= ./objects/

# Compiler and Flags
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -g
MLXFLAGS		= -Lmlx_linux -lmlx -lXext -lX11 -lm -lz
RM				= rm -f
HEADER			= -Iincludes

# Source Files
SRC				= $(SRC_DIR)data.c $(SRC_DIR)main.c $(SRC_DIR)var_init.c
CUB				= $(CUB_DIR)angle_utils.c $(CUB_DIR)dist_calculations.c $(CUB_DIR)draw_lines.c $(CUB_DIR)draw.c \
				$(CUB_DIR)key_press.c $(CUB_DIR)mini_map.c $(CUB_DIR)rendering.c $(CUB_DIR)wall_calculations.c \
				$(CUB_DIR)window_init.c
EXIT			= $(EXIT_DIR)close_window.c
PARS			= $(PARS_DIR)file_validation.c

# Apply the pattern substitution to each source file and produce a corresponding list of object files in the OBJ_DIR
OBJ 			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC)) $(patsubst $(EXIT_DIR)%.c,$(OBJ_DIR)%.o,$(EXIT)) \
				$(patsubst $(PARS_DIR)%.c,$(OBJ_DIR)%.o,$(PARS)) $(patsubst $(CUB_DIR)%.c,$(OBJ_DIR)%.o,$(CUB))

# Build
all: 			$(NAME)
				@echo "cub3d - All set"

$(NAME): 		$(AUX) $(OBJ)
				@$(CC) $(CFLAGS) $(HEADER) $(OBJ) $(AUX) $(MLXFLAGS) -o $@
				@echo "cub3d - Executable file created"

$(AUX):
				@make -s -C $(AUX_DIR)
				@echo "cub3d - Object files created"

# Compile object files from source files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJ_DIR)%.o: $(CUB_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJ_DIR)%.o: $(EXIT_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJ_DIR)%.o: $(PARS_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

# Clean
clean:
				@make fclean -s -C $(AUX_DIR)
				@$(RM) -r $(OBJ_DIR)
				@echo "cub3d - Object files deleted"

fclean: 		clean
				@$(RM) $(NAME)
				@echo "cub3d - Executable file deleted"
				@echo "cub3d - All clean"

re: 			fclean all

# Phony targets represent actions not files
.PHONY: 		all clean fclean re
