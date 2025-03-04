/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:07:21 by hakader           #+#    #+#             */
/*   Updated: 2025/03/04 11:40:58 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void find_player(t_mlx *mlx)
{
	mlx->p_y = 0;
	while (mlx->game.map[mlx->p_y])
	{
		mlx->p_x = 0;
		while (mlx->game.map[mlx->p_y][mlx->p_x])
		{
			if (mlx->game.map[mlx->p_y][mlx->p_x] == 'P')
				return;
			mlx->p_x++;
		}
		mlx->p_y++;
	}
}
void	rendre_map(t_mlx *mlx)
{
	t_axis	ax;
	ax.y = 0;

	while (mlx->game.map[ax.y])
	{
		ax.x = 0;
		while (mlx->game.map[ax.y][ax.x] && ax.x < mlx->game.column)
		{
			if(mlx->game.map[ax.y][ax.x] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tx.wall, ax.x * 80, ax.y * 80);
			if (mlx->game.map[ax.y][ax.x] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tx.floor, ax.x * 80, ax.y * 80);
			if (mlx->game.map[ax.y][ax.x] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tx.player, ax.x * 80, ax.y * 80);
				
			if (mlx->game.map[ax.y][ax.x] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tx.walk, ax.x * 80, ax.y * 80);
			if (mlx->game.map[ax.y][ax.x] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tx.coin, ax.x * 80, ax.y * 80);
			ax.x++;
		}
		ax.y++;
	}
	
}
int key_hook(int keyhook, t_mlx *mlx)
{
    if (keyhook == KEY_ESC)
        exit(0);

    // Update the player's position
    if (keyhook == KEY_W) // Move Up
        mlx->p_y--;
    else if (keyhook == KEY_S) // Move Down
        mlx->p_y++;
    else if (keyhook == KEY_A) // Move Left
        mlx->p_x--;
    else if (keyhook == KEY_D) // Move Right
        mlx->p_x++;

    printf("Player Position: x = %d, y = %d\n", mlx->p_x, mlx->p_y);

    // Clear the window before redrawing
    mlx_clear_window(mlx->mlx, mlx->win);

    // Redraw the entire map and then the player
    rendre_map(mlx);

    // Place the player at the new position
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tx.player, mlx->p_x * 80, mlx->p_y * 80);

    return (0);
}




int    init_wind(t_mlx *mlx)
{	
	mlx->tx.wall = mlx_xpm_file_to_image(mlx->mlx, "texture/mandatory/wall.xpm", &mlx->game.column, &mlx->game.row);
	mlx->tx.floor = mlx_xpm_file_to_image(mlx->mlx, "texture/mandatory/floor.xpm", &mlx->game.column, &mlx->game.row);
	mlx->tx.player = mlx_xpm_file_to_image(mlx->mlx, "texture/mandatory/player.xpm", &mlx->game.column, &mlx->game.row);
	mlx->tx.coin = mlx_xpm_file_to_image(mlx->mlx, "texture/mandatory/coin.xpm", &mlx->game.column, &mlx->game.row);
	mlx->tx.walk = mlx_xpm_file_to_image(mlx->mlx, "texture/mandatory/walk.xpm", &mlx->game.column, &mlx->game.row);

	return 1;
}

void in_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (ft_putstr("MLX initialization failed", 2));
	mlx->win = mlx_new_window(mlx->mlx, mlx->game.column * 80,
		mlx->game.row * 80, "so_long");
	if (!mlx->win)
		return (ft_putstr("WIN initialization failed", 2));
	find_player(mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
	init_wind(mlx);
	rendre_map(mlx);
	mlx_loop(mlx->mlx);
}
