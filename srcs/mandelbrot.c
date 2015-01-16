/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 13:32:22 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/16 13:55:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		mandelbrot_pt(t_env *env, t_long x, t_long y)
{
	const t_ni		c = NI(x / env->zoom, y / env->zoom);
	t_ni			z;
	t_ni			sq;
	int				i;

	z = NI(0, 0);
	sq = NI(0, 0);
	i = env->max_loop + env->offset_loop;
	while ((sq.r + sq.i) < MAX_I && --i > 0)
	{
		sq.r = z.r * z.r;
		sq.i = z.i * z.i;
		z.i = 2 * z.i * z.r + c.i;
		z.r = sq.r - sq.i + c.r;
	}
	return (env->max_loop + env->offset_loop - i);
}

void			mandelbrot(t_env *env)
{
	t_lpt			i;
	t_lpt			ffset;

	ffset = LPT(WIDTH + env->offset.x, HEIGHT + env->offset.y);
	i = env->offset;
	while (++i.y < ffset.y)
	{
		i.x = env->offset.x;
		while (++i.x < ffset.x)
			ft_drawxy(env->img, i.x - env->offset.x, i.y - env->offset.y,
				env->color(env, mandelbrot_pt(env, i.x, i.y)));
	}
}
