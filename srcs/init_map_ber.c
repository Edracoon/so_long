/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_ber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:07:47 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/10 11:40:09 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

void	map_malloc(t_data *d)
{
	int	i;

	i = -1;
	printf("size collum = %i | sizeline = %i\n", d->sizecollum, d->sizeline);
	d->map = (char **)malloc(sizeof(char *) * (d->sizecollum + 1));
	if (!(d->map))
		ft_error("Error:\nMalloc error\n");
	while (++i < d->sizecollum)
	{
		d->map[i] = (char *)malloc(sizeof(char) * (d->sizeline + 1));
		if (!(d->map[i]))
			ft_error("Error:\nMalloc error\n");
	}

}

void	count_map_size(char	*line, t_data *d)
{
	int	sizeline;

	sizeline = ft_strlen(line);
	if (sizeline > d->sizeline)
		d->sizeline = sizeline;
	d->sizecollum += 1;
}

void	parse_ber(char *file, t_data *d)
{
	int		fd;
	int		gnl;
	char	*line;

	gnl = 1;
	fd = open(file, O_DIRECTORY);
	if (fd > 0)
		ft_error("Error\nYou are trying to open a directory\n");
	fd = open(file, O_RDONLY);
	if (!fd)
		ft_error("Error:\nCouldn't open the .ber\n");
	while (gnl > 0)
	{
		gnl = get_next_line(fd, &line);
		count_map_size(line, d);
		free(line);
		line = NULL;
	}
	if (d->sizecollum > 0 && d->sizeline > 0)
		map_malloc(d);
	close(fd);
	stockage_map(d, file);
}