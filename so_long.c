/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:21:31 by hakader           #+#    #+#             */
/*   Updated: 2025/02/27 14:43:52 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pars_square(char **rd_map)
{
	int	x;
	int	y;
	int	check;

	y = 0;
	check = 0;
	if (!rd_map)
		return ;
	while (rd_map[0][check])
		check++;
	while (rd_map[y])
	{
		x = 0;
		while (rd_map[y][x])
			x++;
		if (check != x)
		{
			write(2, RED"Error: Invalid map\n"RESET, 26);
			exit (1);
		}
		y++;
	}
}

void	fl_walls(char *wall)
{
	int	x;

	x = 0;
	if (!wall)
		return ;
	while (wall[x])
	{
		if (wall[x] == '\0' || wall[x] == '\n')
			break;
		if (wall[x] != '1')
		{
			printf("Error\n");
			exit (1);
		}
		x++;
	}
}


void	check_fl_walls(char **map)
{
	int	y;

	y = 0;
	fl_walls(map[0]);
	while(map[y + 1])
		y++;
	fl_walls(map[y]);
}

void	check_rl_walls(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y][x])
		x++;
	x -= 2;
	while (map[y])
	{
		if (map[y][0] != '1' || map[y][x] != '1')
		{
			printf("Error\n");
			exit (1);
		}
		y++;
	}
}

void	map_filter(char *map)
{
	char **rd_map;

	rd_map = read_map(map);

	// free_arr(rd_map);
	pars_square(rd_map);
	check_fl_walls(rd_map);
	check_rl_walls(rd_map);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, RED"Error: <program> <map>\n"RESET, 30);
		exit (1);
	}
	
	map_filter(av[1]);
	// printf("%s", av[2]);
	// write (1, "a", 1);
}
