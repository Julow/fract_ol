/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 19:58:52 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/13 19:58:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

static void		write_debug(t_env *env)
{
	t_string		tmp;

	ft_stringini(&tmp);
	ft_stringadd(&tmp, "max_loop: ");
	ft_stringaddi(&tmp, env->max_loop);
	mlx_string_put(env->mlx, env->win, 10, 20, 0xFFFFFF, tmp.content);
	ft_stringclr(&tmp);
	ft_stringadd(&tmp, "pos: ");
	ft_stringaddi(&tmp, env->offset.x);
	ft_stringadd(&tmp, ", ");
	ft_stringaddi(&tmp, env->offset.y);
	mlx_string_put(env->mlx, env->win, 10, 40, 0xFFFFFF, tmp.content);
	ft_stringclr(&tmp);
	ft_stringadd(&tmp, "zoom: ");
	ft_stringaddd(&tmp, env->zoom, 6);
	mlx_string_put(env->mlx, env->win, 10, 60, 0xFFFFFF, tmp.content);
	ft_stringclr(&tmp);
	ft_stringadd(&tmp, "color: ");
	ft_stringaddi(&tmp, env->color_i);
	mlx_string_put(env->mlx, env->win, 10, 80, 0xFFFFFF, tmp.content);
	free(tmp.content);
}

int				expose_hook(void *param)
{
	t_env			*env;

	env = (t_env*)param;
	draw_fractale(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	write_debug(env);
	return (0);
}

int				key_hook(int key, void *param)
{
	t_env			*env;

	env = (t_env*)param;
	if (key == 65307)
		env_exit(env);
	else if (key == 65362)
		env->offset.y -= 50;
	else if (key == 65364)
		env->offset.y += 50;
	else if (key == 65361)
		env->offset.x -= 50;
	else if (key == 65363)
		env->offset.x += 50;
	else if (key == 65451)
		env->max_loop += 1;
	else if (key == 65453)
		env->max_loop -= 1;
	else if (key == 'c')
		switch_color(env);
	else
		return (0);
	env->rerender = TRUE;
	return (0);
}

int				loop_hook(void *param)
{
	t_env			*env;

	env = (t_env*)param;
	if (env->rerender)
	{
		expose_hook(param);
		env->rerender = FALSE;
	}
	return (0);
}
