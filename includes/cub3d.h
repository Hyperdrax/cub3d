
#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_player
{
	int			x;
	int			y;
	char		direction;
}				t_player;

typedef struct s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct s_data
{
	t_player	player;
	char		**raw_data;
	char		**map;
	int			height;
	int			width;
	char		*no_tex;
	char		*so_tex;
	char		*we_tex;
	char		*ea_tex;
	t_rgb		floor_color;
	t_rgb		ceiling_color;
}				t_data;

typedef enum e_error_codes
{
	ERR_OK = 0,					// No error
	ERR_USAGE = 1,				// Incorrect usage (e.g. wrong argument number)
	ERR_FILE_EXTENSION = 2,		// File extension is not .cub
	ERR_FILE_OPEN = 3,			// File could not be opened (e.g. file doesn't exist, permission denied)
	ERR_FILE_READ = 4,			// File could not be read
	ERR_ALLOC = 5,				// Memory allocation failed
	ERR_UNKNOWN_IDENTIFIER = 6,	// Unknown identifier in the .cub file
	ERR_DUPLICATE_ELEMENT = 7,	// Duplicate element in the .cub file
	ERR_MISSING_ELEMENT = 8,	// Missing required element in .cub file
	ERR_INVALID_COLOR_LINE = 9,	// Invalid color (e.g. wrong format, values...)
	ERR_INVALID_RGB = 10,		// Invalid RGB value (e.g. not a number)
	ERR_RGB_RANGE = 11,			// RGB out of range (0-255)
	ERR_TEXTURE_LOAD = 12,		// texture file doen't exist, permission denied)
	ERR_INVALID_MAP_CHAR = 13,	// (Not a 1, 0, or space or player direction)
	ERR_MAP_NOT_CLOSED = 14,	// Map is not closed (e.g. open/missing walls)
	ERR_PLAYER_COUNT = 15,		// Not exactly one player in the map!
	ERR_EMPTY_FILE = 16,		// The .cub file is empty
	ERR_TEXTURE_PATH = 17,		// Texture path is invalid
	ERR_MISSING_MAP = 18,		// The map is missing in the .cub file
	ERR_MAP_INTERRUPTED = 19	// Map is interrupted by empty lines/other elements
}				t_error_code;

// main.c

// parsing
// parser.c
int				parser(char *cub_name, t_data *data);
int				open_file(char *cub_name);
// checker
// check.c
int				check_extension(char *cub_name);

#endif
