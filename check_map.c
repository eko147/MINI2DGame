#include "minigame.h"

void	check_element(t_game *game)
{
	int	i;

	game->collector = 0;
	game->player = 0;
	game->exit = 0;
	i = 0;
	while (game->map_line[i])
	{
		if (game->map_line[i] == 'C')
			game->collector++;
		else if (game->map_line[i] == 'P')
		{
			game->player_idx = i;
			game->player++;
		}
		else if (game->map_line[i] == 'E')
			game->exit++;
		else if (game->map_line[i] != '0' && game->map_line[i] != '1') 
			print_err("Invalid element");
		i++;
	}
	if (game->player != 1)
		print_err("player is not only one");
	if (game->exit != 1)
		print_err("exit is not only one");
}

void	check_playable_c(int width, int idx, int *colltmp, char *map_line)
{
	if (map_line[idx] == '1' || map_line[idx] == 'E') 
		return ;				
	if (map_line[idx] == 'C') 
		(*colltmp)--;
	map_line[idx] = '1'; 
	if (*colltmp == 0) 
		return ;
	check_playable_c(width, idx - width, colltmp, map_line);
	check_playable_c(width, idx + width, colltmp, map_line);
	check_playable_c(width, idx + 1, colltmp, map_line);
	check_playable_c(width, idx - 1, colltmp, map_line);
}


void	check_playable_e(int width, int idx, int *exittmp, char *map_line)
{
	if (map_line[idx] == '1')
		return ;				
	if (map_line[idx] == 'E')
		(*exittmp)--;
	map_line[idx] = '1';  
	if (*exittmp == 0)
		return ;
	check_playable_e(width, idx - width, exittmp, map_line);
	check_playable_e(width, idx + width, exittmp, map_line);
	check_playable_e(width, idx + 1, exittmp, map_line);
	check_playable_e(width, idx - 1, exittmp, map_line);
}

void	check_playable(t_game	*game)
{
	int		colltmp;
	int		exittmp;
	char	*map_line;

	exittmp = 1;
	map_line = ft_strdup(game->map_line);
	colltmp = game->collector;
	check_playable_c(game->width, game->player_idx, &colltmp, map_line);
	free(map_line);
	map_line = ft_strdup(game->map_line);
	check_playable_e(game->width, game->player_idx, &exittmp, map_line);
	free(map_line);
	if (colltmp != 0)
		print_err("map is not playable");
	if (exittmp != 0)
		print_err("map is not playable");
}

void	check_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	check_element(game);
	while ((game->map_line)[i])
	{
		if (i == j * game->width)
			j++;
		if (i < game->width && game->map_line[i] != '1')
			print_err("first line is not wall");
		else if (1 < j && j < game->height)
		{
			if (game->map_line[(game->width) * (j - 1)] != '1' \
			|| game->map_line[game->width * j - 1] != '1')
				print_err("side is not wall");
		}
		else if (j == game->height && game->map_line[i] != '1')
			print_err("last line is not wall");
		i++;
	}
	check_playable(game);
}
