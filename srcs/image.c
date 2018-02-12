/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 02:10:25 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/12 11:27:48 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				px_to_onscreenimg(t_data *data, int x, int y, int c)
{
	data->onscreen->img_str[x * 4 + y * data->winx * 4] = int_to_rgb(c).b;
	data->onscreen->img_str[x * 4 + y * data->winx * 4 + 1] = int_to_rgb(c).g;
	data->onscreen->img_str[x * 4 + y * data->winx * 4 + 2] = int_to_rgb(c).r;
	data->onscreen->img_str[x * 4 + y * data->winx * 4 + 3] = 0;
}

int					get_px_color(t_data *data, int x, int y)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	b = data->onscreen->img_str[x * 4 + y * data->winx * 4];
	g = data->onscreen->img_str[x * 4 + y * data->winx * 4 + 1];
	r = data->onscreen->img_str[x * 4 + y * data->winx * 4 + 2];
	return (get_rgb(r, g, b));
}

void				ft_printite(t_data *data)
{
	char *str;

	str = ft_itoa(data->onscreen->ite);
	mlx_string_put(data->mlx, data->win, 800, 650, 0xFFFFFF, str);
	free(str);
}

void				print_img(t_data *data)
{
	int				xinc;
	int				yinc;

	xinc = data->winx - 25 - data->winx / 6;
	yinc = data->onscreen->imgy + 25;
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->onscreen->img, 0, 0);
}
