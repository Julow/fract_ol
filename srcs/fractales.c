/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 01:02:10 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/16 13:44:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_bool			get_fractale(t_env *env, char *name)
{
	if (name[0] == '\0' || ft_match(name, "ma*") || ft_strequ(name, "0"))
		env->fract = (t_fract){"Mandelbrot", &mandelbrot, 0,
			PT(420, 230)};
	else if (ft_match(name, "ju*") || ft_strequ(name, "1"))
		env->fract = (t_fract){"Julia", &julia, TRUE,
			PT(WIDTH / 2, HEIGHT / 2)};
	else
		return (FALSE);
	return (TRUE);
}
