/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:39:26 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/10 16:07:18 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			hsv_to_rgb(t_hsv hsv)
{
	double	c;
	double	h;
	double	x;
	double	m;

	c = (double)hsv.v / 100 * ((double)hsv.s / 100);
	h = (double)hsv.h / 60;
	x = c * (1 - fabs(h - ((int)h / 2 * 2) - 1));
	m = (double)hsv.v / 100 - c;
	if (h >= 0 && h < 1)
		return (get_rgb(round(c + m * 255), round(x + m * 255), round(m * 255)));
	if (h >= 1 && h < 2)
		return (get_rgb(round(x + m * 255), round(c + m * 255), round(m * 255)));
	if (h >= 2 && h < 3)
		return (get_rgb(round(m * 255), round(c + m * 255), round(x + m * 255)));
	if (h >= 3 && h < 4)
		return (get_rgb(round(m * 255), round(x + m * 255), round(c + m * 255)));
	if (h >= 4 && h < 5)
		return (get_rgb(round(x + m * 255), round(m * 255), round(c + m * 255)));
	return (get_rgb(round(c + m * 255), round(m * 255), round(x + m * 255)));
}

t_hsv		rgb_to_hsv(int color)
{
	t_hsv	hsv;
	double	max;
	double	min;

	hsv.h = (double)int_to_rgb(color).r / 255 * 100;
	hsv.s = (double)int_to_rgb(color).g / 255 * 100;
	hsv.v = (double)int_to_rgb(color).b / 255 * 100;
	max = ft_max(hsv.h, hsv.s, hsv.v);
	min = ft_min(hsv.h, hsv.s, hsv.v);
	if (max == min)
		hsv.h = 0;
	else if (max == hsv.h)
		hsv.h = (int)round((60 * ((double)(hsv.s - hsv.v) / (max - min)) + 360))
			% 360;
	else if (max == hsv.s)
		hsv.h = round(60 * ((double)(hsv.v - hsv.h) / (max - min)) + 120);
	else
		hsv.h = round(60 * ((double)(hsv.h - hsv.s) / (max - min)) + 240);
	hsv.s = round((max == 0) ? 0 : (1 - (double)(min / max)) * 100);
	hsv.v = round(max);
	return (hsv);
}

void		modifyhue(int y, t_data *data)
{
	y = (y < 100) ? 100 : y;
	y = (y > 279) ? 279 : y;
	data->editedcolor->hsv.h = ((double)(279 - y) / 179 * 359);
	data->editedcolor->value = hsv_to_rgb(data->editedcolor->hsv);
	data->editedcolor->rgb = int_to_rgb(data->editedcolor->value);
	data->colorchanged = 1;
}

void		modifysv(int x, int y, t_data *data)
{
	x = (x < 96) ? 96 : x;
	x = (x > 275) ? 275 : x;
	y = (y < 100) ? 100 : y;
	y = (y > 279) ? 279 : y;
	data->editedcolor->hsv.s = ((double)(x - 96) / 179 * 100);
	data->editedcolor->hsv.v = ((double)(279 - y) / 179 * 100);
	data->editedcolor->value = hsv_to_rgb(data->editedcolor->hsv);
	data->editedcolor->rgb = int_to_rgb(data->editedcolor->value);
	data->colorchanged = 1;
}

void			ptrswap(t_fractale **ptr1, t_fractale **ptr2, t_data *data)
{
	t_fractale	*tmp;

	(void)data;
	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}