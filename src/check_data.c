/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:35:39 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/21 14:26:35 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_dimensions(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
			j++;
		if (data->width != j)
			ft_error("Error: invalid map\n");
		i++;
	}
}

void	check_range(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->z_matrix[i][j] < -100 || data->z_matrix[i][j] > 500)
				ft_error("Error: map too high/low\n");
			j++;
		}
		i++;
	}
}

void	check_data(t_fdf *data)
{
	if (data->height < 2 || data->width < 2)
		ft_error("Error: map too small (minimum 2x2)\n");
	check_dimensions(data);
	check_range(data);
}
