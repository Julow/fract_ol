/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 01:02:10 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/14 01:02:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		mandelbrot(t_env *env, int x, int y)
{
	t_ni			c;
	t_ni			z;
	double			tmp;
	int				i;

	c = NI(x / env->zoom - env->pos.r, y / env->zoom - env->pos.i);
	z = NI(0, 0);
	i = 0;
	while ((z.r * z.r + (z.i * z.i)) < 4 && i < env->max_loop)
	{
		tmp = z.r;
		z.r = z.r * z.r - (z.i * z.i) + c.r;
		z.i = 2 * z.i * tmp + c.i;
		i++;
	}
	return (i);
}

t_bool			get_fractale(t_env *env, char *name)
{
	if (name[0] == '\0' || ft_strequ(name, "mandelbrot"))
		env->fractale = &mandelbrot;
	else
		return (FALSE);
	return (TRUE);
}

void			draw_fractale(t_env *env)
{
	t_pt			i;
	int				tmp;

	i = PT(-1, -1);
	while (++i.y < HEIGHT)
	{
		i.x = -1;
		while (++i.x < WIDTH)
		{
			tmp = env->fractale(env, i.x, i.y);
			ft_drawxy(env->img, i.x, i.y, env->color(env, tmp));
		}
	}
}
