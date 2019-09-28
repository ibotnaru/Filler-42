/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:57:32 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/20 22:09:40 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Counts the sum of '.' after heat_map where the piece is placed.
*/

int		clc_sum(t_struct *strct, int **map, int j, int i)
{
	int		kj;
	int		ki;
	int		sum;

	sum = 0;
	kj = -1;
	ki = -1;
	while (++kj < strct->piece_y)
	{
		ki = -1;
		while (++ki < strct->piece_x)
		{
			if (strct->piece[kj][ki] == '*')
			{
				sum += map[j + kj][i + ki];
			}
		}
	}
	return (sum);
}

/*
** The function finds the best position from all possible,
** for the piece, on heat_map.
** The best position, is the position which is "smallest" sum.
** Smallest sum is definded by an algorithm.
** Westaring from the j = 0 i = 0 (beggining of the map) and send every
** position(dot) on the map to clc_sum funct which returns the sum of
** of the dots where the piece is placed.
*/

void	place_piece(t_struct *strct, int **map)
{
	int		j;
	int		i;
	int		sum;
	int		tmp;

	j = -1;
	sum = 0;
	tmp = -1;
	while (++j < strct->plt_y)
	{
		i = -1;
		while (++i < strct->plt_x)
		{
			if (find_match(strct, j, i) == 1)
			{
				sum = clc_sum(strct, map, j, i);
				if (tmp > sum || tmp == -1)
				{
					tmp = sum;
					strct->y_for_print = j;
					strct->x_for_print = i;
				}
			}
		}
	}
}
