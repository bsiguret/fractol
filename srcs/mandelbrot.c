/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:09:14 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/10 16:04:47 by bsiguret         ###   ########.fr       */
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

void	mandelbrot_init(t_fractale *f)
{
	f->minx = -2.0f;
	f->maxx = 1.0f;
	f->miny = -1.0f;
	f->maxy = 1.0f;
}