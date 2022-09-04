/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktuncbil <ktuncbil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:26:25 by ktuncbil          #+#    #+#             */
/*   Updated: 2022/09/04 17:34:28 by ktuncbil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			if (game->map[y][x] == 'P')
			{
				game->px = x;
				game->py = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	sprite_init(t_game *game)
{
	int	x;
	int	y;

	game->player_s = mlx_xpm_file_to_image(game->mlx, PLAYER, &x, &y);
	game->coin_s = mlx_xpm_file_to_image(game->mlx, COIN, &x, &y);
	game->exit_s = mlx_xpm_file_to_image(game->mlx, EXIT, &x, &y);
	game->tile_s = mlx_xpm_file_to_image(game->mlx, TILE, &x, &y);
	game->wall_s = mlx_xpm_file_to_image(game->mlx, WALL, &x, &y);
}

t_game	*game_init(char *path)
{
	t_game	*new;

	new = (t_game *) malloc(sizeof(t_game));
	new->mlx = mlx_init();
	new->map = map_constractor(new, open(path, O_RDONLY));
	new->moves = 0;
	new->coins = 0;
	if (map_validation(new))
	{
		exit(1);
		free(new);
	}
	new->win = mlx_new_window(new->mlx, new->map_width * SCALE,
			new->map_height * SCALE, TITLE);
	mlx_hook(new->win, 2, (1L << 0), key_game, new);
	sprite_init(new);
	find_player(new);
	return (new);
}

void	start_game(char *path)
{
	t_game	*game;

	game = game_init(path);
	draw_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->player_s,
		game->px * SCALE, game->py * SCALE);
	mlx_loop(game->mlx);
}
