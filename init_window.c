/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:07:21 by hakader           #+#    #+#             */
/*   Updated: 2025/03/04 16:47:56 by hakader          ###   ########.fr       */
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
void    rendre_map(t_mlx *mlx)
{
    t_axis    ax;
    ax.y = 0;

    while (mlx->game.map[ax.y])
    {
        ax.x = 0;
        while (mlx->game.map[ax.y][ax.x] && ax.x < mlx->game.column)
        {
            if(mlx->game.map[ax.y][ax.x] == '1')
                mlx->tx.character = mlx->tx.wall;
            else if (mlx->game.map[ax.y][ax.x] == '0')
                mlx->tx.character = mlx->tx.floor;
            else if (mlx->game.map[ax.y][ax.x] == 'P')
                mlx->tx.character = mlx->tx.player;
            else if (mlx->game.map[ax.y][ax.x] == 'E')
                mlx->tx.character = mlx->tx.door;
            else if (mlx->game.map[ax.y][ax.x] == 'C')
                mlx->tx.character = mlx->tx.coin;
            mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tx.character, ax.x * 80, ax.y * 80);
            ax.x++;
        }
        ax.y++;
    }
    
}
int key_hook(int keyhook, t_mlx *mlx)
{
    find_player(mlx);
    if (keyhook == KEY_ESC)
        exit(0);

    if (keyhook == KEY_W || keyhook == KEY_UP)
    {
        if (mlx->game.map[mlx->p_y - 1][mlx->p_x] == '0' || mlx->game.map[mlx->p_y - 1][mlx->p_x] == 'C')
        {
            mlx->game.map[mlx->p_y - 1][mlx->p_x] = 'P';
            mlx->game.map[mlx->p_y][mlx->p_x] = '0'; 
        }
    }
    else if (keyhook == KEY_S || keyhook == KEY_DOWN)
    {
        if (mlx->game.map[mlx->p_y + 1][mlx->p_x] == '0' || mlx->game.map[mlx->p_y + 1][mlx->p_x] == 'C')
        {
            mlx->game.map[mlx->p_y + 1][mlx->p_x] = 'P'; 
            mlx->game.map[mlx->p_y][mlx->p_x] = '0'; 
        }
    }
    else if (keyhook == KEY_A || keyhook == KEY_LEFT)
    {
        if (mlx->game.map[mlx->p_y][mlx->p_x - 1] == '0' || mlx->game.map[mlx->p_y][mlx->p_x - 1] == 'C')
        {
            mlx->game.map[mlx->p_y][mlx->p_x - 1] = 'P'; 
            mlx->game.map[mlx->p_y][mlx->p_x] = '0'; 
        }
    }
    else if (keyhook == KEY_D || keyhook == KEY_RIGHT)
    {
        if (mlx->game.map[mlx->p_y][mlx->p_x + 1] == '0' || mlx->game.map[mlx->p_y][mlx->p_x + 1] == 'C')
        {
            mlx->game.map[mlx->p_y][mlx->p_x + 1] = 'P'; 
            mlx->game.map[mlx->p_y][mlx->p_x] = '0'; 
        }
    }

    rendre_map(mlx);
    return (0);
}

int    init_wind(t_mlx *mlx)
{	
	mlx->tx.wall = mlx_xpm_file_to_image(mlx->mlx, "texture/mandatory/wall.xpm", &mlx->game.column, &mlx->game.row);
	mlx->tx.floor = mlx_xpm_file_to_image(mlx->mlx, "texture/mandatory/floor.xpm", &mlx->game.column, &mlx->game.row);
	mlx->tx.player = mlx_xpm_file_to_image(mlx->mlx, "texture/mandatory/player.xpm", &mlx->game.column, &mlx->game.row);
	mlx->tx.coin = mlx_xpm_file_to_image(mlx->mlx, "texture/mandatory/coin.xpm", &mlx->game.column, &mlx->game.row);
	mlx->tx.door = mlx_xpm_file_to_image(mlx->mlx, "texture/mandatory/door.xpm", &mlx->game.column, &mlx->game.row);

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
	init_wind(mlx);
	find_player(mlx);
	rendre_map(mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_loop(mlx->mlx);
}
