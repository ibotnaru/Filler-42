/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:10:48 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/10 20:18:49 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** This function changes the '*' to 'O' or 'X'
** depending on player. This function changes the data in structure!
** but it doesn't change the original piece.
*/
void	change_piece(t_struct *strct)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	strct->changed_piece = strct->piece;
	while (strct->piece[j] != NULL)
	{
		while (strct->piece[j][i] != '\0')
		{
			if (strct->piece[j][i] == '*')
			{
				if (strct->player == 'O')
					strct->changed_piece[j][i] = 'O';
				else if (strct->player == 'X')
					strct->changed_piece[j][i] = 'X';
			}
			i++;
		}
		j++;
	}
}

/*
** This function compares char** - sub_plt with char** -piece.
** The position is valid if it founds only one match.
** If it mathes 0 or more than once - the position on the plateau for the
** piece isn't valid.
*/
int		valid_plc(t_struct *strct, char **sub_plt)
{
	int		i;
	int		j;
	int		cnt;

	i = 0;
	j = 0;
	cnt = 0;
	while (j < strct->piece_y)
	{
		while (i < strct->piece_x)
		{
			if (strct->changed_piece[j][i] == sub_plt[j][i])
				cnt++;
			i++;
		}
		j++;
	}
	if (cnt == 1)
		return (1);
	else
		return (0);
}

/*
** This funtion creates a sub_plt(sub plateau) from plateau size of piece
** starting on given indexes for i and j.
*/
char	**sub_plateu(t_struct *strct, int i, int j)
{
	char	**sub_plt;
	int		ki;
	int		kj;

	ki = 0;
	kj = 0;
	sub_plt = (char **)malloc(sizeof(char *) * (strct->piece_y + 1));
	while (kj < strct->piece_y)
	{
		sub_plt[kj] = (char *)malloc(sizeof(char) * (strct->piece_x + 1));
		{
			while (ki < strct->piece_x)
			{
				sub_plt[kj][ki] = strct->plateau[j][i];
				i++;
				ki++;
			}
		}
		sub_plt[kj][ki] = '\0';
		j++;
		kj++;
	}
	sub_plt[kj] = NULL;
	return(sub_plt);
}

void	validation(t_struct *strct)
{
	int		i;
	int		j;
	char	**sub_plt;

	i = 0;
	j = 0;
	while (j < strct->plateau_y)
	{
		while (i < strct->plateau_x)
		{
			sub_plt = sub_plateu(strct, i, j);
			if (valid_plc(strct, sub_plt))
			{
				printf("y = %d\nx = %d", j, i);
			}
			i++;
		}
		j++;
	}
}
