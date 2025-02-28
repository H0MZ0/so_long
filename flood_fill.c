/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:30:48 by hakader           #+#    #+#             */
/*   Updated: 2025/02/28 20:16:17 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    floid(char **tab, t_point size, t_point begin, char *str)
{
	if (begin.x < 0 || begin.y < 0 || begin.x >= size.x 
		|| begin.y >= size.y || str != tab[begin.y][begin.x])
		return ;
	tab[begin.y][begin.x] = 'F';
	floid(tab, (t_point){begin.x + 1, begin.y}, size, str);
	floid(tab, (t_point){begin.x - 1, begin.y}, size, str);
	floid(tab, (t_point){begin.x, begin.y + 1}, size, str);
	floid(tab, (t_point){begin.x, begin.y - 1}, size, str);
}

void    flood_fill(char **tab, t_point size, t_point begin)
{
	floid(tab, size, begin, tab[begin.y][begin.x]);
}
