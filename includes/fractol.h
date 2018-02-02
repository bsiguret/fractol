/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:30:16 by bsiguret          #+#    #+#             */
/*   Updated: 2018/01/27 18:28:18 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>

# define WIN_WIDTH 1000
# define WIN_HEIGHT 800

typedef struct		s_complex
{
	float			r;
	float			i;
}					t_complex;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef	struct		s_fractale
{

	t_complex		c;

	float			zoom;
	t_complex		zoompos;
	t_complex		offset;

	int				locked;
	int				ite;
	int				imgx;
	int				imgy;
	int				modified;
	float			minx;
	float			maxx;
	float			miny;
	float			maxy;
	void			*img;
	char			*img_str;
	float			(*formula)(t_complex, t_complex, int);

}					t_fractale;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_str;
	int				winx;
	int				winy;
}					t_data;

/*
** PARAM INIT **
*/
int					is_fractvalid(int argc, char **argv);
t_data				*init(int fract);
void				mlx_img_init(t_data *data);
t_fractale			*fractalinit(t_data *data);
void				ft_fractset(t_data *data);


/*
** TOOLS **
*/

void				*ft_malloc(int size);
void				ft_error(char *str);


#endif