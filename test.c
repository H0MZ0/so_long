#include <mlx.h>
#include "so_long.h"

int	key_hook(int keyhook, void *param)
{
	if (keyhook == ESC_KEY)
	{
		mlx_destroy_image(param, param);
		exit (0);
	}
	return (0);
}

int main()
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "HAMZA");
	mlx_key_hook(mlx, key_hook, mlx);
	mlx_loop(mlx);
}