/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:57:32 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/14 19:45:16 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Counts the sum of '.' after heat_map where the piece is placed.
*/
int		clc_sum(t_struct *strct, int j, int i)
{
	int		kj;
	int		ki;
	int		sum;

	kj = 0;
	ki = 0;
	while (kj < strct->piece_y)
	{
		ki =0;
		while (ki < strct->piece_x)
		{
			if (strct->piece[kj][ki] == '*')
			{
				if ((((j + kj) <= strct->plateau_y)
					&& ((i + ki) <= strct->plateau_x))
					&& (strct->plateau[j + kj][i + ki] == strct->player))
					sum += strct->plateau[j + kj][i + ki];
			}
			ki++;
		}
		kj++;
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

	j = 0;
	i = 0;
	sum = 0;
	tmp = -1;
	while(j < strct->plateau_y)
	{
		while (i < strct->plateau_x)
		{
			sum = clc_sum(&strct, j, i);
			if (tmp >= sum || tmp == -1)
				tmp = sum;
			i++;
		}
		j++;
	}
}
