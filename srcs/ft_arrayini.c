/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayini.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 11:13:05 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/12 11:13:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_arrayini(t_array *array)
{
	array->data = MAL(void*, 16);
	array->data[0] = NULL;
	array->length = 0;
	array->alloc_length = 16;
}
