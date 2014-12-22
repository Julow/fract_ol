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

static int		mandelbrot(t_env *env, t_long x, t_long y)
{
	t_ni			c;
	t_ni			z;
	t_ni			sq;
	int				i;

	c = NI(x / env->zoom, y / env->zoom);
	z = NI(0, 0);
	sq = NI(0, 0);
	i = env->max_loop;
	while ((sq.r + sq.i) < MAX_I && --i > 0)
	{
		sq.r = z.r * z.r;
		sq.i = z.i * z.i;
		z.i = 2 * z.i * z.r + c.i;
		z.r = sq.r - sq.i + c.r;
	}
	return (env->max_loop - i);
}

static int		julia(t_env *env, t_long x, t_long y)
{
	t_ni			c;
	t_ni			z;
	t_ni			sq;
	int				i;

	c = NI((env->offset.x - (env->mousepos.x - WIDTH)) / env->zoom,
		(env->offset.y - (env->mousepos.y - HEIGHT)) / env->zoom);
	z = NI(x / env->zoom, y / env->zoom);
	sq = NI(z.r * z.r, z.i * z.i);
	i = env->max_loop;
	while ((sq.r + sq.i) < MAX_I && --i > 0)
	{
		sq.r = z.r * z.r;
		sq.i = z.i * z.i;
		z.i = 2 * z.i * z.r + c.i;
		z.r = sq.r - sq.i + c.r;
	}
	return (env->max_loop - i);
}

static int		fractale2(t_env *env, t_long x, t_long y)
{
	t_ni			c;
	t_ni			z;
	int				i;

	c = NI(x / env->zoom, y / env->zoom);
	z = NI(0, 0);
	i = 0;
	while ((z.r * z.r + (z.i * z.i)) < MAX_I && i < env->max_loop)
	{
		z = ft_ni_mult(ft_ni_mult(ft_ni_mult(ft_ni_mult(z, z), z), z), z);
		z.r += c.r;
		z.i += c.i;
		i++;
	}
	return (i);
}

t_bool			get_fractale(t_env *env, char *name)
{
	if (name[0] == '\0' || ft_match(name, "ma*") || ft_strequ(name, "0"))
		env->fract = (t_fract){"Mandelbrot", &mandelbrot, 0, PT(420, 230)};
	else if (ft_match(name, "ju*") || ft_strequ(name, "1"))
		env->fract = (t_fract){"Julia", &julia, TRUE, MIDDLE};
	else if (ft_strequ(name, "2"))
		env->fract = (t_fract){"f(z) = z^5 + c", &fractale2, 0, MIDDLE};
	else
		return (FALSE);
	return (TRUE);
}

void			draw_fractale(t_env *env)
{
	t_lpt			i;
	int				tmp;
	t_lpt			ffset;

	ffset = LPT(WIDTH + env->offset.x, HEIGHT + env->offset.y);
	i = env->offset;
	while (++i.y < ffset.y)
	{
		i.x = env->offset.x;
		while (++i.x < ffset.x)
		{
			tmp = env->fract.f(env, i.x, i.y);
			ft_drawxy(env->img, i.x - env->offset.x, i.y - env->offset.y,
				env->color(env, tmp));
		}
	}
}
