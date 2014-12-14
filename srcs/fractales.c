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
	(void)env;
	(void)x;
	(void)y;
	return (0);
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
	(void)env;
}
