/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 21:37:08 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/02/26 20:35:27 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int sign;
	int number;

	sign = 1;
	i = 0;
	number = 0;
	while (*(str + i) == ' ' || *(str + i) == '\t' || *(str + i) == '\n' ||
		*(str + i) == '\v' || *(str + i) == '\r' || *(str + i) == '\f')
		i++;
	if (*(str + i) == '+')
		i++;
	else if (*(str + i) == '-')
	{
		sign = -1;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		number = 10 * number + *(str + i) - '0';
		i++;
	}
	return (number * sign);
}
