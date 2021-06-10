/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 09:50:44 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/10 11:36:18 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

typedef struct s_mlx
{
	void		*mlx_win;
	void		*mlx;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_mlx;

typedef struct s_data
{
	char		**map;
	int			nbplayer;
	int			win_x;
	int			win_y;
	int			sizeline;
	int			sizecollum;
	int			cubsize;

	double		posx;
	double		posy;
	int			kill_win;
	int			forward;
	int			backward;
	int			leftward;
	int			rightward;
	t_mlx		*mlx;
}	t_data;

void	stockage_map(t_data *d, char *file);
void	parse_ber(char *file, t_data *d);
void	ft_error(char *str);

#endif