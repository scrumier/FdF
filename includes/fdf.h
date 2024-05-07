/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:39:43 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/26 14:47:10 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "keys.h"
# include <X11/X.h>

# define WIDTH 1024
# define HEIGHT 1024
# define GROUND 0

typedef struct s_coord
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}			t_coord;

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
	int		alpha;
}			t_color;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	float	angle_y;
	float	angle_x;
	int		z;
	int		z1;
	int		max_z;
	int		coef_z;
	float	x;
	float	y;
	float	x1;
	float	y1;
	float	size_map;
	int		int_color;

	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_coord	*coord;
}			t_fdf;

int		ft_countwords(char *s);
void	fdf_init(char *file, t_fdf *data);
void	bresenham(t_coord coord, t_fdf *data);
void	draw(t_fdf *data, t_coord coords);
void	isometric(float *x, float *y, int z, t_fdf *data);
void	free_all(t_fdf *data);
void	check_file(char *file);
void	check_data(t_fdf *data);
int		ft_isnumber(int c);
bool	can_i_put_pixel(int x, int y);
void	ft_error(char *str);
void	exec_keys(int key, t_fdf *data);
int		handle_keyrelease(int key, t_fdf *data);
int		handle_keypress(int key, t_fdf *data);
int		handle_no_event(t_fdf *data);

void	reset(t_fdf *data);
void	zoom_in_out(t_fdf *data, int key);
void	change_z(t_fdf *data, int key);
void	change_angle(t_fdf *data, int key);
void	move(t_fdf *data, int key);
void	resize_coef(t_fdf *data, int key);
void	quit_fdf(t_fdf *data);

#endif
