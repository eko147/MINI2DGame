#include "minigame.h"

int	press_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		end_game(game);
	if (key_code == KEY_W)
		move_w(game);
	if (key_code == KEY_A)
		move_a(game);
	if (key_code == KEY_S)
		move_s(game);
	if (key_code == KEY_D)
		move_d(game);
	return (0);
}
