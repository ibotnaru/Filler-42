/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:15:56 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/02/26 17:08:17 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int		nbrc;
	int		len;

	len = 0;
	nbrc = n;
	while (nbrc != 0)
	{
		nbrc = nbrc / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*str;

	len = (n < 0 ? 1 : 0) + ft_len(n);
	sign = n < 0 ? -1 : 1;
	if (!(str = malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (n == -2147483648)
	{
		n = -214748364;
		str[--len] = '8';
	}
	n = (n < 0) ? -n : n;
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[len-- - 1] = n % 10 + '0';
		n = n / 10;
	}
	if (sign < 0)
		str[len - 1] = '-';
	return (str);
}
