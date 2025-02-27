/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:21:31 by hakader           #+#    #+#             */
/*   Updated: 2025/02/27 11:50:10 by hakader          ###   ########.fr       */
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

void	map_filter(void)
{
	char **rd_map;

	rd_map = read_map();
	// print_arr(rd_map);
	pars_square(rd_map);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, RED"Error: <program> <map>\n"RESET, 30);
		exit (1);
	}
	(void)av;
	map_filter();
	// write (1, "a", 1);
}


// void	map_filter(void)
// {

// }""