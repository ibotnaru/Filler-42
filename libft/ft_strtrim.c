/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:43:08 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/02/28 19:21:11 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
		s[i] == '\v' || s[i] == '\r' || s[i] == '\f')
	{
		i++;
	}
	if (i != len)
	{
		j = i;
		i = len - 1;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
			s[i] == '\v' || s[i] == '\r' || s[i] == '\f')
		{
			i--;
		}
		return (ft_strsub(s, j, i - j + 1));
	}
	return (ft_strnew(0));
}
