/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:38:41 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/12 17:48:04 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

void	affiche_perso(t_data *d, int x, int y)
{
	int				temp;

	temp = x;
	d->maxx = x + d->cubsize;
	d->maxy = y + d->cubsize;
	d->ty = 0;
	d->tx = 0;
	while (y < d->maxy)
	{
		x = temp;
		d->tx = 0;
		while (x < d->maxx)
		{
			d->color = get_color_textu(d, d->tx, d->ty, 1);
			if (d->color == 4278190080 && !(d->map[d->i][d->j] == 'D'))
				d->color = 0x0058bf7b;
			if (d->color == 4278190080 && d->map[d->i][d->j] == 'D')
				d->color = 0xff58bf7b;
			my_mlx_pixel_put(d, x, y, d->color);
			d->tx++;
			x++;
		}
		y++;
		d->ty++;
	}
}

void	affiche_cube(t_data *d, int x, int y, int couleur)
{
	int	max_y;
	int	max_x;
	int	temp;

	temp = y;
	max_y = y + d->cubsize;
	max_x = x + d->cubsize;
	while (x < max_x)
	{
		y = temp;
		while (y < max_y)
		{
			my_mlx_pixel_put(d, x, y, couleur);
			y++;
		}
		x++;
	}
}

void	affiche_wall(t_data *d, int x, int y)
{
	int				temp;

	temp = x;
	d->maxx = x + d->cubsize;
	d->maxy = y + d->cubsize;
	d->ty = 0;
	d->tx = 0;
	while (y < d->maxy)
	{
		x = temp;
		d->tx = 0;
		while (x < d->maxx)
		{
			d->color = get_color_textu(d, d->tx, d->ty, 2);
			my_mlx_pixel_put(d, x, y, d->color);
			d->tx++;
			x++;
		}
		y++;
		d->ty++;
	}
}

void	affiche_collectibles(t_data *d, int x, int y)
{
	int				temp;

	temp = x;
	d->maxx = x + d->cubsize;
	d->maxy = y + d->cubsize;
	d->ty = 0;
	d->tx = 0;
	while (y < d->maxy)
	{
		x = temp;
		d->tx = 0;
		while (x < d->maxx)
		{
			d->color = get_color_textu(d, d->tx, d->ty, 0);
			if (d->color == 4278190080)
				d->color = 0x0058bf7b;
			my_mlx_pixel_put(d, x, y, d->color);
			d->tx++;
			x++;
		}
		y++;
		d->ty++;
	}
}

void	affiche_door(t_data *d, int x, int y)
{
	int				temp;

	d->maxx = x + d->cubsize;
	d->maxy = y + d->cubsize;
	d->ty = 0;
	d->tx = 0;
	temp = x;
	while (y < d->maxy)
	{
		x = temp;
		d->tx = 0;
		while (x < d->maxx)
		{
			d->color = get_color_textu(d, d->tx, d->ty, 3);
			if (d->color == 4278190080)
				d->color = 0x0058bf7b;
			my_mlx_pixel_put(d, x, y, d->color);
			d->tx++;
			x++;
		}
		y++;
		d->ty++;
	}
}
