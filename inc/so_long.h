#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../bin/minilibx_opengl_20191021/mlx.h"
# include "../ft_printf/ft_printf.h"

# define TITLE "so_long"
# define SCALE 64

# define COIN "res/coin.xpm"
# define EXIT "res/exit.xpm"
# define PLAYER "res/player.xpm"
# define TILE "res/tile.xpm"
# define WALL "res/wall.xpm"

# define ESC 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

typedef struct s_game
{
	void		*mlx;
	void		*win;

	int			map_height;
	int			map_width;
	char		**map;

	int			moves;
	int			coins;

	int			exit;
	int			ply;

	int			px;
	int			py;

	void		*player_s;
	void		*coin_s;
	void		*exit_s;
	void		*tile_s;
	void		*wall_s;
}	t_game;

void	start_game(char *path);
void	ft_reset(char *buffer);

int		map_validation(t_game *sl);
int 	ft_strlen(char *str);
int		key_game(int keycode, t_game *game);
int		draw_map(t_game *game);

char	**map_constractor(t_game *sl, int fd);

#endif