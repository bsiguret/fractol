/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smoothcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:39:39 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/12 14:28:39 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				getstep(unsigned char val1, unsigned char val2, double ret)
{
	double	color;

	color = (val2 - val1) * ret;
	color = roundl(color);
	return (color);
}

int				ft_get_firstcolor(double retval, t_data *data)
{
	int			color;
	t_color		*ptr;

	ptr = data->color;
	color = ptr->value;
	while (ptr->next)
	{
		ptr = ptr->next;
		if (ptr->index <= retval)
			color = ptr->value;
	}
	return (color);
}

int				ft_get_lastcolor(double retval, t_data *data)
{
	int			color;
	t_color		*ptr;

	ptr = data->color;
	color = ptr->value;
	while (ptr->next)
	{
		ptr = ptr->next;
		if (ptr->index >= retval)
			return (ptr->value);
	}
	return (color);
}

double			ft_get_retval(double retval, t_data *data)
{
	double		inf;
	double		sup;
	t_color		*ptr;

	ptr = data->color;
	while (ptr->next->index < retval)
		ptr = ptr->next;
	inf = ptr->index;
	sup = ptr->next->index;
	return ((double)(retval - inf) / (sup - inf));
}

int				rgb_grad(double retval, t_data *data, t_fractale *fract)
{
	int			col1;
	int			col2;
	int			col3;
	double		ret;

	(void)fract;
	if (retval < 0)
		retval = fabsl(retval);
	if (retval > 1)
		retval = 1;
	col1 = ft_get_firstcolor(retval, data);
	col2 = ft_get_lastcolor(retval, data);
	col3 = col1;
	ret = ft_get_retval(retval, data);
	col3 += (getstep(int_to_rgb(col1).r, int_to_rgb(col2).r, ret)
			* 0x10000);
	col3 += (getstep(int_to_rgb(col1).g, int_to_rgb(col2).g, ret)
			* 0x100);
	col3 += (getstep(int_to_rgb(col1).b, int_to_rgb(col2).b, ret));
	return (col3);
}
