/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:21:31 by hakader           #+#    #+#             */
/*   Updated: 2025/03/01 22:37:35 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	pars_square(t_map	game)
{
	int	check;

	game.y = 0;
	check = 0;
	if (!game.map)
		return ;
	while (game.map[0][check] && game.map[0][check] != '\n')
		check++;
	while (game.map[game.y])
	{
		game.x = 0;
		while (game.map[game.y][game.x]&& game.map[game.y][game.x] != '\n')
			game.x++;
		if (check != game.x)
			put_err("Error:\nInvalid map\n");
		game.y++;
	}
}



void	count_things(t_map	game)
{
	
	int	x;
	int	y;
	int	P;
	int	E;
	int C;

	P = 0;
	E = 0;
	C = 0;
	y = 0;
	// (void)map;
	while (game.map[y])
	{
		x = 0;
		while (game.map[y][x])
		{
			if (game.map[y][x] == 'P')
				P += 1;
			if (game.map[y][x] == 'E')
				E += 1;
			if (game.map[y][x] == 'C')
				C += 1;
			x++;
		}
		y++;
	}
	if (C < 1 || P != 1 || E != 1)
		put_err("Error:\ncheck your map\n");
}

void	check_others(t_map	game)
{
	int	x;
	int	y;

	y = 0;
	while (game.map[y])
	{
		x = 0;
		while (game.map[y][x])
		{
			if (!(game.map[y][x] == 'C' || game.map[y][x] == 'E'
				|| game.map[y][x] == 'P' || game.map[y][x] == '0'
					|| game.map[y][x] == '1' || game.map[y][x] == '\0'
						|| game.map[y][x] == '\n'))
				put_err("Error:\nInvalid character in map\n");
			x++;
		}
		y++;
	}
}

void	map_filter(char *map)
{
	t_map	game;

	game.map = read_map(map);
	// print_arr(game.map);
	game.copy = game.map;
	pars_square(game);
	check_fl_walls(game);
	check_rl_walls(game);
	check_others(game);
	count_things(game);
}

int main(int ac, char **av)
{
	if (ac != 2)
		put_err("Error:\n<program> <map>\n");
	if (!(ft_strcmp(".ber", &av[1][ft_strlen(av[1]) - 4]) == 0
		&& ft_strlen(av[1]) > 4))
		put_err("Error:\nInvalid map\n");
	map_filter(av[1]);
}
