/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 00:42:45 by hakader           #+#    #+#             */
/*   Updated: 2025/03/03 19:21:26 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keyhook, void *param)
{
	if (keyhook == ESC_KEY)
	{
		// mlx_destroy_window(mlx, win);
		exit (0);
	}
}


int main()
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 600, 800, "HAMZA");
	mlx_key_hook(win, key_hook, NULL);
	mlx_loop(mlx);
}