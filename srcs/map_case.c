/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:36:44 by epfennig          #+#    #+#             */
/*   Updated: 2021/08/28 19:25:53 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

void	get_xpm_textures(t_data *d)
{
	int	imgsiz;

	imgsiz = 56;
	d->text[0].img = mlx_xpm_file_to_image(d->mlx, "./textures/ChickenLeg.xpm",
			&imgsiz, &imgsiz);
	d->text[1].img = mlx_xpm_file_to_image(d->mlx, "./textures/viking_left.xpm",
			&imgsiz, &imgsiz);
	d->text[2].img = mlx_xpm_file_to_image(d->mlx, "./textures/mur.xpm",
			&imgsiz, &imgsiz);
	d->text[3].img = mlx_xpm_file_to_image(d->mlx, "./textures/door.xpm",
			&imgsiz, &imgsiz);
	d->text[4].img = mlx_xpm_file_to_image(d->mlx, "./textures/floor.xpm",
			&imgsiz, &imgsiz);
	d->text[5].img = mlx_xpm_file_to_image(d->mlx, "./textures/viking_back.xpm",
			&imgsiz, &imgsiz);
	d->text[6].img = mlx_xpm_file_to_image(d->mlx, "./textures/viking_right.xpm",
			&imgsiz, &imgsiz);
	d->text[7].img = mlx_xpm_file_to_image(d->mlx, "./textures/viking_front.xpm",
			&imgsiz, &imgsiz);
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
	d->text[4].addr = mlx_get_data_addr(d->text[4].img,
			&d->text[4].bits_per_pixel,
			&d->text[4].line_length, &d->text[4].endian);
	d->text[5].addr = mlx_get_data_addr(d->text[5].img,
			&d->text[5].bits_per_pixel,
			&d->text[5].line_length, &d->text[5].endian);
	d->text[6].addr = mlx_get_data_addr(d->text[6].img,
			&d->text[6].bits_per_pixel,
			&d->text[6].line_length, &d->text[6].endian);
	d->text[7].addr = mlx_get_data_addr(d->text[7].img,
			&d->text[7].bits_per_pixel,
			&d->text[7].line_length, &d->text[7].endian);
}

int	mapj_chose(int j, t_data *d)
{
	if (d->pj > 20)
		j = 21;
	if (d->pj > 41)
		j = 42;
	if (d->pj > 62)
		j = 63;
	if (d->pj > 83)
		j = 84;
	if (d->pj > 104)
		j = 105;
	if (d->pj > 125)
		j = 126;
	if (d->pj > 146)
		j = 147;
	if (d->pj > 167)
		j = 168;
	if (d->pj > 188)
		j = 189;
	return (j);
}

int	mapi_chose(int i, t_data *d)
{
	if (d->pi > 8)
		i = 9;
	if (d->pi > 17)
		i = 18;
	if (d->pi > 26)
		i = 27;
	if (d->pi > 35)
		i = 36;
	if (d->pi > 44)
		i = 45;
	if (d->pi > 53)
		i = 54;
	if (d->pi > 62)
		i = 63;
	if (d->pi > 71)
		i = 72;
	if (d->pi > 80)
		i = 81;
	return (i);
}
