/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:21:31 by hakader           #+#    #+#             */
/*   Updated: 2025/03/01 15:21:13 by hakader          ###   ########.fr       */
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
			put_err("Error: Invalid map\n");
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
			put_err("Error:\nCheck your walls\n");
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
			put_err("Error:\nCheck your walls\n");
		y++;
	}
}

void	count_things(char **map)
{
	int	P;
	int	E;
	int	C;
	int	x;
	int	y;

	P = 0;
	E = 0;
	C = 0;
	y = 0;
	(void)map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				P += 1;
			if (map[y][x] == 'E')
				E += 1;
			if (map[y][x] == 'C')
				C += 1;
			x++;
		}
		y++;
	}
	if (C < 1 || P != 1 || E != 1)
		put_err("Error:\ncheck your map\n");
}

void	check_others(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!(map[y][x] == 'C' || map[y][x] == 'E' || map[y][x] == 'P' || map[y][x] == '0' || map[y][x] == '1' || map[y][x] == '\0' || map[y][x] == '\n'))
				put_err("Error:\nInvalid character in map\n");
			x++;
		}
		y++;
	}
}

void	map_filter(char *map)
{
	char **rd_map;

	rd_map = read_map(map);

	pars_square(rd_map);
	check_fl_walls(rd_map);
	check_rl_walls(rd_map);
	check_others(rd_map);
	count_things(rd_map);
}

int main(int ac, char **av)
{
	if (ac != 2)
		put_err("Error:\n<program> <map>\n");
	if (!(ft_strcmp(".ber", &av[1][ft_strlen(av[1]) - 4]) == 0 && ft_strlen(av[1]) > 4))
		put_err("Error:\nInvalid map\n");
	map_filter(av[1]);
}
