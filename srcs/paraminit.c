/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraminit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:33:20 by bsiguret          #+#    #+#             */
/*   Updated: 2018/01/27 18:27:21 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data			*init(int fract)
{
	t_data	*data;

	data = (t_data*)ft_malloc(sizeof(t_data));
	if (!(data->mlx = mlx_init()))
		ft_error("Mlx init failed.");
	data->winx = WIN_WIDTH;
	data->winy = WIN_HEIGHT;
	if (!(data->win =
				mlx_new_window(data->mlx, data->winx, data->winy, "fractol")))
		ft_error("New window creation failed.");
	data->img = NULL;
	data->mandelbrot = fractalinit(data);
	// boolinit(data);
	ft_fractset(data);
	// screeninit(data, fract);
	fract = 2;
	// colorinit(data);
	mlx_img_init(data);
	return (data);
}


t_fractale		*fractalinit(t_data *data)
{
	t_fractale	*fract;

	fract = (t_fractale*)ft_malloc(sizeof(t_fractale));
	fract->zoompos.r = 0;
	fract->zoompos.i = 0;
	fract->offset.r = 0;
	fract->offset.i = 0;
	fract->tran.r = 0;
	fract->tran.i = 0;
	fract->zoom = 1;
	fract->ite = 50;
	fract->c = ft_comp(0, 0);
	fract->imgx = data->winx / 6;
	fract->imgy = (data->winy - 125) / 5;
	fract->locked = 1;
	fract->modified = 1;
	img_init(fract, data);
	fract->array = arrayinit(WINX, WINY);
	fract->miniarray = arrayinit(WINX / 6, (WINY - 125) / 5);
	return (fract);
}

void			ft_fractset(t_data *data)
{
	data->mandelbrot->formula = &ft_mandelbrot;
	data->mandelbrot->minx = -2.5;
	data->mandelbrot->maxx = 1.5;
	data->mandelbrot->miny = -1.5;
	data->mandelbrot->maxy = 1.5;
}

void			mlx_img_init(t_data *data)
{
	int			bpp;
	int			sl;
	int			endian;

	if (!(data->img = mlx_new_image(data->mlx, data->winx, data->winy)))
		exit(-1);
	if (!(data->img_str = mlx_get_data_addr(data->img, &bpp, &sl, &endian)))
		exit(-1);
}

void			img_init(t_fractale *fract, t_data *data)
{
	int			bpp;
	int			sl;
	int			endian;

	if (!(fract->img = mlx_new_image(data->mlx, data->winx, data->winy)))
		ft_error("fractal->img creation failed !\n");
	if (!(fract->img_str = mlx_get_data_addr(fract->img, &bpp, &sl, &endian)))
		ft_error("fractal->img_str creation failed !\n");
}