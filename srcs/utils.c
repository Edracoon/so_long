/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:06:06 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/12 16:22:34 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

void	my_mlx_pixel_put(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->line_length + x * (d->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_color_textu(t_data *d, int x, int y, int nb)
{
	char	*dst;

	dst = d->text[nb].addr + (y * d->text[nb].line_length + \
		x * (d->text[nb].bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
