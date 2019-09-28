/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_opponent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 23:41:40 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/27 19:53:50 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Ceates a **map of integers, where '.' is -1,
** player - (-8) and opponent - 1, based on the
** original plt.
*/

int		**create_map(t_struct *strct)
{
	int		i;
	int		j;
	int		**map;

	i = -1;
	j = -1;
	map = (int **)malloc(sizeof(int *) * (strct->plt_y + 1));
	while (++j < strct->plt_y)
	{
		i = -1;
		map[j] = (int *)malloc(sizeof(int) * (strct->plt_x + 1));
		while (++i < strct->plt_x)
		{
			if (strct->plt[j][i] == '.')
				map[j][i] = -1;
			else if ((strct->plt[j][i] == strct->player)
				|| (strct->plt[j][i] == strct->player + 32))
				map[j][i] = -8;
			else if ((strct->plt[j][i] == strct->opponent)
				|| (strct->plt[j][i] == strct->opponent + 32))
				map[j][i] = 1;
		}
		map[j][i] = 0;
	}
	map[j] = NULL;
	return (map);
}

/*
** Takes the coordnts of the opponent and heats the map arround it.
** (we need to change only the positions set with -1).
** j>0 if j-1 is out of borders
** j+1 if j+1 is out of borders
** i>0 if i-1 is out of borders
** i!=0 if i+1 is out of borders
*/

int		**surround_opp(int **map, int j, int i, int cnt)
{
	if (j > 0 && map[j + 1] && i > 0 && i != 0 && map[j - 1][i] == -1)
		map[j - 1][i] = 1 + cnt;
	if (j > 0 && map[j + 1] && i > 0 && i != 0 && map[j + 1][i] == -1)
		map[j + 1][i] = 1 + cnt;
	if (j > 0 && map[j + 1] && i > 0 && i != 0 && map[j][i - 1] == -1)
		map[j][i - 1] = 1 + cnt;
	if (j > 0 && map[j + 1] && i > 0 && i != 0 && map[j][i + 1] == -1)
		map[j][i + 1] = 1 + cnt;
	if (j > 0 && map[j + 1] && i > 0 && i != 0 && map[j - 1][i - 1] == -1)
		map[j - 1][i - 1] = 1 + cnt;
	if (j > 0 && map[j + 1] && i > 0 && i != 0 && map[j - 1][i + 1] == -1)
		map[j - 1][i + 1] = 1 + cnt;
	if (j > 0 && map[j + 1] && i > 0 && i != 0 && map[j + 1][i - 1] == -1)
		map[j + 1][i - 1] = 1 + cnt;
	if (j > 0 && map[j + 1] && i > 0 && i != 0 && map[j + 1][i + 1] == -1)
		map[j + 1][i + 1] = 1 + cnt;
	return (map);
}

/*
** This is an algorithm which finds the opponent (which will be represented
** as nbr - 1) on the map and heats the map (fills the plateu witn numbers)
** oround him to "calculate"(ints) the best position for your piece.
** The new plateu is a two-dimensnl array of (numbers)integers.
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
	k = 0;
	cnt = 0;
	map = create_map(strct);
	k = strct->plt_x > strct->plt_y ? strct->plt_x : strct->plt_y;
	while (++cnt < k)
	{
		j = -1;
		while (++j < strct->plt_y)
		{
			i = -1;
			while (++i < strct->plt_x)
			{
				if (map[j][i] == cnt)
					map = surround_opp(map, j, i, cnt);
			}
		}
	}
	return (map);
}
