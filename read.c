#include "minigame.h"

void	read_imgs(t_game *game)
{	
	int		img_width;
	int		img_height;

	game->img.collectible = mlx_xpm_file_to_image(game->mlx, \
	"./images/collectible.xpm", &img_width, &img_height);
	game->img.empty = mlx_xpm_file_to_image(game->mlx, \
	"./images/empty.xpm", &img_width, &img_height);
	game->img.player = mlx_xpm_file_to_image(game->mlx, \
	"./images/player.xpm", &img_width, &img_height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, \
	"./images/exit.xpm", &img_width, &img_height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, \
	"./images/wall.xpm", &img_width, &img_height);
}

char	*withoutnl(char *line, int height)
{
	int		idx;
	char	*line_nnl;
	char	*tmp;
	int		idx2;

	idx2 = 0;
	idx = 0;
	line_nnl = malloc(ft_strlen(line) - height + 2); 
	if (!line_nnl)
		print_err("Malloc Error\n");
	while (line[idx])
	{
		if (line[idx] != '\n')
			line_nnl[idx2++] = line[idx];
		idx++;
	}
	line_nnl[idx2] = '\0';
	tmp = line;
	free(tmp);
	return (line_nnl);
}

void	before_read(const char *filename, t_game *game, int	*fd, char **line)
{
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		print_err("Failed to open file.\n");
	*line = get_next_line(*fd);
	if (!*line)  
		print_err("The file is empty.\n");
	game->width = ft_strlen(*line) - 1;
	game->map_line = ft_strdup(*line);
	game->height = 1;
}

void	read_map(const char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	*tmp;
	int		line_len;

	line = 0;
	before_read(filename, game, &fd, &line);
	while (line)
	{
		line_len = ft_strlen(line) - 1;
		if (find_newline(line) < 0)
			line_len++;
		if (line_len != game->width)
			print_err("Is not_square");
		free(line); 
		line = get_next_line(fd);
		if (line == 0)  
			break ;
		tmp = game->map_line;
		game->map_line = ft_strjoin(game->map_line, line);
		free(tmp);
		game->height++;
	}
	game->map_line = withoutnl(game->map_line, game->height);
	close(fd);
}
