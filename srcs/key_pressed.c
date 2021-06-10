/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:59:55 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/10 17:02:03 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

int	ft_destroy_windows(t_data *d)
{
	mlx_destroy_window(d->mlx, d->mlx_win);
	ft_putstr_fd("Game over\n", 1);
	exit(1);
	return (1);
}

int	key_pressed(int keycode, t_data *d)
{
	if (keycode == 53)
		d->kill_win = 1;
	if (keycode == 13)
		d->forward = 1;
	if (keycode == 1)
		d->backward = 1;
	if (keycode == 2)
		d->rightward = 1;
	if (keycode == 0)
		d->leftward = 1;
	return (0);
}

void	reset_mouvement(t_data *d)
{
	d->kill_win = 0;
	d->forward = 0;
	d->backward = 0;
	d->rightward = 0;
	d->leftward = 0;
}

int	ft_mouvement(t_data *d)
{
	if (d->kill_win)
		ft_destroy_windows(d);
	if (d->forward)
		ft_forward(d);
	if (d->backward)
		ft_backward(d);
	if (d->rightward)
		ft_rightward(d);
	if (d->leftward)
		ft_leftward(d);
	if (d->map[(d->posy / d->cubsize)][(d->posx / d->cubsize)] == 'C')
	{
		d->map[(d->posy / d->cubsize)][(d->posx / d->cubsize)] = '0';
		d->collec -= 1;
	}
	reset_mouvement(d);
	return (0);
}
