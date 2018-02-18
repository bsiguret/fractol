/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 19:37:40 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/16 16:57:26 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		ft_comp(double x, double y)
{
	t_complex	comp;

	comp.r = x;
	comp.i = y;
	return (comp);
}

t_complex		ft_cinv(t_complex c)
{
	double		div;

	div = c.r * c.r + c.i * c.i;
	c.r = c.r / div;
	c.i = -c.i / div;
	return (c);
}

double			ft_cmod(t_complex comp)
{
	return (sqrt(comp.r * comp.r + comp.i * comp.i));
}

double			ft_cangle(t_complex c)
{
	double		angle;

	angle = atan(c.i / c.r);
	return (angle);
}

t_complex		ft_conj(t_complex c)
{
	c.i = -c.i;
	return (c);
}
