/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:03:58 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/02/26 20:49:38 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		c;
	int		l;

	l = ft_strlen(needle);
	if (l == 0)
		return ((char *)haystack);
	i = 0;
	c = 0;
	while (haystack[i])
	{
		if (c < l && haystack[i] == needle[c])
		{
			c++;
			if (c == l)
				return ((char *)(haystack + i - c + 1));
		}
		else
		{
			i -= c;
			c = 0;
		}
		i++;
	}
	return (NULL);
}
