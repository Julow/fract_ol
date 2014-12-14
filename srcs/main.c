/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 19:50:26 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/13 19:50:27 by jaguillo         ###   ########.fr       */
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
	env->pos = NI(env->zoom / WIDTH, env->zoom / HEIGHT);
	env->max_loop = 30;
	mlx_expose_hook(env->win, &expose_hook, env);
	mlx_key_hook(env->win, &key_hook, env);
	mlx_mouse_hook(env->win, &mouse_hook, env);
	mlx_loop_hook(env->win, &loop_hook, env);
}

static t_bool	load_env(void *mlx, char *arg)
{
	t_env			*env;

	env = MAL1(t_env);
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
	int				i;
	t_bool			start;

	if ((mlx = mlx_init()) == NULL)
		error("Error: mlx_init fail.\n");
	i = 0;
	start = FALSE;
	while (++i < argc)
		start = start | load_env(mlx, argv[i]);
	ft_putstr("Fract'ol\n'Esc' to quit\n'c' to change colors\n");
	if ((argc <= 1 && load_env(mlx, "mandelbrot")) || start)
		mlx_loop(mlx);
	return (0);
}
