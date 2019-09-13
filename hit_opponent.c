/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_opponent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 23:41:40 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/13 00:53:47 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		**create_map(t_struct *strct)
{
	int		i;
	int		j;
	int		**map;

	i = 0;
	j = 0;
	map = (int **)malloc(sizeof(int *) * (strct->plateau_y + 1));
	while (j < strct->plateau_y)
	{
		i = 0;
		//map = (int *)malloc(sizeof(int) * (strct->plateau_x + 1));
		map = (int *)malloc(sizeof(int) * (strct->plateau_x));
		while (i < strct->plateau_x)
		{
			if (map[j][i] == '.')
				map[j][i] = 0;
			else if ((map[j][i] == strct->player)
				|| (map[j][i] == strct->player + 32))	// O || o
				map[j][i] = -1;
			else if ((map[j][i] == strct->opponent)
				|| (map[j][i] == strct->opponent + 32))		// X || x
				map[j][i] = 1;
			i++;
		}
		//map[i][j] = 0;
		j++;
	}
	map[j] = NULL;
	return(map);
}

int		**surround_opp(strct, map, i, j)
{
 //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

/*
** This is an algorithm which finds the opponend (which will be represented
** as nbr - 1) on the map and heats the map (fills the plateu witn numbers)
** oround him to "calculate"(ints) the best position for your piece.
** The new plateu is a double array of (numbers)integers.
*/
int		**heat_map(t_struct *strct)
{
	int		i;
	int		j;
	int		k;
	int		cnt;
	int		**map;

	i = 0;
	j = 0;
	k = 1;
	map = create_map(strct);
	while (j < strct->plateau_y)
	{
		i = 0;
		while (i < strct->plateau_x)
		{
			// STOP HERE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			if (map[j][i] == 1 + cnt)								//found the opponent
			{
				map = surround_opp(strct, map, i, j);				//surround the opponent
			i++;
		}
		j++;
	}
	return (map);
}
