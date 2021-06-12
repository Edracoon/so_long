/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stockage_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:34:01 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/12 16:00:10 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

int	is_char_valid(char c)
{
	if (c == '1' || c == '0' || c == 'E' || c == 'C' || c == 'P')
		return (1);
	return (0);
}

void	check_valid_char(int i, int j, t_data *d)
{
	if (i - 1 < 0 || j - 1 < 0
		|| j + 1 >= d->sizeline || i + 1 >= d->sizecollum)
		ft_error("Error\nMap isn't closed\n", d);
	if (d->map[i][j] == 'P')
	{
		d->pj = j;
		d->pi = i;
		d->nbplayer += 1;
		d->map[i][j] = 'P';
	}
	if (d->map[i][j] == 'C')
		d->collec += 1;
}

void	parse_map(t_data *d)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	d->collec = 0;
	while (++i < d->sizecollum)
	{
		j = -1;
		while (++j < d->sizeline)
		{
			if (!(is_char_valid(d->map[i][j])))
				ft_error("Error\nMap invalid (invalid char in map)\n", d);
			if (d->map[i][j] == '0' || d->map[i][j] == 'P' ||
				d->map[i][j] == 'E' || d->map[i][j] == 'C')
				check_valid_char(i, j, d);
			if (d->nbplayer > 1)
				ft_error("Error\nNumber of player error\n", d);
		}
	}
	if (d->nbplayer < 1)
		ft_error("Error\nNumber of player error\n", d);
}

void	stockage_map(t_data *d, char *file)
{
	int		fd;
	int		gnl;
	char	*line;
	int		i;

	i = 0;
	gnl = 1;
	fd = open(file, O_DIRECTORY);
	if (fd > 0)
		ft_error("Error\nYou are trying to open a directory\n", d);
	fd = open(file, O_RDONLY);
	if (!fd)
		ft_error("Error\nCouldn't open the .ber\n", d);
	while (gnl > 0 && i < d->sizecollum)
	{
		gnl = get_next_line(fd, &line);
		d->map[i] = ft_strdup(line);
		free(line);
		line = NULL;
		i++;
	}
	parse_map(d);
}
