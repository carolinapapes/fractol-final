# Compiler and compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Ofast
SRC = fractol.c fractal_sets.c handlers_mouse.c viewport.c handlers_mlx.c messages.c palette.c
SRC_BASIC = handlers_key.c parser.c
SRC_BONUS = handlers_key_bonus.c parser_bonus.c
BUILD_DIR = ./build

# LIBS
LIBS_PATH = ./libs

# Minilibx
MLX_NAME   = MiniLibX
MLX_PATH	= $(LIBS_PATH)/minilibx_opengl
MLX_LINK	= -L${MLX_PATH} -lmlx -framework OpenGL -framework AppKit

# Libft
LIBFT_NAME = libft
LIBFT_PATH 	= $(LIBS_PATH)/libft
LIBFT_LINK	= -L${LIBFT_PATH} -lft


OBJ_SRC_BONUS = $(SRC_BONUS:%.c=$(BUILD_DIR)/%.o)
OBJ_SRC_BASIC = $(SRC_BASIC:%.c=$(BUILD_DIR)/%.o)
OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o) $(SRC_BASIC:%.c=$(BUILD_DIR)/%.o)
OBJ_BONUS = $(SRC:%.c=$(BUILD_DIR)/%.o) $(SRC_BONUS:%.c=$(BUILD_DIR)/%.o)
DPS = $(OBJ:%.o=%.d) $(OBJ_SRC_BONUS:%.o=%.d) $(OBJ_SRC_BASIC:%.o=%.d)
DPS_SRC_BONUS = $(OBJ_SRC_BONUS:%.o=%.d)
DPS_SRC_BASIC = $(OBJ_SRC_BASIC:%.o=%.d)


PREQ = Makefile 
NAME = fractol
DEFLAGS := -MMD -MP

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m

# Functions
define make_lib
    @echo "Making $1..."
    @make -C $2 
    @echo "$(GREEN)📚completed		$1$(DEF_COLOR)"
endef

all: make_libs $(NAME)
	@- rm -f .bonus
	@- rm -f ${OBJ_SRC_BONUS}
	@- rm -f $(OBJ_SRC_BONUS:%.o=%.d)

bonus: make_libs $(OBJ_BONUS) $(LIBFT_PATH)/libft.a $(BONUS_FILE)
	@$(CC) $(CFLAGS) ${OBJ_BONUS} -o $(NAME) $(MLX_LINK) $(LIBFT_LINK)
	@echo "$(GREEN)📚bonus completed		$(NAME)$(DEF_COLOR)"
	@touch .bonus
	@- rm -f ${OBJ_SRC_BASIC}
	@- rm -f ${DPS_SRC_BASIC}

make_libs:
	$(call make_lib,$(MLX_NAME),$(MLX_PATH))
	$(call make_lib,$(LIBFT_NAME),$(LIBFT_PATH))

$(NAME): $(OBJ) $(LIBFT_PATH)/libft.a
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_LINK) $(LIBFT_LINK)
	@echo "$(GREEN)📚completed		$(NAME)$(DEF_COLOR)"


$(BUILD_DIR)/%.o: %.c $(PREQ) | $(BUILD_DIR) 
	@$(CC) $(CFLAGS) $(DEFLAGS) -c $< -o $@
	@echo "$(GRAY)⏳compiling		$<$(DEF_COLOR)"
	
$(BUILD_DIR):
	@mkdir -p $@

$(BONUS_FILE): 
	@touch .bonus

clean:
	@rm -rf $(BUILD_DIR)
	@- rm -f .bonus
	@Make -C $(MLX_PATH) clean
	@Make -C $(LIBFT_PATH) clean
	@echo "$(RED)🧹clean		${NAME}$(DEF_COLOR)"

fclean:
	@rm -f $(NAME)
	@- rm .bonus
	@rm -rf $(BUILD_DIR)
	@Make -C $(MLX_PATH) clean
	@Make -C $(LIBFT_PATH) fclean
	@echo "$(RED)🧹fclean		${NAME}$(DEF_COLOR)"

re: fclean all

-include $(DPS)

.PHONY: re fclean clean all make_libs bonus