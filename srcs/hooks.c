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

int				expose_hook(void *param)
{
	t_env			*env;
	t_string		*tmp;

	env = (t_env*)param;
	draw_fractale(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	tmp = ft_stringnew();
	ft_stringadd(tmp, "max_loop: ");
	ft_stringaddi(tmp, env->max_loop);
	mlx_string_put(env->mlx, env->win, 10, 20, 0xFFFFFF, tmp->content);
	ft_stringclr(tmp);
	ft_stringadd(tmp, "pos: ");
	ft_stringaddd(tmp, env->pos.r, 6);
	ft_stringadd(tmp, " + ");
	ft_stringaddd(tmp, env->pos.i, 6);
	ft_stringadd(tmp, "i");
	mlx_string_put(env->mlx, env->win, 10, 40, 0xFFFFFF, tmp->content);
	ft_stringclr(tmp);
	ft_stringadd(tmp, "zoom: ");
	ft_stringaddd(tmp, env->zoom, 6);
	mlx_string_put(env->mlx, env->win, 10, 60, 0xFFFFFF, tmp->content);
	ft_stringkil(tmp);
	return (0);
}

int				key_hook(int key, void *param)
{
	t_env			*env;

	env = (t_env*)param;
	if (key == 65307)
	{
		mlx_destroy_window(env->mlx, env->win);
		ft_stringkil(env->title);
		ft_imagekil(env->mlx, env->img);
		free(env);
		exit(1);
	}
	else if (key == 65362)
		env->pos.i += 60 / env->zoom;
	else if (key == 65364)
		env->pos.i -= 60 / env->zoom;
	else if (key == 65361)
		env->pos.r += 60 / env->zoom;
	else if (key == 65363)
		env->pos.r -= 60 / env->zoom;
	else
		return (0);
	expose_hook(param);
	return (0);
}

/*
** 4: + zoom
** 5: - zoom
*/
int				mouse_hook(int key, int x, int y, void *param)
{
	t_env			*env;

	env = (t_env*)param;
	if (key == 4)
	{
		env->zoom += env->zoom / 5;
		env->pos.r -= 60 / env->zoom;
		env->pos.i -= 60 / env->zoom;
		env->max_loop += 5;
		expose_hook(param);
	}
	else if (key == 5 && env->max_loop > 5)
	{
		env->pos.r += 60 / env->zoom;
		env->pos.i += 60 / env->zoom;
		env->zoom -= env->zoom / 5;
		env->max_loop -= 5;
		expose_hook(param);
	}
	(void)x;
	(void)y;
	return (0);
}

int				loop_hook(void *param)
{
	(void)param;
	return (0);
}
