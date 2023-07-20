#include "minigame.h"

void	print_err(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	exit(1);
}

void	check_filename(const char *filename)
{
	int	name_len;

	name_len = ft_strlen((char *)filename);
	if (name_len <= 4)
		print_err("Not a valid file\n");
	if (filename[name_len - 1] != 'r' || filename[name_len - 2] \
	!= 'e' || filename[name_len - 3] != 'b' || filename[name_len - 4] != '.')
		print_err("Invalid filetype");
}

int	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		print_err("wrong argument.\n");
	check_filename(argv[1]);
	read_map(argv[1], &game);
	check_map(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 64,\
	game.height * 64, "SO_LONG");
	game.move_cnt = 0;
	mlx_key_hook(game.win, press_key, &game);
	mlx_loop_hook(game.mlx, paint_map, &game);
	mlx_hook(game.win, 17, 0, end_game, &game);
	mlx_loop(game.mlx);
	return (0);
}

//so_long 이름 바꾸기 