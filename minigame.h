#ifndef MINIGAME_H
# define MINIGAME_H

# include "./mlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_img
{
	void	*collectible;
	void	*empty;
	void	*exit;
	void	*player;
	void	*wall;
}			t_img;

typedef struct  s_game
{
    int height;
    int width;
    char*   map_line;
    void	*mlx;
    void	*win;
    t_img	img;
    int		exit;
	int		player;
    int     player_idx;
	int		empty;
    int     collector;
    int     move_cnt;
	int		x;
	int		y;
}               t_game;

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void    check_map(t_game *game);
void	print_err(char *message);
void	check_element(t_game *game);
int     press_key(int key_code, t_game *game);
void	ft_putnbr(int nb);
int     end_game(t_game *game);
char	*withoutnl(char *line, int height);
void	before_read(const char *filename, t_game *game, int	*fd, char **line);
void	read_imgs(t_game *game);
void	read_map(const char *filename, t_game *game);
void	move_a(t_game   *game);
void	move_s(t_game   *game);
void	move_d(t_game   *game);
void	move_w(t_game   *game);
void	move_move(t_game *game, int idx);
int	    paint_map(t_game *game);
#endif