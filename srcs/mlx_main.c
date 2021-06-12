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

unsigned int	get_color_textu(t_data *d, int x, int y, int nb)
{
	char	*dst;

	dst = d->text[nb].addr + (y * d->text[nb].line_length +\
		x * (d->text[nb].bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	affiche_perso(t_data *d, int x, int y, int i, int j)
{
	unsigned int	color;
	int				tx;
	int				ty;
	int				maxx;
	int				maxy;

	maxx = x + d->cubsize;
	maxy = y + d->cubsize;
	ty = 0;
	tx = 0;
	int temp = x;
	while (y < maxy)
	{
		x = temp;
		tx = 0;
		while (x < maxx)
		{
			color = get_color_textu(d, tx, ty, 1);
			if (color == 4278190080)
			{
				color = 0x0058bf7b;
				if (d->map[i][j] == 'D')
					color = 0xff000000;
			}
			my_mlx_pixel_put(d, x, y, color);
			tx++;
			x++;
		}
		y++;
		ty++;
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
	unsigned int	color;
	int				tx;
	int				ty;
	int				maxx;
	int				maxy;

	maxx = x + d->cubsize;
	maxy = y + d->cubsize;
	ty = 0;
	tx = 0;
	int temp = x;
	while (y < maxy)
	{
		x = temp;
		tx = 0;
		while (x < maxx)
		{
			color = get_color_textu(d, tx, ty, 2);
			if (color == 4278190080)
				color = 0x0048c9b0;
			my_mlx_pixel_put(d, x, y, color);
			tx++;
			x++;
		}
		y++;
		ty++;
	}
}

void	affiche_collectibles(t_data *d, int x, int y)
{
	unsigned int	color;
	int				tx;
	int				ty;
	int				maxx;
	int				maxy;

	maxx = x + d->cubsize;
	maxy = y + d->cubsize;
	ty = 0;
	tx = 0;
	int temp = x;
	while (y < maxy)
	{
		x = temp;
		tx = 0;
		while (x < maxx)
		{
			color = get_color_textu(d, tx, ty, 0);
			if (color == 4278190080)
				color = 0x0058bf7b;
			my_mlx_pixel_put(d, x, y, color);
			tx++;
			x++;
		}
		y++;
		ty++;
	}
}

void	affiche_door(t_data *d, int x, int y)
{
	unsigned int	color;
	int				tx;
	int				ty;
	int				maxx;
	int				maxy;

	maxx = x + d->cubsize;
	maxy = y + d->cubsize;
	ty = 0;
	tx = 0;
	int temp = x;
	while (y < maxy)
	{
		x = temp;
		tx = 0;
		while (x < maxx)
		{
			color = get_color_textu(d, tx, ty, 3);
			if (color == 4278190080)
				color = 0x0058bf7b;
			my_mlx_pixel_put(d, x, y, color);
			tx++;
			x++;
		}
		y++;
		ty++;
	}
}

int	mapi_chose(int i, t_data *d)
{
	if (d->i > 8)
		i = 9;
	if (d->i > 17)
		i = 18;
	if (d->i > 26)
		i = 27;
	if (d->i > 35)
		i = 36;
	if (d->i > 44)
		i = 45;
	if (d->i > 53)
		i = 54;
	if (d->i > 62)
		i = 63;
	if (d->i > 71)
		i = 72;
	if (d->i > 80)
		i = 81;
	return (i);
}

int	mapj_chose(int j, t_data *d)
{
	if (d->j > 20)
		j = 21;
	if (d->j > 41)
		j = 42;
	if (d->j > 62)
		j = 63;
	if (d->j > 83)
		j = 84;
	if (d->j > 104)
		j = 105;
	if (d->j > 125)
		j = 126;
	if (d->j > 146)
		j = 147;
	if (d->j > 167)
		j = 168;
	if (d->j > 188)
		j = 189;
	return (j);
}

void	affiche_minimap(t_data *d, int x, int y, int i)
{
	int	j;

	j = 0;
	while (i < d->win_y - 1)
	{
		j = 0;
		while (j < d->win_x)
		{
			my_mlx_pixel_put(d, j, i, 0x0058bf7b);
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	i = mapi_chose(i, d);
	j = mapj_chose(j, d);
	while (d->sizecollum > i && d->map[i][j] && y < 9 * d->cubsize)
	{
		x = 0;
		while (d->sizeline > j && d->map[i][j] && x < 21 * d->cubsize)
		{
			if (d->map[i][j] == '1')
				affiche_wall(d, x, y);
			if (d->map[i][j] == '0')
				affiche_cube(d, x, y, 0x0058bf7b);
			if (d->map[i][j] == 'C')
				affiche_collectibles(d, x, y);
			if (d->map[i][j] == 'E' || d->map[i][j] == 'D')
				affiche_door(d, x, y);
			if (d->map[i][j] == 'P' || d->map[i][j] == 'D')
				affiche_perso(d, x, y, i, j);
			x += d->cubsize;
			j++;
		}
		i++;
		j = 0;
		j = mapj_chose(j, d);
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

void	get_xpm_textures(t_data *d)
{
	int	imgsiz = 56;
	d->text[0].img = mlx_xpm_file_to_image(d->mlx, \
		"/Users/epfennig/Desktop/so_long/textures/ChickenLeg.xpm", &imgsiz, &imgsiz);
	d->text[1].img = mlx_xpm_file_to_image(d->mlx, \
		"/Users/epfennig/Desktop/so_long/textures/viking.xpm", &imgsiz, &imgsiz);
	d->text[2].img = mlx_xpm_file_to_image(d->mlx, \
		"/Users/epfennig/Desktop/so_long/textures/blocks.xpm", &imgsiz, &imgsiz);
	d->text[3].img = mlx_xpm_file_to_image(d->mlx, \
		"/Users/epfennig/Desktop/so_long/textures/door.xpm", &imgsiz, &imgsiz);
	printf("good\n");
	d->text[0].addr = mlx_get_data_addr(d->text[0].img,
		&d->text[0].bits_per_pixel,
			&d->text[0].line_length, &d->text[0].endian);
	d->text[1].addr = mlx_get_data_addr(d->text[1].img,
		&d->text[1].bits_per_pixel,
			&d->text[1].line_length, &d->text[1].endian);
	d->text[2].addr = mlx_get_data_addr(d->text[2].img,
		&d->text[2].bits_per_pixel,
			&d->text[2].line_length, &d->text[2].endian);
	d->text[3].addr = mlx_get_data_addr(d->text[3].img,
		&d->text[3].bits_per_pixel,
			&d->text[3].line_length, &d->text[3].endian);
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
