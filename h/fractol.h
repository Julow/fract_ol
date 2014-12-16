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

/*
** fractales from http://www.lifesmith.com/formulas.html
*/

# include "libft.h"
# include <mlx.h>
# include <math.h>

# define WIDTH		600
# define HEIGHT		480

# define MAX_I		16

# define NI(r,i)	((t_ni){(r), (i)})

# define C(i)		((t_color)(t_uint)(i))

typedef struct	s_ni
{
	long double		r;
	long double		i;
}				t_ni;

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	t_string		*title;
	t_image			*img;
	t_color			(*color)(struct s_env*, int);
	int				color_i;
	int				(*fractale)(struct s_env*, int, int);
	long double		zoom;
	int				max_loop;
	t_pt			offset;
	t_pt			mousepos;
	t_bool			mousedown;
	t_bool			rerender;
}				t_env;

/*
** main.c
*/
void			env_exit(t_env *env);

/*
** utils.c
*/
t_string		*ft_stringnews4(char *s1, char *s2, char *s3, char *s4);
t_ni			ft_ni_mult(t_ni a, t_ni b);
t_ni			ft_ni_plus(t_ni a, t_ni b);
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
** colors.c
*/
void			switch_color(t_env *env);

/*
** hooks.c
** mouse_hooks.c
*/
int				expose_hook(void *param);
int				key_hook(int key, void *param);
int				loop_hook(void *param);
int				mouseup_hook(int key, int x, int y, void *param);
int				mousedown_hook(int key, int x, int y, void *param);
int				mousemove_hook(int x, int y, void *param);

#endif
