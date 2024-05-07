/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:58:49 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/19 14:24:54 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	resize_coef(t_fdf *data, int key)
{
	if (key == PLUS)
		data->size_map *= 1.1;
	if (key == MINUS && data->size_map > 1)
		data->size_map /= 1.1;
}

void	move(t_fdf *data, int key)
{
	if (key == LEFT)
	{
		data->x -= 10 * data->size_map;
		data->x1 -= 10 * data->size_map;
	}
	else if (key == RIGHT)
	{
		data->x += 10 * data->size_map;
		data->x1 += 10 * data->size_map;
	}
	else if (key == UP)
	{
		data->y -= 10 * data->size_map;
		data->y1 -= 10 * data->size_map;
	}
	else if (key == DOWN)
	{
		data->y += 10 * data->size_map;
		data->y1 += 10 * data->size_map;
	}
}

void	change_angle(t_fdf *data, int key)
{
	if (key == W)
		data->angle_y -= 0.1;
	else if (key == A)
		data->angle_x -= 0.1;
	else if (key == S)
		data->angle_y += 0.1;
	else if (key == D)
		data->angle_x += 0.1;
}

void	zoom_in_out(t_fdf *data, int key)
{
	if (key == PLUS_NUM)
	{
		if (data->zoom + data->size_map > 1000)
			data->zoom = 1000;
		else
			data->zoom += 1 * data->size_map;
	}
	if (key == MINUS_NUM)
	{
		if (data->zoom - data->size_map < 0)
			data->zoom = 0;
		else
			data->zoom -= 1 * data->size_map;
	}
}

void	change_z(t_fdf *data, int key)
{
	if (key == P)
		data->coef_z += 1;
	else if (key == M)
		data->coef_z -= 1;
}
