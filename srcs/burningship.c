/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:50:17 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/14 16:14:54 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_burningship(t_complex c, t_complex z, int ite)
{
	int				i;
	double			ret;

	i = 0;
	while (i < ite)
	{
		if (ft_checkvalue(z) > 100)
		{
			ret = (i + 1 - log(log(ft_checkvalue(z))) / log(2)) / ite;
			return (ret);
		}
		z = ft_cadd(ft_csqr(ft_cabs(z)), c);
		i++;
	}
	return (-1);
}
