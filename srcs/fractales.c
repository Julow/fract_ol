/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 01:02:10 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/23 13:59:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_bool			get_fractale(t_env *env, char *name)
{
	if (ft_match(name, "ma*") || ft_strequ(name, "0"))
		env->fract = (t_fract){"Mandelbrot", &mandelbrot, FALSE,
			PT(420, 230)};
	else if (ft_match(name, "ju*") || ft_strequ(name, "1"))
		env->fract = (t_fract){"Julia", &julia, TRUE,
			PT(WIDTH / 2, HEIGHT / 2)};
	else if (ft_match(name, "ik*") || ft_strequ(name, "2"))
		env->fract = (t_fract){"Ikeda map", &ikeda, TRUE,
			PT(WIDTH / 2, HEIGHT / 2)};
	else if (ft_match(name, "sp*") || ft_strequ(name, "3"))
		env->fract = (t_fract){"Spiral", &spiral, TRUE,
			PT(WIDTH / 2, HEIGHT / 2)};
	else
		return (FALSE);
	return (TRUE);
}
