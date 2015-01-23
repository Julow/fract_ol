/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 01:02:10 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/23 14:14:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_bool			get_fractale(t_env *env, char *name)
{
	if (ft_match(name, "ma*") || ft_strequ(name, "0"))
		env->fract = FRACT("Mandelbrot", &mandelbrot, false, PT(420, 230));
	else if (ft_match(name, "ju*") || ft_strequ(name, "1"))
		env->fract = FRACT("Julia", &julia, true, MIDDLE);
	else if (ft_match(name, "ik*") || ft_strequ(name, "2"))
		env->fract = FRACT("Ikeda map", &ikeda, true, MIDDLE);
	else if (ft_match(name, "sp*") || ft_strequ(name, "3"))
		env->fract = FRACT("Spiral", &spiral, true, MIDDLE);
	else
		return (false);
	return (true);
}
