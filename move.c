#include "minigame.h"


void	move_move(t_game *game, int idx)
{
	if (game->map_line[idx] == '0')
	{
		game->map_line[idx] = 'P';
		game->map_line[game->player_idx] = '0';
	}
	if (game->map_line[idx] == 'C')
	{
		game->map_line[idx] = 'P';
		game->map_line[game->player_idx] = '0';
		game->collector--;
	}
	if (game->map_line[idx] == 'E')
		if (game->collector == 0)
			end_game(game);
	game->move_cnt++;
	write(1, "move: ", 6);
	ft_putnbr(game->move_cnt);
	write(1, "\n", 1);
	game->player_idx = idx; 
}

void	move_w(t_game *game)
{
	int	move_idx;

	move_idx = game->player_idx - game->width;
	if (game->map_line[move_idx] != '1')
		move_move(game, move_idx);
}

void	move_a(t_game *game)
{
	int	move_idx;

	move_idx = game->player_idx - 1;
	if (game->map_line[move_idx] != '1')
		move_move(game, move_idx);
}

void	move_s(t_game *game)
{
	int	move_idx;

	move_idx = game->player_idx + game->width;
	if (game->map_line[move_idx] != '1')
		move_move(game, move_idx);
}

void	move_d(t_game *game)
{
	int	move_idx;

	move_idx = game->player_idx + 1;
	if (game->map_line[move_idx] != '1')
		move_move(game, move_idx);
}
