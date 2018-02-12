/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:28:23 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/12 16:22:03 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				is_fractvalid(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("usage:	./fractol param");
		ft_putendl("possible param: mandelbrot, julia");
		exit(-1);
	}
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		return (0);
	else if (ft_strcmp(argv[1], "julia") == 0)
		return (1);
	else
		return (is_fractvalid(1, argv));
}

int				main(int argc, char **argv)
{
	t_data		*data;
	int			fract;

	fract = is_fractvalid(argc, argv);
	data = init(fract);
	mlx_hook(data->win, 2, 0, key, data);
	mlx_hook(data->win, 4, 0, mousewheel, data);
	mlx_hook(data->win, 6, 0, mouse_mov, data);
	ft_print(data, data->onscreen);
	mlx_loop(data->mlx);
	return (0);
}