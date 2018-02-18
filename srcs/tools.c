/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:45:41 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/16 17:05:40 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*ft_malloc(int size)
{
	void	*ptr;

	if (!(ptr = malloc(size)))
		ft_error("Malloc failed !\n");
	return (ptr);
}

void		ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(-1);
}

double		ft_max(double a, double b, double c)
{
	if (a >= b && a >= c)
		return (a);
	if (b >= a && b >= c)
		return (b);
	return (c);
}

double		ft_min(double a, double b, double c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

void		zoom(int zoom, int x, int y, t_data *d)
{
	t_complex	coordcursor;

	d->onscreen->zoompos = ft_mousecoord(x, y, d->onscreen, d);
	if (d->onscreen->zoom < 1 && zoom > 0)
		d->onscreen->zoom *= 1.1;
	else if (zoom <= 0)
		d->onscreen->zoom /= 1.1;
	coordcursor = ft_mousecoord(x, y, d->onscreen, d);
	d->onscreen->offset.r -= (coordcursor.r - d->onscreen->zoompos.r);
	d->onscreen->offset.i -= (coordcursor.i - d->onscreen->zoompos.i);
	if (zoom > 0 && d->onscreen->ite > 0)
		d->onscreen->ite -= 1;
	else
		d->onscreen->ite += 1;
	d->onscreen->modified = 1;
}
