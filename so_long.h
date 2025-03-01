/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:40 by hakader           #+#    #+#             */
/*   Updated: 2025/03/01 15:53:08 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


#define RED "\033[1;31m"
#define RESET "\033[0m"

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "GNL/get_next_line.h"

typedef struct s_map
{
	int x;
	int y;
	int P;
	int E;
	int C;
	int row;
	int colomn;
	char	**map;
	char	**copy;
}	t_map;


char	**read_map(char *map);
void	print_arr(char **str);
void	free_arr(char **str);
void	pars_square(t_map	game);


int	ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char *str, int fd);
void	put_err(char *str);

#endif