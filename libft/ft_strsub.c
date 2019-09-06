/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:49:04 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/02/28 19:07:26 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			j;
	char			*dest;

	i = start;
	j = 0;
	if (!s || !(dest = ft_strnew(len)))
		return (NULL);
	while (i < len + start)
	{
		dest[j] = s[i];
		i++;
		j++;
	}
	return (dest);
}
