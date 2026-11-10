
#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include "libft/libft.h"


typedef struct s_player
{
	int		x;
	int		y;
	char	direction;
}		t_player;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}		t_rgb;

typedef struct s_data
{
	t_player	player;
	char		**map;
	int			height;
	int			width;
	char		*no_tex;
	char		*so_tex;
	char		*we_tex;
	char		*ea_tex;
	t_rgb		floor_color;
	t_rgb		ceiling_color;
}		t_data;


// main.c

//parsing
	//parser.c
int	parser(char *cub_name, t_data *data);
int	open_file(char *cub_name);
//checker
	//check.c
int	check_extension(char *cub_name);

#endif
