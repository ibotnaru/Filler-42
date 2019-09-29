/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:57:32 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/29 13:15:10 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Counts the sum of '.' after heat_map where the piece is placed.
*/

int		clc_sum(t_struct *sct, int **map, int j, int i)
{
	int		kj;
	int		ki;
	int		sum;

	sum = 0;
	kj = -1;
	ki = -1;
	while (++kj < sct->piece_y)
	{
		ki = -1;
		while (++ki < sct->piece_x)
		{
			if (sct->piece[kj][ki] == '*')
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

void	place_piece(t_struct *sct, int **map)
{
	int		j;
	int		i;
	int		sum;
	int		tmp;

	j = -1;
	sum = 0;
	tmp = -1;
	while (++j < sct->plt_y)
	{
		i = -1;
		while (++i < sct->plt_x)
		{
			if (find_match(sct, j, i) == 1)
			{
				sum = clc_sum(sct, map, j, i);
				if (tmp > sum || tmp == -1)
				{
					tmp = sum;
					sct->y_for_print = j;
					sct->x_for_print = i;
				}
			}
		}
	}
}
