/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:45:29 by hakader           #+#    #+#             */
/*   Updated: 2025/02/17 20:23:43 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_square(char *str, int i)
{
	int	j;

	j = 0;
	while (str[j])
	{
		printf("%c", str[j]);
		j++;
	}
	if (j == i)
		return (0);
	return (1);
}

void	pars_square(char **str)
{
	int	i;
 
	i = 0;
	while (str[0][i] == '1')
	{
		if (str[0][i] != '1')
			printf("{{ikhan}}\n");
		i++;
	}
	int j = 0;
	while (str[j])
	{
		if (check_square(str[j], i) == 1)
			printf("((ikhan))\n");
		j++;
	}

}
