/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 09:50:28 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/10 10:59:53 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, STDOUT_FILENO);
	exit(0);
}

int	check_map_name(char *av)
{
	int	len;

	len = ft_strlen(av);
	len -= 4;
	av = ft_substr(av, len, 4);
	if ((ft_strnstr(av, ".ber", 4)))
	{
		free(av);
		return (1);
	}
	free(av);
	return (0);
}

void	init_data(t_data *d)
{
	d->nbplayer = 0;
	d->win_x = 0;
	d->win_y = 0;
	d->minimap = 0;
	d->posx = 0;
	d->posy = 0;
	d->kill_win = 0;
	d->forward = 0;
	d->backward = 0;
	d->leftward = 0;
	d->rightward = 0;
	d->rot_left = 0;
	d->rot_right = 0;
}

int	main(int ac, char **av)
{
	t_data d;

	if (ac != 2)
		ft_error("Error:\nArguments\n");
	init_data(&d);
	if (!check_map_name(av[1]))
		ft_error("Error:\nMap name invalid\n");
	printf("ok\n");
	return (1);
}