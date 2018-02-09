/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:09:14 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/03 19:21:05 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float				ft_mandelbrot(t_complex c, t_complex z, int ite)
{
	int				i;
	float			ret;

	i = 0;
	while (i < ite)
	{
		z = ft_cadd(ft_csqr(z), c);
		if (ft_checkvalue(z) > 100)
		{
			ret = (i + 1 - log(log(ft_checkvalue(z))) / log(2)) / ite;
			return (ret);
		}
		i++;
	}
	return (-1);
}

void		mandelbrot_init(t_fractale *f)
{
	f->xmin = -2.0f;
	f->xmax = 1.0f;
	f->ymin = -1.0f;
	f->ymax = 1.0f;
	f->offx = -0.5f;
}