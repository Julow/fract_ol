/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spiral.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 13:58:00 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/23 14:02:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static void		spiral_trail(t_env *env, t_lpt pt)
{
	const double	u = 1 * 200 / env->zoom;
	int				i;
	double			t;
	t_lpt			last;

	i = (env->max_loop + env->offset_loop) * 500;
	last = pt;
	while (--i > 0)
	{
		t = 0.4 - (6 / (pt.x * pt.x + pt.y * pt.y + 1));
		pt = LPT(1 + u * (pt.x * cos(t) - pt.y * sin(t)),
			u * (pt.x * sin(t) + pt.y * cos(t)));
		ft_drawline(env->img, PT(pt.x - env->offset.x, pt.y - env->offset.y),
			PT(last.x - env->offset.x, last.y - env->offset.y), env->color(env, i));
		last = pt;
	}
}

void			spiral(t_env *env)
{
	int				p;
	t_lpt			offset;

	offset = LPT(WIDTH + env->offset.x - env->mousepos.x,
		HEIGHT + env->offset.y - env->mousepos.y);
	ft_imageclr(env->img);
	p = 100;
	while ((p -= 3) > 0)
		spiral_trail(env, LPT(offset.x + p, offset.y + p));
}
