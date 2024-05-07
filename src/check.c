/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:47:32 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/26 14:24:06 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_file(char *file)
{
	int		fd;
	char	*extension;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error: file not found\n");
	close(fd);
	extension = ft_strrchr(file, '.');
	if (!(extension && ft_strncmp(extension, ".fdf", 4) == 0))
		ft_error("Error: file is not a .fdf\n");
}

bool	can_i_put_pixel(int x, int y)
{
	if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH)
		return (true);
	else
		return (false);
}
