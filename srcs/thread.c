/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 01:58:05 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/12 14:26:23 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_part			ft_palloc(t_data *data, int i, t_fractale *fract)
{
	t_part		part;

	part.y = i;
	part.z = fract->c;
	part.fra = fract;
	part.data = data;
	return (part);
}

void			ft_print(t_data *d, t_fractale *fract)
{
	pthread_t	thr[4];
	t_part		part[4];
	int			i;

	i = -1;
	while (++i < 4)
	{
		part[i] = ft_palloc(d, i, fract);
		if (d->onscreen->locked == 0 || d->onscreen->modified == 1)
			pthread_create(&thr[i], NULL, ft_fractal, (void*)&part[i]);
		else if (d->colorchanged == 1)
			pthread_create(&thr[i], NULL, ft_coloredfractal, (void*)&part[i]);
	}
	while (--i >= 0)
		pthread_join(thr[i], NULL);
	print_img(d);
	ft_printite(d);
}

void			*ft_fractal(void *part)
{
	int			x;
	int			y;
	t_part		*p;
	double		retval;

	p = part;
	y = p->y;
	while (y < p->data->winy)
	{
		x = -1;
		while (++x < p->data->winx)
		{
			if ((retval = p->fra->formula(ft_coord(x, y, p->fra, p->data),
				p->fra->c, p->data->onscreen->ite)) == -1)
				px_to_onscreenimg(p->data, x, y, 0x000000);
			else
				px_to_onscreenimg(p->data, x, y, rgb_grad(retval, p->data,
							p->data->onscreen));
			p->data->onscreen->array[y][x].value = retval;
		}
		y += 4;
	}
	return (NULL);
}

void			*ft_coloredfractal(void *part)
{
	int			x;
	int			y;
	t_part		*p;

	p = part;
	y = p->y;
	while (y < p->data->winy)
	{
		x = -1;
		while (++x < p->data->winx)
		{
			if (p->fra->array[y][x].value == -1)
				px_to_onscreenimg(p->data, x, y, 0x000000);
			else
				px_to_onscreenimg(p->data, x, y, rgb_grad(
					p->fra->array[y][x].value, p->data, p->data->onscreen));
		}
		y += 4;
	}
	return (NULL);
}