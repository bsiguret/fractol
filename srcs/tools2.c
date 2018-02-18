/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:18:21 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/16 17:05:49 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_func(t_data *d, t_fractale *f)
{
	f->zoompos.r = 0;
	f->zoompos.i = 0;
	f->zoom = 1;
	f->offset.r = 0;
	f->offset.i = 0;
	f->tran.r = 0;
	f->tran.i = 0;
	f->ite = 50;
	ft_print(d, f);
}

void	switch_color(t_data *d, int nb)
{
	if (nb == 18)
		color_reinit(d, COLOR1, COLOR1_1);
	else if (nb == 19)
		color_reinit(d, COLOR2, COLOR2_1);
	else if (nb == 20)
		color_reinit(d, COLOR3, COLOR3_1);
	else if (nb == 21)
		color_reinit(d, COLOR4, COLOR4_1);
	else if (nb == 23)
		color_reinit(d, COLOR5, COLOR5_1);
}

void	color_reinit(t_data *d, int color, int color2)
{
	d->color->value = color;
	d->color->rgb = int_to_rgb(d->color->value);
	d->color->hsv = rgb_to_hsv(color);
	d->color->next->value = color2;
	d->color->next->rgb = int_to_rgb(d->color->next->value);
	d->color->next->hsv = rgb_to_hsv(color2);
	ft_print(d, d->onscreen);
}

void	ite(int keycode, t_data *d)
{
	int	*ite;

	ite = &d->onscreen->ite;
	if (keycode == 69 && d->locked == 0)
	{
		*ite += 5;
		d->onscreen->modified = 1;
	}
	if (keycode == 78 && *ite > 0 && d->locked == 0)
	{
		*ite -= 5;
		d->onscreen->modified = 1;
	}
}

void	cam_lock(t_data *d)
{
	if (d->julia->locked == 0)
		d->julia->locked = 1;
	else if (d->julia->locked == 1)
		d->julia->locked = 0;
}
