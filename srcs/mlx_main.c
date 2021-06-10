/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:10:08 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/10 13:42:28 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

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

int	key_released(int keycode, t_data *d)
{
	if (keycode == 53)
		d->kill_win = 0;
	if (keycode == 13)
		d->forward = 0;
	if (keycode == 1)
		d->backward = 0;
	if (keycode == 2)
		d->rightward = 0;
	if (keycode == 0)
		d->leftward = 0;
	return (0);
}

int	ft_destroy_windows(t_data *d)
{
	mlx_destroy_window(d->mlx->mlx, d->mlx->mlx_win);
	exit(1);
	return (1);
}

void	my_mlx_pixel_put(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->mlx->addr + (y * d->mlx->line_length + x * (d->mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	affiche_perso(t_data *d, int x, int y, int couleur)
{
	int	max_y;
	int	max_x;
	int	temp;

	temp = y;
	max_y = y + (d->cubsize) + 4 - 1;
	max_x = x + (d->cubsize) + 4 - 1;
	while (x < max_x)
	{
		y = temp;
		while (y < max_y)
			my_mlx_pixel_put(d, x, y++, couleur);
		x++;
	}
}

void	affiche_cube(t_data *d, int x, int y, int couleur)
{
	int		max_y;
	int		max_x;
	int		temp;

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
	while (d->sizecollum > i && d->map[i][j])
	{
		x = 0;
		while (d->sizeline > j && d->map[i][j])
		{
			if (d->map[i][j] == '1')
				affiche_cube(d, x, y, 0x00117864);
			if (d->map[i][j] == '0')
				affiche_cube(d, x, y, 0x0048c9b0);
			if (d->map[i][j] == '2')
				affiche_cube(d, x, y, 0x00ff0000);
			affiche_perso(d, d->posx * d->cubsize, d->posy * d->cubsize, 0x00ebfe00);
			x += d->cubsize;
			j++;
		}
		i++;
		j = 0;
		y += d->cubsize;
	}
}

int	ft_affiche_image(t_data *d)
{
	affiche_minimap(d, 0, 0, 0);
	mlx_put_image_to_window(d->mlx->mlx, d->mlx->mlx_win, d->mlx->img, 0, 0);
	return (0);
}

void	mlx_main(t_data *d)
{
	d->mlx->mlx = mlx_init();
	d->mlx->mlx_win = mlx_new_window(d->mlx, d->win_x, d->win_y, "so_long");
	d->mlx->img = mlx_new_image(d->mlx, d->win_x, d->win_y);
	d->mlx->addr = mlx_get_data_addr(d->mlx->img, \
		&d->mlx->bits_per_pixel, &d->mlx->line_length, &d->mlx->endian);
	mlx_hook(d->mlx->mlx_win, 2, 1L << 0, key_pressed, d);
	mlx_hook(d->mlx->mlx_win, 3, 1L << 1, key_released, d);
	mlx_hook(d->mlx->mlx_win, 17, 0, ft_destroy_windows, d);
	mlx_loop_hook(d->mlx, ft_affiche_image, d);
	mlx_loop(d->mlx);
}