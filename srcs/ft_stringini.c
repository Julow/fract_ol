/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 11:12:56 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/12 11:12:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_stringini(t_string *str)
{
	str->content = MAL(char, 16);
	str->content[0] = '\0';
	str->length = 0;
	str->alloc_length = 16;
}
