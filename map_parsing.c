/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:01:07 by hakader           #+#    #+#             */
/*   Updated: 2025/03/01 18:46:57 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	column(char *map)
{
	char	*str;
	int	fd;
	int	size;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		printf("failed to open map");
		exit (1);
	}
	size = 0;
	while ((str = get_next_line(fd)))
	{
		free(str);
		size++;
	}
	close(fd);
	return (size);
}


char	**read_map(char *map)
{
	int	fd;
	int	i;
	int	lines;
	char **str;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		printf("failed to open map");
		exit (1);
	}
	lines = column(map);
	str = malloc(lines * sizeof(char *));
	if (!str)
		return NULL;
	i = 0;
	while ((str[i] = get_next_line(fd)))
		i++;
	str[i] = NULL;
	close(fd);
	return (str);
}
