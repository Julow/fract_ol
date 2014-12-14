/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 00:48:05 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/14 00:48:05 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

t_string		*ft_stringnews4(char *s1, char *s2, char *s3, char *s4)
{
	t_string		*str;

	str = ft_stringnew();
	if (s1 != NULL)
		ft_stringadd(str, s1);
	if (s2 != NULL)
		ft_stringadd(str, s2);
	if (s3 != NULL)
		ft_stringadd(str, s3);
	if (s4 != NULL)
		ft_stringadd(str, s4);
	return (str);
}

int				ft_mix(int a, int b, double pos)
{
	if (a > b)
		return (a - ((a - b) * pos));
	return (b - a) * pos + a;
}

void			error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}
