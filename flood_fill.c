/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:30:48 by hakader           #+#    #+#             */
/*   Updated: 2025/03/03 19:27:27 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floid(char **tab, t_mlx size, t_mlx begin, char *str)
{
	if (begin.x < 0 || begin.y < 0 || size.x >= begin.x
		|| size.y >= begin.y || tab[begin.y][begin.x] != str)
		return ;
	tab[begin.y][begin.x] = 'F';
	floid(tab, size, (t_mlx){begin.x + 1, begin.y}, str);
	floid(tab, size, (t_mlx){begin.x - 1, begin.y}, str);
	floid(tab, size, (t_mlx){begin.x, begin.y + 1}, str);
	floid(tab, size, (t_mlx){begin.x, begin.y - 1}, str);
}

void	flood_fill(char **tab, t_mlx size, t_mlx begin)
{
	floid(tab, size, begin, tab[begin.y][begin.x]);
}
