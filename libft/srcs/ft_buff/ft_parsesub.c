/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsesub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 17:32:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/13 15:32:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string		ft_parsesub(t_buff *buff, const char *parse)
{
	char			c;
	t_string		sub;

	ft_stringini(&sub);
	c = ft_buffget(buff);
	while (c != '\0')
	{
		if (ft_strchr(parse, (c = ft_buffget(buff))) == NULL)
			break ;
		ft_stringaddc(&sub, c);
		buff->i++;
	}
	return (sub);
}
