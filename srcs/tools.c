/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:45:41 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/10 01:59:55 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*ft_malloc(int size)
{
	void	*ptr;

	if (!(ptr = malloc(size)))
		ft_error("Malloc failed !\n");
	return (ptr);
}

void		ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(-1);
}

float		ft_max(float a, float b, float c)
{
	if (a >= b && a >= c)
		return (a);
	if (b >= a && b >= c)
		return (b);
	return (c);
}

float		ft_min(float a, float b, float c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}