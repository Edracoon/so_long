/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stockage_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:34:01 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/10 11:42:50 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

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
		ft_error("Error\nYou are trying to open a directory\n");
	fd = open(file, O_RDONLY);
	if (!fd)
		ft_error("Error:\nCouldn't open the .ber\n");
	while (gnl > 0 && i < d->sizecollum)
	{
		gnl = get_next_line(fd, &line);
		d->map[i] = ft_strdup(line);
		free(line);
		line = NULL;
		i++;
	}
	i = -1;
	while (++i < d->sizecollum)
	{
		int j = -1;
		while (++j < d->sizeline)
			printf("%c", d->map[i][j]);
		printf("\n");
	}
}