/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:11:43 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/12 16:35:55 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double			ft_julia(t_complex c, t_complex z, int ite)
{
	int			i;
	double		retval;

	i = 0;
	while (i < ite)
	{
		c = ft_cadd(ft_csqr(c), z);
		if (ft_checkvalue(c) > 512)
		{
			retval = (i - log(log(ft_cmod(c)) / log(100)) / log(2)) / ite;
			return (retval);
		}
		i++;
	}
	return (-1);
}