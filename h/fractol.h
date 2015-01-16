/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 19:50:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/16 13:57:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"

# define WIDTH		590
# define HEIGHT		440

# define DEF_LOOP	30

# define MAX_I		8

# define LPT(x,y)	((t_lpt){(x), (y)})

# define NI(r,i)	((t_ni){(r), (i)})

typedef struct	s_lpt
{
	t_long			x;
	t_long			y;
}				t_lpt;

typedef struct	s_ni
{
	long double		r;
	long double		i;
}				t_ni;

typedef struct	s_fract
{
	char			*name;
	void			(*draw)();
	t_bool			mouserender;
	t_pt			startpos;
}				t_fract;

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	t_string		*title;
	t_image			*img;
	t_color			(*color)(struct s_env*, int);
	int				color_i;
	t_fract			fract;
	long double		zoom;
	int				max_loop;
	int				offset_loop;
	t_lpt			offset;
	t_lpt			mousepos;
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
inline t_ni		ft_ni_mult(t_ni a, t_ni b);
inline t_ni		ft_ni_plus(t_ni a, t_ni b);
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

void			mandelbrot(t_env *env);

void			julia(t_env *env);

/*
** colors.c
** mandelbrot.c
** julia.c
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
