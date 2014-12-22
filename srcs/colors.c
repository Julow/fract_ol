/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 12:46:17 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/14 12:46:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_color	color0(t_env *env, int loop)
{
	t_color			c;

	if (loop == env->max_loop)
		return (C(0xFF000000));
	c.b.r = 250;
	c.b.g = 250;
	c.b.b = 250;
	c.b.a = loop % 64;
	return (c);
}

static t_color	color1(t_env *env, int loop)
{
	t_color			c;

	if (loop == env->max_loop)
		return (C(0xFF000000));
	c.b.r = 50 * loop;
	c.b.g = 150 * loop;
	c.b.b = 250 * loop;
	c.b.a = 0xFF;
	return (c);
}

static t_color	color2(t_env *env, int loop)
{
	t_color			c;

	if (loop == env->max_loop)
		return (C(0xFF000000));
	c.b.r = 20 * loop;
	c.b.g = 15 * loop;
	c.b.b = 10 * loop;
	c.b.a = 0xFF;
	return (c);
}

static t_color	color3(t_env *env, int loop)
{
	t_color			c;

	if (loop == env->max_loop)
		return (C(0xFF000000));
	c.i = loop * 255 / env->max_loop;
	c.b.a = 0xFF;
	return (c);
}

void			switch_color(t_env *env)
{
	env->color_i = (env->color_i + 1) % 4;
	if (env->color_i == 0)
		env->color = &color0;
	else if (env->color_i == 1)
		env->color = &color1;
	else if (env->color_i == 2)
		env->color = &color2;
	else if (env->color_i == 3)
		env->color = &color3;
}
