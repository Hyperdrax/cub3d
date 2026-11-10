//42-header

#include "cub3d.h"

int	parse_rgb(char *line, t_rgb *color)
{
	int	i;
	int	value;
	int	count;

	i = 0;
	value = -1;
	count = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			if (value == -1)
				value = 0;
			value = value * 10 + (line[i] - '0');
		}
		else if (line[i] == ',')
		{
			if (count == 0 && value >= 0 && value <= 255)
			{
				color->r = value;
				value = -1;
				count++;
			}
			else if (count == 1 && value >= 0 && value <= 255)
			{
				color->g = value;
				value = -1;
				count++;
			}
			else if (count == 2 && value >= 0 && value <= 255)
			{
				color->b = value;
				value = -1;
				count++;
			}
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	parse_f_c_color(char *line, t_data *data)
{
	if (line[0] == 'F')
	{
		parse_rgb(line + 2, &data->floor_color);
	}
	else if (line[0] == 'C')
	{
		parse_rgb(line + 2, &data->ceiling_color);
	}
	else
	{
		return (1);
	}
}
