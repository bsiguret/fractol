/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:37:41 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/16 17:05:29 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fract_switch(t_data *data, int keycode)
{
	if (keycode == 83)
		data->onscreen = data->mandelbrot;
	else if (keycode == 84)
		data->onscreen = data->julia;
	else if (keycode == 85)
		data->onscreen = data->burningship;
	else if (keycode == 86)
		data->onscreen = data->glynn;
	else if (keycode == 87)
		data->onscreen = data->mandeldrop;
	else if (keycode == 88)
		data->onscreen = data->mandelheart;
}
