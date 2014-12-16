/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 01:02:10 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/14 01:02:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		mandelbrot(t_env *env, int x, int y)
{
	t_ni			c;
	t_ni			z;
	long double		tmp;
	int				i;

	c = NI(x / env->zoom, y / env->zoom);
	z = NI(0, 0);
	i = 0;
	while ((z.r * z.r + (z.i * z.i)) < MAX_I && i < env->max_loop)
	{
		tmp = z.r;
		z.r = z.r * z.r - (z.i * z.i) + c.r;
		z.i = 2 * z.i * tmp + c.i;
		i++;
	}
	return (i);
}

static int		julia(t_env *env, int x, int y)
{
	t_ni			c;
	t_ni			z;
	long double		tmp;
	int				i;

	c = NI((env->offset.x - env->mousepos.x) / env->zoom,
		(env->offset.y - env->mousepos.y) / env->zoom);
	z = NI(x / env->zoom, y / env->zoom);
	i = 0;
	while ((z.r * z.r + (z.i * z.i)) < MAX_I && i < env->max_loop)
	{
		tmp = z.r;
		z.r = z.r * z.r - (z.i * z.i) + c.r;
		z.i = 2 * z.i * tmp + c.i;
		i++;
	}
	return (i);
}

static int		fractale2(t_env *env, int x, int y)
{
	t_ni			c;
	t_ni			z;
	int				i;

	c = NI(x / env->zoom, y / env->zoom);
	z = NI(0, 0);
	i = 0;
	while ((z.r * z.r + (z.i * z.i)) < MAX_I && i < env->max_loop)
	{
		z = (ft_ni_mult(z, z));
		z.r += c.r;
		z.i += c.i;
		i++;
	}
	return (i);
}

t_bool			get_fractale(t_env *env, char *name)
{
	if (name[0] == '\0' || ft_match(name, "ma*") || ft_strequ(name, "0"))
		env->fractale = &mandelbrot;
	else if (ft_match(name, "ju*") || ft_strequ(name, "1"))
		env->fractale = &julia;
	else if (ft_strequ(name, "2"))
		env->fractale = &fractale2;
	else
		return (FALSE);
	return (TRUE);
}

void			draw_fractale(t_env *env)
{
	t_pt			i;
	int				tmp;
	t_pt			ffset;

	ffset = PT(WIDTH + env->offset.x, HEIGHT + env->offset.y);
	i = env->offset;
	while (++i.y < ffset.y)
	{
		i.x = env->offset.x;
		while (++i.x < ffset.x)
		{
			tmp = env->fractale(env, i.x, i.y);
			ft_drawxy(env->img, i.x - env->offset.x, i.y - env->offset.y,
				env->color(env, tmp));
		}
	}
}
