/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandeldrop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:42:14 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/15 16:42:50 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_mandeldrop(t_complex c, t_complex z, int ite)
{
	int			i;
	double		ret;

	i = 0;
	c.r += c.i;
	c.i = c.r - c.i;
	c.r = c.r -= c.i;
	c = ft_cinv(c);
	while (i < ite)
	{
		z = ft_cadd(ft_csqr(z), c);
		if (ft_checkvalue(z) > 100)
		{
			ret = (i + 1 - log(log(ft_checkvalue(z))) / log(2.0)) / ite;
			return (ret);
		}
		i++;
	}
	return (-1);
}
