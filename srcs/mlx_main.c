/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:10:08 by epfennig          #+#    #+#             */
/*   Updated: 2021/08/28 19:09:42 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

void	print_backgroundcolor(t_data *d, int i, int j)
{
	j = 0;
	while (i < d->win_y)
	{
		j = 0;
		while (j < d->win_x)
		{
			my_mlx_pixel_put(d, j, i, 0xff000000);
			j++;
		}
		i++;
	}
}

void	boucle_x_norme(t_data *d, int y)
{
	int	x;

	x = 0;
	while (d->sizeline > d->j && d->map[d->i][d->j] && x < 21 * d->cubsize)
	{
		if (d->map[d->i][d->j] == '1')
			mlx_put_image_to_window(d->mlx, d->mlx_win, d->text[MUR].img, x, y);
		if (d->map[d->i][d->j] == '0')
			mlx_put_image_to_window(d->mlx, d->mlx_win, d->text[FLOOR].img, x, y);
		if (d->map[d->i][d->j] == 'C')
		{
			mlx_put_image_to_window(d->mlx, d->mlx_win, d->text[FLOOR].img, x, y);
			mlx_put_image_to_window(d->mlx, d->mlx_win, d->text[CHICKEN].img, x, y);
		}
		if (d->map[d->i][d->j] == 'E')
		{
			mlx_put_image_to_window(d->mlx, d->mlx_win, d->text[FLOOR].img, x, y);
			mlx_put_image_to_window(d->mlx, d->mlx_win, d->text[DOOR].img, x, y);
		}
		if (d->map[d->i][d->j] == 'P')
		{
			mlx_put_image_to_window(d->mlx, d->mlx_win, d->text[FLOOR].img, x, y);
			mlx_put_image_to_window(d->mlx, d->mlx_win, d->text[d->playdir].img, x, y);
		}
		if (d->map[d->i][d->j] == 'D')
		{
			mlx_put_image_to_window(d->mlx, d->mlx_win, d->text[FLOOR].img, x, y);
			mlx_put_image_to_window(d->mlx, d->mlx_win, d->text[DOOR].img, x, y);
			mlx_put_image_to_window(d->mlx, d->mlx_win, d->text[d->playdir].img, x, y);
		}
		x += d->cubsize;
		d->j++;
	}
}

void	affiche_minimap(t_data *d)
{
	int	y;

	y = 0;
	d->i = 0;
	d->j = 0;
	d->i = mapi_chose(d->i, d);
	d->j = mapj_chose(d->j, d);
	while (d->sizecollum > d->i && d->map[d->i][d->j] && y < 9 * d->cubsize)
	{
		boucle_x_norme(d, y);
		d->i++;
		d->j = 0;
		d->j = mapj_chose(d->j, d);
		y += d->cubsize;
	}
}

int	ft_affiche_image(t_data *d)
{
	print_backgroundcolor(d, 0, 0);
	affiche_minimap(d);
	ft_mouvement(d);
	// mlx_put_image_to_window(d->mlx, d->mlx_win, d->img, 0, 0);
	return (0);
}

void	mlx_main(t_data *d)
{
	d->mlx = mlx_init();
	d->mlx_win = mlx_new_window(d->mlx, d->win_x, d->win_y, "so_long");
	d->img = mlx_new_image(d->mlx, d->win_x, d->win_y);
	d->addr = mlx_get_data_addr(d->img, \
		&d->bits_per_pixel, &d->line_length, &d->endian);
	get_xpm_textures(d);
	mlx_hook(d->mlx_win, 2, 1L << 0, key_pressed, d);
	mlx_hook(d->mlx_win, 17, 0, ft_destroy_windows, d);
	mlx_loop_hook(d->mlx, ft_affiche_image, d);
	mlx_loop(d->mlx);
}
