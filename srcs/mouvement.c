/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:58:38 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/11 12:36:38 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

void	ft_forward(t_data *d)
{
	if (d->map[(d->posy / d->cubsize) - 1][(d->posx / d->cubsize)] != '1')
		d->posy -= 1;
	if (d->map[(d->posy / d->cubsize)][(d->posx / d->cubsize)] == 'E')
	{
		if (d->collec > 0)
			ft_putstr_fd("You must collect every collectibles to escape\n", 1);
		else if (d->collec == 0)
			ft_destroy_windows(d);
	}
	ft_putnbr_fd(++d->nbmoov, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_backward(t_data *d)
{
	if (d->map[(d->posy / d->cubsize) + d->i + 1][(d->posx / d->cubsize)] != '1')
		d->posy += 1;
	if (d->map[(d->posy / d->cubsize)][(d->posx / d->cubsize)] == 'E')
	{
		if (d->collec > 0)
			ft_putstr_fd("You must collect every collectibles to escape\n", 1);
		else if (d->collec == 0)
			ft_destroy_windows(d);
	}
	ft_putnbr_fd(++d->nbmoov, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_rightward(t_data *d)
{
	if (d->map[(d->posy / d->cubsize)][(d->posx / d->cubsize) + 1] != '1')
		d->posx += 1;
	if (d->map[(d->posy / d->cubsize)][(d->posx / d->cubsize)] == 'E')
	{
		if (d->collec > 0)
			ft_putstr_fd("You must collect every collectibles to escape\n", 1);
		else if (d->collec == 0)
			ft_destroy_windows(d);
	}
	ft_putnbr_fd(++d->nbmoov, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_leftward(t_data *d)
{
	if (d->map[(d->posy / d->cubsize)][(d->posx / d->cubsize) - 1] != '1')
		d->posx -= 1;
	if (d->map[(d->posy / d->cubsize)][(d->posx / d->cubsize)] == 'E')
	{
		if (d->collec > 0)
			ft_putstr_fd("You must collect every collectibles to escape\n", 1);
		else if (d->collec == 0)
			ft_destroy_windows(d);
	}
	ft_putnbr_fd(++d->nbmoov, 1);
	ft_putchar_fd('\n', 1);
}
