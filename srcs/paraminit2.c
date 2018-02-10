/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraminit2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:53:57 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/10 01:59:42 by bsiguret         ###   ########.fr       */
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
	data->menu = 0;
	data->colormenu = 0;
	data->clickedsquare = 0;
	data->clickedrainbow = 0;
	data->clickedr = 0;
	data->clickedg = 0;
	data->clickedb = 0;
	data->scrollmenuoffset = 0;
	data->colorchanged = 1;
	data->locked = 0;
	data->button[3] = 0;
	data->buttony[3] = 0;
	data->buttonx[3] = 0;
}

void			colorinit(t_data *data)
{
	data->color = (t_color*)ft_malloc(sizeof(t_color));
	data->color->value = 0x3d2900;
	data->color->index = 0;
	data->color->hover = 0;
	data->color->locked = 1;
	data->color->clicked = 0;
	data->color->rgb = int_to_rgb(data->color->value);
	data->color->hsv = rgb_to_hsv(0x3d2900);
	data->color->next = (t_color*)ft_malloc(sizeof(t_color));
	data->color->next->value = 0xfdc549;
	data->color->next->index = 1;
	data->color->next->hover = 0;
	data->color->next->locked = 1;
	data->color->next->clicked = 0;
	data->color->next->rgb = int_to_rgb(data->color->next->value);
	data->color->next->hsv = rgb_to_hsv(0xfdc549);
	data->color->next->next = NULL;
	data->colormenu = 0;
	data->editedcolor = NULL;
}

void			screeninit(t_data *data, int fra)
{
	data->onscreen = data->mandelbrot;

	if (fra != 0)
		ptrswap(&data->onscreen, &data->screen, data);
}