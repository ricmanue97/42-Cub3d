

# Files
NAME			= cub3D
AUX				= $(AUX_DIR)aux.a

# Directories
AUX_DIR			= ./aux/
SRC_DIR			= ./srcs/
PARS_DIR		= ./parsing/
EXIT_DIR		= ./free_error_exit/
OBJ_DIR			= ./objects/


# Compiler and Flags
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -g
RM				= rm -f
HEADER			= -Iinclude -Ipipex
LIBRARIES		= -lreadline

# Source Files
SRC			= $(SRC_DIR)main.c



# Apply the pattern substitution to each source file and produce a corresponding list of object files in the OBJ_DIR
OBJ 			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC)) $(patsubst $(EXIT_DIR)%.c,$(OBJ_DIR)%.o,$(EXIT)) \
				$(patsubst $(PARS_DIR)%.c,$(OBJ_DIR)%.o,$(PARS)) \

# Build
all: 			$(NAME)
				@echo "cub3D - All set"

$(NAME): 		$(AUX) $(OBJ)
				@$(CC) $(CFLAGS) $(HEADER) $(OBJ) $(AUX) $(LIBRARIES) -o $@
				@echo "cub3D - Executable file created"

$(AUX):
				@make -s -C $(AUX_DIR)
				@echo "cub3D - Object files created"

# Compile object files from source files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJ_DIR)%.o: $(EXIT_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJ_DIR)%.o: $(PARS_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJ_DIR)%.o: $(GNL_DIR)%.c
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