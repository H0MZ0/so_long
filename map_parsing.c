/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:01:07 by hakader           #+#    #+#             */
/*   Updated: 2025/02/27 14:43:05 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}

void	print_arr(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			printf("%c", str[i][j++]);
		i++;
	}
}

char	**read_map(char *map)
{
	int	fd;
	int	i;
	char **str;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		printf("failed to open map");
		exit (1);
	}
	i = 0;
	str = malloc(100 * sizeof(char *));
	if (!str)
		return NULL;
	while ((str[i] = get_next_line(fd)))
		i++;
	str[i] = NULL;
	close(fd);
	return (str);
}
