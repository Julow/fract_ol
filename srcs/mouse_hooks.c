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

int				mousedown_hook(int key, int x, int y, void *param)
{
	t_env			*env;

	env = (t_env*)param;
	if (key == 1)
		env->mousedown = TRUE;
	else if (key == 4 || (key == 5 && env->zoom > 100))
	{
		env->zoom *= (key == 4) ? 1.005 : 0.995;
		env->offset.x *= (key == 4) ? 1.005 : 0.995;
		env->offset.y *= (key == 4) ? 1.005 : 0.995;
		env->max_loop = MAX((int)(log(env->zoom) * 5), 30);
		env->rerender = TRUE;
	}
	(void)x;
	(void)y;
	return (0);
}

int				mousemove_hook(int x, int y, void *param)
{
	t_env			*env;

	env = (t_env*)param;
	if (env->mousedown)
	{
		env->offset.x += env->mousepos.x - x;
		env->offset.y += env->mousepos.y - y;
	}
	env->mousepos.x = x;
	env->mousepos.y = y;
	env->rerender = TRUE;
	return (0);
}
