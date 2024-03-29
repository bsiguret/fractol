/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:30:16 by bsiguret          #+#    #+#             */
/*   Updated: 2018/02/16 17:34:44 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

# define WIN_WIDTH 900
# define WIN_HEIGHT 700

# define COLOR1 0x3d3d3d
# define COLOR1_1 0xd6d6d6

# define COLOR2 0x3d2900
# define COLOR2_1 0xfdc549

# define COLOR3 0x1b135b
# define COLOR3_1 0x00e9ff

# define COLOR4 0x5b1420
# define COLOR4_1 0xff0000

# define COLOR5 0x4b5b35
# define COLOR5_1 0x50ff00

# define CM c + m
# define XM x + m

typedef struct		s_value
{
	double			r;
	double			i;
	int				ping;
	double			value;
}					t_value;

typedef struct		s_complex
{
	double			r;
	double			i;
}					t_complex;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_hsv
{
	double			h;
	double			s;
	double			v;
}					t_hsv;

typedef struct		s_color
{
	int				locked;
	int				clicked;
	int				value;
	double			index;
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

	double			zoom;
	t_complex		tran;
	t_complex		zoompos;
	t_complex		offset;

	int				locked;
	int				ite;
	int				imgx;
	int				imgy;
	int				modified;
	double			minx;
	double			maxx;
	double			miny;
	double			maxy;
	void			*img;
	char			*img_str;
	t_value			**array;
	double			(*formula)(t_complex, t_complex, int);

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
	t_fractale		*julia;
	t_fractale		*burningship;
	t_fractale		*glynn;
	t_fractale		*mandeldrop;
	t_fractale		*mandelheart;
	t_fractale		*onscreen;
}					t_data;

typedef struct		s_part
{
	int				y;
	t_complex		z;
	t_fractale		*fra;
	t_data			*data;
}					t_part;

/*
** PARAM INIT **
*/

int					is_fractvalid(int ac, char **av);
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
void				colorinit(t_data *data, int color, int color2);
void				screeninit(t_data *data, int fra);
void				ft_fractset2(t_data *data);

/*
** HOOK FUNCTIONS
*/

int					mousewheel(int button, int x, int y, t_data *data);
int					key(int keycode, t_data *d);
void				move(int keycode, t_data *data);
int					maphandle(int x, int y, t_data *d);
int					mouse_mov(int x, int y, t_data *d);

/*
** COMPLEX
*/

t_complex			ft_comp(double x, double y);
t_complex			ft_cinv(t_complex c);
double				ft_cmod(t_complex comp);
double				ft_cangle(t_complex c);
t_complex			ft_conj(t_complex c);
t_complex			ft_cmul(t_complex c1, t_complex c2);
t_complex			ft_cadd(t_complex c1, t_complex c2);
t_complex			ft_csqr(t_complex comp);
t_complex			ft_cabs(t_complex c);
t_complex			ft_cpow(t_complex c, double power);

/*
** FRACTALE **
*/

double				ft_mandelbrot(t_complex c, t_complex z, int ite);
double				ft_julia(t_complex c, t_complex z, int ite);
double				ft_burningship(t_complex c, t_complex z, int ite);
double				ft_glynn(t_complex c, t_complex z, int ite);
double				ft_mandeldrop(t_complex c, t_complex z, int ite);
double				ft_mandelheart(t_complex c, t_complex z, int ite);
double				ft_checkvalue(t_complex comp);

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
** SMOOTH COLOR **
*/

int					rgb_grad(double retval, t_data *data, t_fractale *fract);
double				ft_get_retval(double retval, t_data *data);
int					ft_get_lastcolor(double retval, t_data *data);
int					ft_get_firstcolor(double retval, t_data *data);
int					getstep(unsigned char val1, unsigned char val2, double ret);
void				*ft_coloredfractal(void *part);

/*
** DRAW **
*/
void				ft_line(t_point a, t_point b, t_data *data, int color);
void				ft_print(t_data *data, t_fractale *fract);
void				*ft_fractal(void *part);

/*
** IMAGE FUNCTION **
*/
void				print_img(t_data *data);
int					get_px_color(t_data *data, int x, int y);
void				px_to_onscreenimg(t_data *data, int x, int y, int c);
void				ft_printite(t_data *data);

/*
** POS DATA
*/
t_complex			ft_coordzoom(double x, double y, t_fractale *fra,
	t_data *data);
t_complex			ft_mousecoord(double x, double y, t_fractale *fra,
	t_data *data);
t_complex			ft_coord(double x, double y, t_fractale *fra, t_data *data);
t_complex			ft_mcoord(double x, double y, t_fractale *fra,
	t_data *data);
t_point				ft_point(int x, int y);

/*
** TOOLS **
*/

void				*ft_malloc(int size);
void				ft_error(char *str);
double				ft_max(double a, double b, double c);
double				ft_min(double a, double b, double c);
void				zoom(int zoom, int x, int y, t_data *d);

void				reset_func(t_data *d, t_fractale *f);
void				switch_color(t_data *d, int nb);
void				color_reinit(t_data *d, int color, int color2);
void				ite(int keycode, t_data *d);
void				cam_lock(t_data *d);

void				fract_switch(t_data *data, int keycode);

#endif
