/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glynn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:19:04 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/14 17:25:39 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_glynn(t_complex c, t_complex z, int ite)
{
	int			i;
	double		ret;

	z.r = -0.2;
	i = 0;
	c.r += c.i;
	c.i = c.r - c.i;
	c.r = c.r -= c.i;
	while (i < ite)
	{
		c = ft_cadd(ft_cpow(c, 1.5), z);
		if (ft_checkvalue(c) > 100)
		{
			ret = (i - log(log(ft_cmod(c)) / log(100)) / log(2)) / ite;
			return (ret);
		}
		i++;
	}
	return (-1);
}