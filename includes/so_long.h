/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 09:50:44 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/10 17:09:17 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

typedef struct s_data
{
	char		**map;
	int			nbplayer;
	int			win_x;
	int			win_y;
	int			sizeline;
	int			sizecollum;
	int			cubsize;

	int			posx;
	int			posy;
	int			kill_win;
	int			forward;
	int			backward;
	int			leftward;
	int			rightward;

	int			collec;

	int			nbmoov;

	void		*mlx_win;
	void		*mlx;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

}	t_data;

void	stockage_map(t_data *d, char *file);
void	parse_ber(char *file, t_data *d);
void	ft_error(char *str, t_data *d);
void	mlx_main(t_data *d);
int		ft_mouvement(t_data *d);
void	my_mlx_pixel_put(t_data *d, int x, int y, int color);
int		ft_destroy_windows(t_data *d);
int		key_pressed(int keycode, t_data *d);
void	ft_rightward(t_data *d);
void	ft_leftward(t_data *d);
void	ft_backward(t_data *d);
void	ft_forward(t_data *d);

#endif