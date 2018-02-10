/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:44:02 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/10 18:37:00 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(int keycode, t_data *data)
{
	int	x;
	int	y;

	if (keycode == 126 || keycode == 125)
		y = (keycode == 126) ? data->buttony[3] - 3 : data->buttony[3] + 3;
	else
		y = data->buttony[3];
	if (keycode == 123 || keycode == 124)
		x = (keycode == 123) ? data->buttonx[3] - 3 : data->buttonx[3] + 3;
	else
		x = data->buttonx[3];
	maphandle(x, y, data);
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

int		key(int keycode, t_data *d)
{
	if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124)
		move(keycode, d);
	if (keycode == 15)
		reset_func(d, d->onscreen);
	if (keycode == 53)
		exit(0);
	if (keycode == 69 || keycode == 78)
		ite(keycode, d);
	if (keycode == 69 || keycode == 78 || keycode == 46)
		ft_print(d, d->onscreen);
	return (0);
}

int				maphandle(int x, int y, t_data *d)
{
	t_complex	map1;
	t_complex	map2;

	map1 = ft_coord(x, y, d->onscreen, d);
	map2 = ft_coord(d->buttonx[3], d->buttony[3], d->onscreen, d);
	if (d->buttonx[3] != x)
	{
		d->onscreen->tran.r += map1.r - map2.r;
		d->buttonx[3] = x;
		d->onscreen->modified = 1;
	}
	if (d->buttony[3] != y)
	{
		d->onscreen->tran.i += map1.i - map2.i;
		d->buttony[3] = y;
		d->onscreen->modified = 1;
	}
	ft_print(d, d->onscreen);
	return (1);
}

int				mousewheel(int button, int x, int y, t_data *data)
{
	if (button == 5)
		zoom(1, x, y, data);
	if (button == 4)
		zoom(-1, x, y, data);
	ft_print(data, data->onscreen);
	return (1);
}
