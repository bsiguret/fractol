/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:30:16 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/09 17:01:06 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>

# define WIN_WIDTH 1800
# define WIN_HEIGHT 1400

typedef struct		s_value
{
	float			r;
	float			i;
	int				ping;
	float			value;
}					t_value;

typedef struct		s_complex
{
	float			r;
	float			i;
}					t_complex;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_hsv
{
	float			h;
	float			s;
	float			v;
}					t_hsv;

typedef struct		s_color
{
	int				locked;
	int				clicked;
	int				hover;
	int				value;
	float			index;
	t_hsv			hsv;
	t_rgb			rgb;
	struct s_color	*next;
}					t_color;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef	struct		s_fractale
{

	t_complex		c;

	float			zoom;
	t_complex		tran;
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
	t_value			**array;
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
	int				locked;
	int				menu;
	int				scrollmenuoffset;
	int				colormenu;
	int				clickedsquare;
	int				clickedrainbow;
	int				clickedr;
	int				clickedg;
	int				clickedb;
	int				pickedcolor;
	t_color			*editedcolor;
	int				colorchanged;
	int				key[279];
	int				button[7];
	int				buttonx[7];
	int				buttony[7];
	t_color			*color;
	t_fractale		*mandelbrot;
	t_fractale		*onscreen;
	t_fractale		*screen;
}					t_data;

/*
** PARAM INIT **
*/

int					is_fractvalid(int argc, char **argv);
t_data				*init(int fract);
void				mlx_img_init(t_data *data);
void				img_init(t_fractale *fract, t_data *data);
t_fractale			*fractalinit(t_data *data);
void				ft_fractset(t_data *data);

/*
** PARAM INIT 2 **
*/

t_value				**arrayinit(int xmax, int ymax);
void				boolinit(t_data *data);
void				colorinit(t_data *data);
void				screeninit(t_data *data, int fra);


/*
** HOOK FUNCTIONS
*/

int					button_on(int button, int x, int y, t_data *data);
int					button_off(int button, int x, int y, t_data *data);
// void				leftbuttonclick(int x, int y, t_data *data);
// int					rightbuttonclick(int x, int y, t_data *data);
void				mousewheel(int button, int x, int y, t_data *data);

/*
** COMPLEX
*/

t_complex			ft_comp(float x, float y);
t_complex			ft_cinv(t_complex c);
float				ft_cmod(t_complex comp);
float				ft_cangle(t_complex c);
t_complex			ft_conj(t_complex c);
t_complex			ft_cmul(t_complex c1, t_complex c2);
t_complex			ft_cadd(t_complex c1, t_complex c2);
t_complex			ft_csqr(t_complex comp);
t_complex			ft_cabs(t_complex c);
t_complex			ft_cpow(t_complex c, float power);

/*
** MANDELBROT **
*/

float				ft_mandelbrot(t_complex c, t_complex z, int ite);
void				mandelbrot_init(t_fractale *f);
float				ft_checkvalue(t_complex comp);

/*
** COLOR **
*/

int					hsv_to_rgb(t_hsv hsv);
t_hsv				rgb_to_hsv(int color);
void				modifyhue(int y, t_data *data);
void				modifysv(int x, int y, t_data *data);
void				modifyrgb(int x, t_data *data);
t_rgb				int_to_rgb(int c);
int					get_rgb(unsigned char r, unsigned char g, unsigned char b);
int					rgb_to_int(t_rgb rgb);
int					get_closestcolor(t_color *color);
void				ptrswap(t_fractale **ptr1, t_fractale **ptr2, t_data *data);

/*
** COLOR GRADIENT **
*/

int					rgb_grad(float retval, t_data *data, t_fractale *fract);
float				ft_get_retval(float retval, t_data *data);
int					ft_get_lastcolor(float retval, t_data *data);
int					ft_get_firstcolor(float retval, t_data *data);
int					getstep(unsigned char val1, unsigned char val2, float ret);

/*
** DRAW **
*/
void				ft_line(t_point a, t_point b, t_data *data, int color);

/*
** TOOLS **
*/

void				*ft_malloc(int size);
void				ft_error(char *str);
float				ft_max(float a, float b, float c);
float				ft_min(float a, float b, float c);

#endif