/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseendl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 15:27:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/13 15:33:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_parseendl(t_buff *buff)
{
	char			c;

	c = '\0';
	while ((c = ft_buffget(buff)) != '\n' && c != '\0')
		buff->i++;
	if (c == '\n')
		buff->i++;
}
