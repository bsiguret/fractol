/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraminit2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:53:57 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/16 17:04:01 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_value			**arrayinit(int xmax, int ymax)
{
	int			i;
	t_value		**array;

	array = (t_value**)ft_malloc(sizeof(t_value*) * ymax);
	i = -1;
	while (++i < ymax)
		array[i] = (t_value*)ft_malloc(sizeof(t_value) * xmax);
	return (array);
}

void			boolinit(t_data *data)
{
	data->clickedr = 0;
	data->clickedg = 0;
	data->clickedb = 0;
	data->colorchanged = 1;
	data->locked = 0;
	data->button[3] = 0;
	data->buttony[3] = 0;
	data->buttonx[3] = 0;
}

void			colorinit(t_data *data, int color, int color2)
{
	data->color = (t_color*)ft_malloc(sizeof(t_color));
	data->color->value = color;
	data->color->index = 0;
	data->color->locked = 1;
	data->color->clicked = 0;
	data->color->rgb = int_to_rgb(data->color->value);
	data->color->hsv = rgb_to_hsv(color);
	data->color->next = (t_color*)ft_malloc(sizeof(t_color));
	data->color->next->value = color2;
	data->color->next->index = 1;
	data->color->next->rgb = int_to_rgb(data->color->next->value);
	data->color->next->hsv = rgb_to_hsv(color2);
	data->color->next->next = NULL;
	data->editedcolor = NULL;
}

void			screeninit(t_data *data, int fra)
{
	if (fra == 0)
		data->onscreen = data->mandelbrot;
	else if (fra == 1)
		data->onscreen = data->julia;
	else if (fra == 2)
		data->onscreen = data->burningship;
	else if (fra == 3)
		data->onscreen = data->glynn;
	else if (fra == 4)
		data->onscreen = data->mandeldrop;
	else if (fra == 5)
		data->onscreen = data->mandelheart;
}

void			ft_fractset2(t_data *data)
{
	data->mandeldrop->formula = &ft_mandeldrop;
	data->mandeldrop->minx = -4;
	data->mandeldrop->maxx = 4;
	data->mandeldrop->miny = -1.75;
	data->mandeldrop->maxy = 4.25;
	data->mandelheart->formula = &ft_mandelheart;
	data->mandelheart->minx = -4;
	data->mandelheart->maxx = 4;
	data->mandelheart->miny = 3.75;
	data->mandelheart->maxy = -2.25;
}
