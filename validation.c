/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:05:09 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/12 19:54:14 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** This function compares char** - plateau with char** -piece.
** The position is valid if it founds only one match.
** If it mathes 0 or more than once - the position on the plateau for the
** piece isn't valid.
** Also the position isn't valid if it is out of the borders of the plateau.
*/
int		find_match(t_struct *strct, int j, int i)
{
	int		ki;
	int		kj;
	int		cnt;

	ki = 0;
	kj = 0;
	cnt = 0;
	while (kj < strct->piece_y)
	{
		ki = 0;
		while (ki < strct->piece_x)
		{
			if (strct->piece[kj][ki] == '*')
				if ((((j + kj) <= strct->plateau_y)
					&& ((i + ki) <= strct->plateau_x))
					&& (strct->plateau[j + kj][i + ki] == strct->player))
					cnt++;
			ki++;
		}
		kj++;
	}
	if (cnt == 1)
		return (1);
	else
		return (0);
}

void	validation(t_struct *strct)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < strct->plateau_y)
	{
		i = 0;
		while (i < strct->plateau_x)
		{
			if (find_match(strct, j, i))
				printf("y = %d	x = %d\n", j, i);		//change printf
			i++;
		}
		j++;
	}
}
