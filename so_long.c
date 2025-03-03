/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:21:31 by hakader           #+#    #+#             */
/*   Updated: 2025/03/03 00:37:54 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pars_square(t_map *game)
{
	int	check;

	check = 0;
	game->axis.y = 0;
	if (!game->map)
		return ;
	while (game->map[0][check] && game->map[0][check] != '\n')
		check++;
	while (game->map[game->axis.y])
	{
		game->axis.x = 0;
		while (game->map[game->axis.y][game->axis.x]
			&& game->map[game->axis.y][game->axis.x] != '\n')
			game->axis.x++;
		if (check != game->axis.x)
			put_err("Error:\nInvalid map\n");
		game->axis.y++;
	}
}

void	count_things(t_map *game)
{
	game->P = 0;
	game->E = 0;
	game->C = 0;
	game->axis.y = 0;
	while (game->map[game->axis.y])
	{
		game->axis.x = 0;
		while (game->map[game->axis.y][game->axis.x])
		{
			if (game->map[game->axis.y][game->axis.x] == 'P')
				game->P++;
			if (game->map[game->axis.y][game->axis.x] == 'E')
				game->E++;
			if (game->map[game->axis.y][game->axis.x] == 'C')
				game->C++;
			game->axis.x++;
		}
		game->axis.y++;
	}
	if (game->C < 1 || game->P != 1 || game->E != 1)
		put_err("Error:\nCheck your map\n");
}

void	check_others(t_map *game)
{
	game->axis.y = 0;
	while (game->map[game->axis.y])
	{
		game->axis.x = 0;
		while (game->map[game->axis.y][game->axis.x])
		{
			if (!(game->map[game->axis.y][game->axis.x] == 'C'
				|| game->map[game->axis.y][game->axis.x] == 'E'
				|| game->map[game->axis.y][game->axis.x] == 'P'
				|| game->map[game->axis.y][game->axis.x] == '0'
				|| game->map[game->axis.y][game->axis.x] == '1'
				|| game->map[game->axis.y][game->axis.x] == '\n'))
				put_err("Error:\nInvalid character in map\n");
			game->axis.x++;
		}
		game->axis.y++;
	}
}

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

void	copy_map(t_map *game)
{
	int	i;

	i = 0;
	game->copy = malloc(sizeof(char *) * game->row);
	while (i < game->row)
	{
		game->copy[i] = malloc((sizeof(char) * game->column));
		ft_strcpy(game->copy[i], game->map[i]);
		i++;
	}
}

void	map_filter(char *map)
{
	t_map	game;
	t_axis	axis;

	game.map = read_map(map);
	pars_square(&game);
	check_fl_walls(&game);
	check_rl_walls(&game);
	check_others(&game);
	count_things(&game);
	copy_map(&game);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		put_err("Error:\n<program> <map>\n");
	if (!(ft_strcmp(".ber", &av[1][ft_strlen(av[1]) - 4]) == 0
		&& ft_strlen(av[1]) > 4))
		put_err("Error:\nInvalid map\n");
	map_filter(av[1]);
	return (0);
}
