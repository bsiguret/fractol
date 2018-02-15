/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:28:23 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/15 16:47:00 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				is_fractvalid(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl("usage:	./fractol param");
		ft_putendl("possible param: mandelbrot, julia, burningship, glynn, mandeldrop");
		exit(-1);
	}
	else if (ft_strcmp(av[1], "mandelbrot") == 0)
		return (0);
	else if (ft_strcmp(av[1], "julia") == 0)
		return (1);
	else if (ft_strcmp(av[1], "burningship") == 0)
		return (2);
	else if (ft_strcmp(av[1], "glynn") == 0)
		return (3);
	else if (ft_strcmp(av[1], "mandeldrop") == 0)
		return (4);
	else
		return (is_fractvalid(1, av));
}

int				main(int ac, char **av)
{
	t_data		*data;
	int			fract;

	fract = is_fractvalid(ac, av);
	data = init(fract);
	mlx_hook(data->win, 2, 0, key, data);
	mlx_hook(data->win, 4, 0, mousewheel, data);
	mlx_hook(data->win, 6, 0, mouse_mov, data);
	ft_print(data, data->onscreen);
	mlx_loop(data->mlx);
	return (0);
}