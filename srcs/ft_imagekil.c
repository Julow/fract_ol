/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imagekil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 19:42:50 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/11 19:42:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include <mlx.h>

void			ft_imagekil(void *mlx, t_image *img)
{
	mlx_destroy_image(mlx, img->img);
	free(img);
}
