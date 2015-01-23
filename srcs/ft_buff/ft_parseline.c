/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 20:13:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/13 15:33:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string		ft_parseline(t_buff *buff)
{
	char			c;
	t_string		line;

	ft_stringini(&line);
	c = ft_buffget(buff);
	while (c != '\0')
	{
		if ((c = ft_buffget(buff)) == '\n' || c == '\0')
			break ;
		ft_stringaddc(&line, c);
		buff->i++;
	}
	if (c == '\n')
		buff->i++;
	return (line);
}
