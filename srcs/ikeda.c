/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ikeda.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 12:58:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/23 14:03:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static void		ikeda_trail(t_env *env, t_lpt pt)
{
	const double	u = 1 * 200 / env->zoom;
	int				i;
	double			t;

	i = (env->max_loop + env->offset_loop) * 100;
	while (--i > 0)
	{
		t = 0.4 - (6 / (pt.x * pt.x + pt.y * pt.y + 1));
		pt = LPT(1 + u * (pt.x * cos(t) - pt.y * sin(t)),
			u * (pt.x * sin(t) + pt.y * cos(t)));
		ft_drawxy(env->img, pt.x - env->offset.x, pt.y - env->offset.y,
			env->color(env, i));
	}
}

void			ikeda(t_env *env)
{
	int				p;
	t_lpt			offset;

	offset = LPT(WIDTH + env->offset.x - env->mousepos.x,
		HEIGHT + env->offset.y - env->mousepos.y);
	ft_imageclr(env->img);
	p = 100;
	while (--p > 0)
		ikeda_trail(env, LPT(offset.x + p, offset.y + p));
}
