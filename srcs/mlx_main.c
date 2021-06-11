/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:10:08 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/11 19:36:17 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

void	affiche_perso(t_data *d, int x, int y, int couleur)
{
	int	max_y;
	int	max_x;
	int	temp;

	temp = y;
	max_y = y + (d->cubsize) - (d->cubsize / 4);
	max_x = x + (d->cubsize) - (d->cubsize / 4);
	while (x + (d->cubsize / 4) < max_x)
	{
		y = temp;
		while (y + (d->cubsize / 4) < max_y)
			my_mlx_pixel_put(d, x + (d->cubsize / 4), \
				(d->cubsize / 4) + y++, couleur);
		x++;
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

void	affiche_minimap(t_data *d, int x, int y, int i)
{
	int	j;

	j = 0;
	while (i < d->win_y)
	{
		j = 0;
		while (j < d->win_x)
		{
			my_mlx_pixel_put(d, j, i, 0x0048c9b0);
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	i = d->ymapindex * 8;
	j = d->xmapindex * 20;
	if (d->i > d->ymapindex * 8)
		d->ymapindex++;
	else if (d->i < d->ymapindex - 1 * 8)
		d->ymapindex--;
	if (d->j > d->xmapindex * 20)
		d->xmapindex++;
	else if (d->j < d->xmapindex - 1 * 20)
		d->xmapindex--;
	while (d->sizecollum > i && d->map[i][j] && y < 9 * d->cubsize)
	{
		x = 0;
		while (d->sizeline > j && d->map[i][j] && x < 21 * d->cubsize)
		{
			if (d->map[i][j] == '1')
				affiche_cube(d, x, y, 0x00117864);
			if (d->map[i][j] == '0')
				affiche_cube(d, x, y, 0x0048c9b0);
			if (d->map[i][j] == 'C')
				affiche_cube(d, x, y, 0x00ff0000);
			if (d->map[i][j] == 'E' || d->map[i][j] == 'D')
				affiche_cube(d, x, y, 0x0036f3ff);
			if (d->map[i][j] == 'P' ||d->map[i][j] == 'D')
				affiche_perso(d, x, y, 0x00ebfe00);
			x += d->cubsize;
			j++;
		}
		i++;
		if (d->j > d->xmapindex * 20)
			d->xmapindex++;
		else if (d->j < d->xmapindex - 1 * 20)
			d->xmapindex--;
		j = d->xmapindex * 20;
		y += d->cubsize;
	}
}

int	ft_affiche_image(t_data *d)
{
	affiche_minimap(d, 0, 0, 0);
	ft_mouvement(d);
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->img, 0, 0);
	return (0);
}

void	mlx_main(t_data *d)
{
	d->mlx = mlx_init();
	d->mlx_win = mlx_new_window(d->mlx, d->win_x, d->win_y, "so_long");
	d->img = mlx_new_image(d->mlx, d->win_x, d->win_y);
	d->addr = mlx_get_data_addr(d->img, \
		&d->bits_per_pixel, &d->line_length, &d->endian);
	mlx_hook(d->mlx_win, 2, 1L << 0, key_pressed, d);
	mlx_hook(d->mlx_win, 17, 0, ft_destroy_windows, d);
	mlx_loop_hook(d->mlx, ft_affiche_image, d);
	mlx_loop(d->mlx);
}
