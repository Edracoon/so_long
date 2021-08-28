/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:58:38 by epfennig          #+#    #+#             */
/*   Updated: 2021/08/28 19:26:09 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

void	ft_forward(t_data *d)
{
	if (d->map[(d->pi) - 1][(d->pj)] == 'E')
	{
		if (d->collec > 0)
			ft_putstr_fd("You must collect every collectibles to escape\n", 1);
		else if (d->collec == 0)
			ft_destroy_windows(d);
	}
	if (d->map[d->pi + 1][d->pj] == 'C')
	{
		d->collec--;
	}
	if (d->map[(d->pi) - 1][(d->pj)] != '1')
	{
		ft_putnbr_fd(++d->nbmoov, 1);
		ft_putchar_fd('\n', 1);
		if (d->map[d->pi - 1][d->pj] == 'E')
			d->map[(d->pi - 1)][(d->pj)] = 'D';
		else
			d->map[(d->pi - 1)][(d->pj)] = 'P';
		if (!(d->map[d->pi][d->pj] == 'E' || d->map[d->pi][d->pj] == 'D'))
			d->map[(d->pi)][(d->pj)] = '0';
		else if (d->map[d->pi][d->pj] == 'D')
			d->map[(d->pi)][(d->pj)] = 'E';
		d->pi -= 1;
	}
	d->playdir = 5;
}

void	ft_backward(t_data *d)
{
	if (d->map[(d->pi) + 1][(d->pj)] == 'E')
	{
		if (d->collec > 0)
			ft_putstr_fd("You must collect every collectibles to escape\n", 1);
		else if (d->collec == 0)
			ft_destroy_windows(d);
	}
	if (d->map[d->pi + 1][d->pj] == 'C')
		d->collec--;
	if (d->map[(d->pi) + 1][(d->pj)] != '1')
	{
		ft_putnbr_fd(++d->nbmoov, 1);
		ft_putchar_fd('\n', 1);
		if (d->map[d->pi + 1][d->pj] == 'E')
			d->map[(d->pi + 1)][(d->pj)] = 'D';
		else
			d->map[(d->pi + 1)][(d->pj)] = 'P';
		if (!(d->map[d->pi][d->pj] == 'E' || d->map[d->pi][d->pj] == 'D'))
			d->map[(d->pi)][(d->pj)] = '0';
		else if (d->map[d->pi][d->pj] == 'D')
			d->map[(d->pi)][(d->pj)] = 'E';
		d->pi += 1;
	}
	d->playdir = 7;
}

void	ft_rightward(t_data *d)
{
	if (d->map[(d->pi)][(d->pj + 1)] == 'E')
	{
		if (d->collec > 0)
			ft_putstr_fd("You must collect every collectibles to escape\n", 1);
		else if (d->collec == 0)
			ft_destroy_windows(d);
	}
	if (d->map[d->pi][d->pj + 1] == 'C')
		d->collec--;
	if (d->map[(d->pi)][(d->pj) + 1] != '1')
	{
		ft_putnbr_fd(++d->nbmoov, 1);
		ft_putchar_fd('\n', 1);
		if (d->map[d->pi][d->pj + 1] == 'E')
			d->map[(d->pi)][(d->pj) + 1] = 'D';
		else
			d->map[(d->pi)][(d->pj) + 1] = 'P';
		if (!(d->map[d->pi][d->pj] == 'E' || d->map[d->pi][d->pj] == 'D'))
			d->map[(d->pi)][(d->pj)] = '0';
		else if (d->map[d->pi][d->pj] == 'D')
			d->map[(d->pi)][(d->pj)] = 'E';
		d->pj += 1;
	}
	d->playdir = 6;
}

void	ft_leftward(t_data *d)
{
	if (d->map[(d->pi)][(d->pj) - 1] == 'E')
	{
		if (d->collec > 0)
			ft_putstr_fd("You must collect every collectibles to escape\n", 1);
		else if (d->collec == 0)
			ft_destroy_windows(d);
	}
	if (d->map[d->pi][d->pj - 1] == 'C')
		d->collec--;
	if (d->map[(d->pi)][(d->pj) - 1] != '1')
	{
		ft_putnbr_fd(++d->nbmoov, 1);
		ft_putchar_fd('\n', 1);
		if (d->map[d->pi][d->pj - 1] == 'E')
			d->map[(d->pi)][(d->pj) - 1] = 'D';
		else
			d->map[(d->pi)][(d->pj) - 1] = 'P';
		if (!(d->map[d->pi][d->pj] == 'E' || d->map[d->pi][d->pj] == 'D'))
			d->map[(d->pi)][(d->pj)] = '0';
		else if (d->map[d->pi][d->pj] == 'D')
			d->map[(d->pi)][(d->pj)] = 'E';
		d->pj -= 1;
	}
	d->playdir = 1;
}
