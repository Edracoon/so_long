/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_ber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:07:47 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/10 16:55:33 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

void	map_malloc(t_data *d)
{
	int	i;

	i = -1;
	d->map = (char **)malloc(sizeof(char *) * (d->sizecollum));
	if (!(d->map))
		ft_error("Error\nMalloc error\n", d);
}

void	count_map_size(char	*line, t_data *d, int i)
{
	int	sizeline;

	if (!(line[0]))
		return ;
	sizeline = ft_strlen(line);
	if (i == 0)
		d->sizeline = sizeline;
	if (sizeline > d->sizeline || sizeline < d->sizeline)
		ft_error("Error\nMap is not rectangular\n", d);
	d->sizecollum += 1;
}

void	parse_ber(char *file, t_data *d)
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
	if (fd == -1)
		ft_error("Error\nCouldn't open the .ber\n", d);
	while (gnl > 0)
	{
		gnl = get_next_line(fd, &line);
		count_map_size(line, d, i);
		i++;
		free(line);
		line = NULL;
	}
	if (d->sizecollum > 0 && d->sizeline > 0)
		map_malloc(d);
	close(fd);
	stockage_map(d, file);
}
