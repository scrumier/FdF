/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:57:17 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/03/26 15:02:31 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	get_height_and_width(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	int		current_width;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Error: file not found\n");
	line = get_next_line(fd);
	if (!line)
		ft_error("Error: file is empty\n");
	data->height = 0;
	data->width = 0;
	while (line != NULL)
	{
		current_width = ft_countwords(line);
		if (current_width > data->width)
			data->width = current_width;
		free(line);
		line = get_next_line(fd);
		(data->height)++;
	}
	free(line);
	close(fd);
}

static void	fill(int *z_line, char *line, int width)
{
	int		i;
	char	**nbr;

	nbr = ft_split(line, ' ');
	if (!nbr)
		ft_error("Malloc failed\n");
	i = 0;
	while (i < width)
	{
		if (nbr[i] != NULL && (ft_atoi(nbr[i]) < 2147483647)
			&& (ft_atoi(nbr[i]) > -2147483648))
			z_line[i] = ft_atoi(nbr[i]) - GROUND;
		else
			z_line[i] = GROUND;
		free(nbr[i]);
		i++;
	}
	free(nbr);
}

static int	find_max_z_value(t_fdf *data)
{
	int	max_z;
	int	i;
	int	j;
	int	z_tmp;

	i = 0;
	j = 0;
	max_z = INT_MIN;
	while (i < data->height)
	{
		while (j < data->width)
		{
			z_tmp = data->z_matrix[i][j] - GROUND;
			if (z_tmp > max_z)
				max_z = z_tmp;
			j++;
		}
		i++;
	}
	return (max_z);
}

void	fill_z_matrix(char *file, t_fdf *data, int height)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Error: file not found\n");
	while (i < height)
	{
		line = get_next_line(fd);
		fill(data->z_matrix[i], line, data->width);
		free(line);
		i++;
	}
	close(fd);
}

void	fdf_init(char *file, t_fdf *data)
{
	int	i;

	get_height_and_width(file, data);
	data->z_matrix = ft_calloc(data->height, sizeof(int *));
	if (!data->z_matrix)
		ft_error("Malloc failed\n");
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = ft_calloc(data->width, sizeof(int));
		if (!data->z_matrix[i])
			ft_error("Malloc failed\n");
		i++;
	}
	fill_z_matrix(file, data, data->height);
	data->size_map = (data->width + data->height) / 2;
	data->max_z = find_max_z_value(data);
}
