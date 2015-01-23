/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 19:58:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/23 14:14:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include <mlx.h>
#include <math.h>

static void		print_debug(t_env *env)
{
	t_string		tmp;

	ft_stringini(&tmp);
	ft_stringadd(&tmp, "max_loop: ");
	ft_stringaddi(&tmp, env->max_loop);
	ft_stringadd(&tmp, " + ");
	ft_stringaddi(&tmp, env->offset_loop);
	mlx_string_put(env->mlx, env->win, 10, 20, 0xFF0000, tmp.content);
	ft_stringclr(&tmp);
	ft_stringadd(&tmp, "pos: ");
	ft_stringaddil(&tmp, env->offset.x);
	ft_stringadd(&tmp, ", ");
	ft_stringaddil(&tmp, env->offset.y);
	mlx_string_put(env->mlx, env->win, 10, 40, 0xFF0000, tmp.content);
	ft_stringclr(&tmp);
	ft_stringadd(&tmp, "zoom: ");
	ft_stringaddd(&tmp, env->zoom, 6);
	if (isnan(env->zoom))
		ft_stringadd(&tmp, " (NaN)");
	mlx_string_put(env->mlx, env->win, 10, 60, 0xFF0000, tmp.content);
	ft_stringclr(&tmp);
	ft_stringadd(&tmp, "color: ");
	ft_stringaddi(&tmp, env->color_i);
	mlx_string_put(env->mlx, env->win, 10, 80, 0xFF0000, tmp.content);
	free(tmp.content);
}

static void		reset_pos(t_env *env)
{
	env->zoom = 200;
	env->max_loop = DEF_LOOP * 5;
	env->offset = LPT(-env->fract.startpos.x, -env->fract.startpos.y);
	env->mousepos = LPT(0, 0);
	env->mousedown = false;
	env->rerender = true;
}

int				expose_hook(void *param)
{
	t_env			*env;

	env = (t_env*)param;
	env->fract.draw(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	return (0);
}

int				key_hook(int key, void *param)
{
	if (key == 65307)
		env_exit((t_env*)param);
	else if (key == 65362)
		((t_env*)param)->offset.y -= 50;
	else if (key == 65364)
		((t_env*)param)->offset.y += 50;
	else if (key == 65361)
		((t_env*)param)->offset.x -= 50;
	else if (key == 65363)
		((t_env*)param)->offset.x += 50;
	else if (key == 65451)
		((t_env*)param)->offset_loop += 1;
	else if (key == 65453)
		((t_env*)param)->offset_loop -= 1;
	else if (key == 'p')
		return (print_debug((t_env*)param), 0);
	else if (key == 'c')
		switch_color((t_env*)param);
	else if (key == 'r')
		reset_pos((t_env*)param);
	else
		return (0);
	return (((t_env*)param)->rerender = true, 0);
}

int				loop_hook(void *param)
{
	t_env			*env;

	env = (t_env*)param;
	if (env->rerender)
	{
		expose_hook(param);
		env->rerender = false;
	}
	return (0);
}
