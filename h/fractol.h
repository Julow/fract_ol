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

# define WIDTH		640
# define HEIGHT		480

# define NI(r,i)	((t_ni){(r), (i)})

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	t_image			*img;
	int				(*color)(struct s_env*, int);
	int				(*fractale)(struct s_env*, int, int);
}				t_env;

typedef struct	s_ni
{
	double			r;
	double			i;
}				t_ni;

/*
** ft_image
*/
t_image			*ft_imagenew(void *mlx, t_pt size);
void			ft_imagekil(void *mlx, t_image *img);

/*
** hooks.c
*/
int				expose_hook(void *param);
int				key_hook(int key, void *param);
int				mouse_hook(int key, int x, int y, void *param);

#endif
