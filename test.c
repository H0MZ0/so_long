/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 00:42:45 by hakader           #+#    #+#             */
/*   Updated: 2025/03/03 00:43:27 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

int	key_hook(int keyhook, void *param)
{
	if (keyhook == ESC_KEY)
		exit (0);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "Wahmane");
	mlx_key_hook(win, key_hook, win);
	mlx_loop(mlx);
}
