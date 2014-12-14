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

	env = (t_env*)param;
	draw_fractale(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
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
	return (0);
}

int				mouse_hook(int key, int x, int y, void *param)
{
	ft_putstr("Button ");
	ft_putnbr(key);
	ft_putchar('\n');
	(void)x;
	(void)y;
	(void)param;
	return (0);
}

int				loop_hook(void *param)
{
	(void)param;
	return (0);
}
