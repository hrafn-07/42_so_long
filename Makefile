SRC = src/main.c \
		src/init.c \
		src/map_constraction.c \
		src/map_validation.c \
		src/utils.c \
		src/draw.c

OBJ = obj/*.o

NAME = so_long

ARG = maps/map4.ber

LIB = bin/minilibx_opengl_20191021
PRINTF = ft_printf/libftprintf.a
FRAMEWORKS = -framework AppKit -framework OpenGL

INC = inc

all: $(NAME)

$(NAME): $(LIB) $(PRINTF) $(OBJ)
	@make -C $(LIB)
	@gcc -o $(NAME) $(OBJ) $(FRAMEWORKS) $(LIB)/libmlx.a $(PRINTF)

$(PRINTF):
	@make -C ./ft_printf

$(OBJ): $(SRC)
	@gcc -c $^ -I $(INC);mv *.o obj

run: all
	@./$(NAME) $(ARG)

clean:
	@rm -rf obj/*.o
	@rm so_long

fclean: clean
	@rm -rf $(NAME)
	@make clean -C bin/minilibx_opengl_20191021

re: fclean all

.PHONY: all clean fclean re