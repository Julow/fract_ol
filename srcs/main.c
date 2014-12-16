/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 19:50:26 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/16 13:26:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

static void		env_init(t_env *env, void *mlx, char *name)
{
	env->mlx = mlx;
	env->title = ft_stringnews4("Fract'ol :: ", name, " ::", NULL);
	if ((env->win = mlx_new_window(mlx, WIDTH, HEIGHT,
		env->title->content)) == NULL)
		error("Error: mlx_new_window fail.\n");
	env->img = ft_imagenew(mlx, PT(WIDTH, HEIGHT));
	env->color_i = 0;
	switch_color(env);
	env->zoom = 200;
	env->max_loop = 30;
	env->offset = PT(-420, -240);
	env->mousepos = PT(0, 0);
	env->mousedown = FALSE;
	env->rerender = FALSE;
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
		ft_putstr_fd("Error: Bad fractale: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("\n", 2);
		free(env);
		return (FALSE);
	}
	env_init(env, mlx, arg);
	return (TRUE);
}

void			env_exit(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	ft_stringkil(env->title);
	ft_imagekil(env->mlx, env->img);
	free(env);
	exit(1);
}

int				main(int argc, char **argv)
{
	void			*mlx;

	if ((mlx = mlx_init()) == NULL)
		error("Error: mlx_init fail.\n");
	ft_putstr("Fract'ol\n");
	ft_putstr("Supported fractales: Mandelbrot(0), Julia(1), 2\n");
	ft_putstr("==============================\n");
	if (argc > 1 && !load_env(mlx, argv[1]))
		error("Error: Fractale not supported.\n");
	else if (!load_env(mlx, "mandelbrot"))
		error("Error: Please specify a fractale.\n");
	else
		ft_putstr("Default fractale: Mandelbrot\n");
	ft_putstr("'Esc' to quit\n'c' to change colors\n");
	mlx_loop(mlx);
	return (0);
}
