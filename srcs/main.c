/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 19:50:26 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/23 14:15:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include <mlx.h>

static void		env_init(t_env *env, void *mlx)
{
	env->mlx = mlx;
	env->title = ft_stringnews4("Fract'ol :: ", env->fract.name, " ::", NULL);
	if ((env->win = mlx_new_window(mlx, WIDTH, HEIGHT,
		env->title->content)) == NULL)
		error("Error: mlx_new_window fail.\n");
	env->img = ft_imagenew(mlx, PT(WIDTH, HEIGHT));
	env->color_i = 0;
	switch_color(env);
	env->zoom = 200;
	env->max_loop = DEF_LOOP * 5;
	env->offset_loop = 0;
	env->offset = LPT(-env->fract.startpos.x, -env->fract.startpos.y);
	env->mousepos = LPT(0, 0);
	env->mousedown = false;
	env->rerender = false;
	mlx_expose_hook(env->win, &expose_hook, env);
	mlx_key_hook(env->win, &key_hook, env);
	mlx_loop_hook(env->mlx, &loop_hook, env);
	mlx_hook(env->win, 4, 1 << 2, &mousedown_hook, env);
	mlx_hook(env->win, 5, 1 << 3, &mouseup_hook, env);
	mlx_hook(env->win, 6, 1 << 6, &mousemove_hook, env);
}

static t_bool	load_env(void *mlx, char *arg)
{
	t_env			*env;

	env = MAL1(t_env);
	ft_strlower(arg);
	if (!get_fractale(env, arg))
	{
		ft_putstr_fd("Error: Fractale not supported: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("\n", 2);
		free(env);
		return (false);
	}
	env_init(env, mlx);
	return (true);
}

void			env_exit(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	ft_stringkil(env->title);
	ft_imagekil(env->mlx, env->img);
	free(env);
	exit(0);
}

int				main(int argc, char **argv)
{
	void			*mlx;

	if ((mlx = mlx_init()) == NULL)
		error("Error: mlx_init fail.\n");
	ft_putstr("Fract'ol\nSupported fractales: Mandelbrot(0), Julia(1), "
		"Ikeda(2), Spiral(3)\n");
	ft_putstr("==============================\n");
	if (argc > 1 && !load_env(mlx, argv[1]))
		return (1);
	else if (argc <= 1)
		error("Error: Please specify a fractale.\n");
	ft_putstr("'Esc' to quit\n'c' to change colors\n'r' to reset position\n");
	ft_putstr("'p' to print debug\n");
	mlx_loop(mlx);
	return (0);
}
