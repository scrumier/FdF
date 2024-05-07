/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:25:59 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/26 14:51:19 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_countwords(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != ' ')
		{
			count++;
			while (s[i] && s[i] != ' ')
				i++;
		}
		else
			i++;
	}
	return (count);
}

void	quit_fdf(t_fdf *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_all(data);
	exit(EXIT_SUCCESS);
}

void	reset(t_fdf *data)
{
	data->zoom = 20;
	data->size_map = 1;
	data->angle_x = 0.45;
	data->angle_y = 0.45;
	data->coef_z = 1;
	data->x = 0;
	data->y = 0;
}
