/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:58:38 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/11 17:37:19 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

void	ft_forward(t_data *d)
{
	if (d->map[(d->i) - 1][(d->j)] == 'E')
	{
		if (d->collec > 0)
			ft_putstr_fd("You must collect every collectibles to escape\n", 1);
		else if (d->collec == 0)
			ft_destroy_windows(d);
	}
	if (d->map[d->i - 1][d->j] == 'C')
		d->collec--;
	if (d->map[(d->i) - 1][(d->j)] != '1')
	{
		if (d->map[d->i - 1][d->j] == 'E')
			d->map[(d->i - 1)][(d->j)] = 'D';
		else
			d->map[(d->i - 1)][(d->j)] = 'P';
		if (!(d->map[d->i][d->j] == 'E' || d->map[d->i][d->j] == 'D'))
			d->map[(d->i)][(d->j)] = '0';
		else if (d->map[d->i][d->j] == 'D')
			d->map[(d->i)][(d->j)] = 'E';
		d->i -= 1;
	}
	ft_putnbr_fd(++d->nbmoov, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_backward(t_data *d)
{
	if (d->map[(d->i) + 1][(d->j)] == 'E')
	{
		if (d->collec > 0)
			ft_putstr_fd("You must collect every collectibles to escape\n", 1);
		else if (d->collec == 0)
			ft_destroy_windows(d);
	}
	if (d->map[d->i + 1][d->j] == 'C')
		d->collec--;
	if (d->map[(d->i) + 1][(d->j)] != '1')
	{
		if (d->map[d->i + 1][d->j] == 'E')
			d->map[(d->i + 1)][(d->j)] = 'D';
		else
			d->map[(d->i + 1)][(d->j)] = 'P';
		if (!(d->map[d->i][d->j] == 'E' || d->map[d->i][d->j] == 'D'))
			d->map[(d->i)][(d->j)] = '0';
		else if (d->map[d->i][d->j] == 'D')
			d->map[(d->i)][(d->j)] = 'E';
		d->i += 1;
	}
	ft_putnbr_fd(++d->nbmoov, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_rightward(t_data *d)
{
	if (d->map[(d->i)][(d->j + 1)] == 'E')
	{
		if (d->collec > 0)
			ft_putstr_fd("You must collect every collectibles to escape\n", 1);
		else if (d->collec == 0)
			ft_destroy_windows(d);
	}
	if (d->map[d->i][d->j + 1] == 'C')
		d->collec--;
	if (d->map[(d->i)][(d->j) + 1] != '1')
	{
		if (d->map[d->i][d->j + 1] == 'E')
			d->map[(d->i)][(d->j) + 1] = 'D';
		else
			d->map[(d->i)][(d->j) + 1] = 'P';
		if (!(d->map[d->i][d->j] == 'E' || d->map[d->i][d->j] == 'D'))
			d->map[(d->i)][(d->j)] = '0';
		else if (d->map[d->i][d->j] == 'D')
			d->map[(d->i)][(d->j)] = 'E';
		d->j += 1;
	}
	ft_putnbr_fd(++d->nbmoov, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_leftward(t_data *d)
{
	if (d->map[(d->i)][(d->j) - 1] == 'E')
	{
		if (d->collec > 0)
			ft_putstr_fd("You must collect every collectibles to escape\n", 1);
		else if (d->collec == 0)
			ft_destroy_windows(d);
	}
	if (d->map[d->i][d->j - 1] == 'C')
		d->collec--;
	if (d->map[(d->i)][(d->j) - 1] != '1')
	{
		if (d->map[d->i][d->j - 1] == 'E')
			d->map[(d->i)][(d->j) - 1] = 'D';
		else
			d->map[(d->i)][(d->j) - 1] = 'P';
		if (!(d->map[d->i][d->j] == 'E' || d->map[d->i][d->j] == 'D'))
			d->map[(d->i)][(d->j)] = '0';
		else if (d->map[d->i][d->j] == 'D')
			d->map[(d->i)][(d->j)] = 'E';
		d->j -= 1;
	}
	ft_putnbr_fd(++d->nbmoov, 1);
	ft_putchar_fd('\n', 1);
}
