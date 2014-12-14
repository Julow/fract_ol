/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 19:50:51 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/13 19:50:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "ft_draw.h"
# include <mlx.h>

# define WIDTH		640
# define HEIGHT		480

# define NI(r,i)	((t_ni){(r), (i)})

# define C(i)		((t_color)(t_uint)(i))

typedef struct	s_ni
{
	double			r;
	double			i;
}				t_ni;

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	t_string		*title;
	t_image			*img;
	t_color			(*color)(struct s_env*, int);
	int				(*fractale)(struct s_env*, int, int);
	t_ni			pos;
	long double		zoom;
	int				max_loop;
}				t_env;

/*
** utils.c
*/
t_string		*ft_stringnews4(char *s1, char *s2, char *s3, char *s4);
void			error(char *str);

/*
** ft_image
*/
t_image			*ft_imagenew(void *mlx, t_pt size);
void			ft_imagekil(void *mlx, t_image *img);

/*
** fractales.c
*/
t_bool			get_fractale(t_env *env, char *name);
void			draw_fractale(t_env *env);

/*
** hooks.c
*/
int				expose_hook(void *param);
int				key_hook(int key, void *param);
int				mouse_hook(int key, int x, int y, void *param);
int				loop_hook(void *param);

#endif
