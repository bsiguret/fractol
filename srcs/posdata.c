/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   posdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 02:28:02 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/16 17:04:21 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		ft_coordzoom(double x, double y, t_fractale *fra, t_data *data)
{
	t_complex	comp;

	comp.r = (x + (((data->winx - 1) / fabs(fra->maxx - fra->minx)) *
				fra->minx))
		/ ((data->winx - 1) / fabs(fra->maxx - fra->minx));
	comp.i = (y + (((data->winy - 1) / fabs(fra->maxy - fra->miny)) *
				fra->miny))
		/ ((data->winy - 1) / fabs(fra->maxy - fra->miny));
	return (comp);
}

t_complex		ft_mousecoord(double x, double y, t_fractale *fra, t_data *data)
{
	t_complex	comp;

	comp.r = x / (data->winx - 1) *
		(data->onscreen->maxx - data->onscreen->minx) + data->onscreen->minx;
	comp.i = (-(y - data->winy + 1)) / (data->winy - 1) * (data->onscreen->maxy
			- data->onscreen->miny) + data->onscreen->miny;
	comp.r = (comp.r - fra->offset.r) * fra->zoom - fra->tran.r + fra->offset.r;
	comp.i = (comp.i - fra->offset.i) * fra->zoom - fra->tran.i + fra->offset.i;
	return (comp);
}

t_complex		ft_coord(double x, double y, t_fractale *fra, t_data *data)
{
	t_complex	comp;

	(void)data;
	comp.r = x / (data->winx - 1) * (fra->maxx - fra->minx) + fra->minx;
	comp.i = (-(y - data->winy + 1)) / (data->winy - 1) *
		(fra->maxy - fra->miny) + fra->miny;
	comp.r = (comp.r - fra->offset.r) * fra->zoom - fra->tran.r + fra->offset.r;
	comp.i = (comp.i - fra->offset.i) * fra->zoom - fra->tran.i + fra->offset.i;
	return (comp);
}

t_complex		ft_mcoord(double x, double y, t_fractale *fra, t_data *data)
{
	t_complex	comp;

	(void)data;
	comp.r = x / (fra->imgx - 1) * (fra->maxx - fra->minx) + fra->minx;
	comp.i = (-(y - fra->imgy + 1)) / (fra->imgy - 1) * (fra->maxy - fra->miny)
		+ fra->miny;
	comp.r = (comp.r - fra->offset.r) * fra->zoom - fra->tran.r + fra->offset.r;
	comp.i = (comp.i - fra->offset.i) * fra->zoom - fra->tran.i + fra->offset.i;
	return (comp);
}

t_point			ft_point(int x, int y)
{
	t_point		p;

	p.x = x;
	p.y = y;
	return (p);
}
