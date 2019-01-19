/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:12:03 by mde-laga          #+#    #+#             */
/*   Updated: 2018/11/19 18:00:29 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dest;
	char	*sourc;

	i = 0;
	dest = dst;
	sourc = (char*)src;
	while (i < n && (i == 0 || (unsigned char)sourc[i - 1] != (unsigned char)c))
	{
		dest[i] = sourc[i];
		i++;
	}
	if (i > 0 && (unsigned char)sourc[i - 1] == (unsigned char)c)
		return (dest + i);
	return (NULL);
}
