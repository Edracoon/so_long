/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 09:50:44 by epfennig          #+#    #+#             */
/*   Updated: 2021/08/28 19:25:33 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

# define CHICKEN	0
# define MUR		2
# define DOOR		3
# define FLOOR		4

typedef struct s_textu
{
	void		*mlx_win;
	void		*mlx;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_textu;

typedef struct s_data
{
	char			**map;
	int				nbplayer;
	int				win_x;
	int				win_y;
	int				sizeline;
	int				sizecollum;
	int				cubsize;
	int				pi;
	int				pj;

	unsigned int	color;

	int				j;
	int				i;

	int				x;
	int				y;

	int				tx;
	int				ty;

	int				maxx;
	int				maxy;
	int				posx;
	int				posy;

	int				kill_win;
	int				forward;
	int				backward;
	int				leftward;
	int				rightward;

	int				xmapindex;
	int				ymapindex;

	int				collec;
	int				nbmoov;

	void			*mlx_win;
	void			*mlx;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;

	int				playdir;

	t_textu			text[8];
}	t_data;

int				mapj_chose(int j, t_data *d);
int				mapi_chose(int i, t_data *d);
void			stockage_map(t_data *d, char *file);
void			parse_ber(char *file, t_data *d);
void			ft_error(char *str, t_data *d);
void			mlx_main(t_data *d);
int				ft_mouvement(t_data *d);
void			my_mlx_pixel_put(t_data *d, int x, int y, int color);
int				ft_destroy_windows(t_data *d);
int				key_pressed(int keycode, t_data *d);
void			ft_rightward(t_data *d);
void			ft_leftward(t_data *d);
void			ft_backward(t_data *d);
void			ft_forward(t_data *d);
void			affiche_perso(t_data *d, int x, int y);
void			affiche_cube(t_data *d, int x, int y, int couleur);
void			affiche_wall(t_data *d, int x, int y);
void			affiche_floor(t_data *d, int x, int y);
void			affiche_collectibles(t_data *d, int x, int y);
void			affiche_door(t_data *d, int x, int y);
unsigned int	get_color_textu(t_data *d, int x, int y, int nb);
void			get_xpm_textures(t_data *d);

#endif