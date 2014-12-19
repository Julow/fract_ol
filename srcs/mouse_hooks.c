/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 14:36:16 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/16 14:36:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int				mouseup_hook(int key, int x, int y, void *param)
{
	t_env			*env;

	env = (t_env*)param;
	if (key == 1)
		env->mousedown = FALSE;
	(void)x;
	(void)y;
	return (0);
}

inline int		get_loops(long double zoom)
{
	int				i;

	i = 0;
	while ((zoom /= 1.33) > 1)
		i++;
	return (i * 2 + DEF_LOOP);
}

int				mousedown_hook(int key, int x, int y, void *param)
{
	t_env			*env;
	t_lpt			pos;
	t_ni			tmp;

	env = (t_env*)param;
	if (key == 1)
		env->mousedown = TRUE;
	else if (key == 4 || (key == 5 && env->zoom > 10))
	{
		pos = LPT(env->offset.x + x, env->offset.y + y);
		tmp = NI(pos.x / env->zoom, pos.y / env->zoom);
		env->zoom *= (key == 4) ? 1.005 : 0.995;
		env->offset.x += (tmp.r - (pos.x / env->zoom)) * env->zoom;
		env->offset.y += (tmp.i - (pos.y / env->zoom)) * env->zoom;
		env->max_loop = get_loops(env->zoom);
		env->rerender = TRUE;
	}
	return (0);
}

int				mousemove_hook(int x, int y, void *param)
{
	t_env			*env;
	t_lpt			pos;

	pos = LPT((t_long)x, (t_long)y);
	env = (t_env*)param;
	if (env->mousedown)
	{
		env->offset.x += env->mousepos.x - pos.x;
		env->offset.y += env->mousepos.y - pos.y;
		env->rerender = TRUE;
	}
	else if (env->fract.mouserender)
		env->rerender = TRUE;
	env->mousepos.x = pos.x;
	env->mousepos.y = pos.y;
	return (0);
}
