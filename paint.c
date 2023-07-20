#include "minigame.h"

void	paint_img(t_game *game, int x, int y, int i)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.empty, x, y);
	if (game->map_line[i] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall, x, y);
	else if (game->map_line[i] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img.player, x, y);
	else if (game->map_line[i] == 'C')
		mlx_put_image_to_window(game->mlx, \
		game->win, game->img.collectible, x, y);
	else if (game->map_line[i] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, x, y);
}

int	paint_map(t_game *game)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = -1;
	while (game->map_line[++i] && y <= 64 * game->height)
	{
		paint_img(game, x, y, i);
		x += 64;
		if (x == 64 * game->width)
		{
			x = 0;
			y += 64;
		}
	}
	return (0);
}
