/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:27:27 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/26 14:59:35 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	mlx_in_data(t_fdf *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, HEIGHT, WIDTH, "FdF");
	data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
	data->zoom = 20;
	data->size_map = 1;
	data->angle_x = 0.45;
	data->angle_y = 0.45;
	data->coef_z = 1;
}

void	exec_keys(int key, t_fdf *data)
{
	if (key == ESC)
		quit_fdf(data);
	else if (key == PLUS || key == MINUS)
		resize_coef(data, key);
	else if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
		move(data, key);
	else if (key == W || key == A || key == S || key == D)
		change_angle(data, key);
	else if (key == PLUS_NUM || key == MINUS_NUM)
		zoom_in_out(data, key);
	else if (key == P || key == M)
		change_z(data, key);
	else if (key == R)
		reset(data);
	else
		return ;
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
	draw(data, *(data->coord));
}

int	main(int ac, char **av)
{
	t_fdf	*data;
	t_coord	coord;

	if (ac != 2)
		return (ft_putstr_fd("Usage: ./fdf file\n", 2), 1);
	check_file(av[1]);
	data = ft_calloc(1, sizeof(t_fdf));
	if (!data)
		ft_error("Error: calloc failed\n");
	data->coord = &coord;
	fdf_init(av[1], data);
	check_data(data);
	mlx_in_data(data);
	data->data_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
				&data->size_line, &data->endian);
	draw(data, coord);
	mlx_loop_hook(data->mlx, handle_no_event, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, &handle_keyrelease, data);
	mlx_loop(data->mlx);
	mlx_destroy_display(data->mlx);
	return (0);
}
