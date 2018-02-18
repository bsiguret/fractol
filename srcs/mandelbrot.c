/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:09:14 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/16 16:58:17 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_mandelbrot(t_complex c, t_complex z, int ite)
{
	int				i;
	double			ret;

	i = 0;
	while (i < ite)
	{
		z = ft_cadd(ft_csqr(z), c);
		if (ft_checkvalue(z) > 100)
		{
			ret = (i + 1 - log(log(ft_checkvalue(z))) / log(2)) / ite;
			return (ret);
		}
		i++;
	}
	return (-1);
}

double	ft_checkvalue(t_complex comp)
{
	return (comp.r * comp.r + comp.i * comp.i);
}
