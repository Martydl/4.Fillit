/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:48:02 by mde-laga          #+#    #+#             */
/*   Updated: 2018/11/20 11:16:21 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (src > dst)
		while (++i < len)
			((char*)dst)[i] = ((char*)src)[i];
	if (src < dst)
		while (len--)
			((char*)dst)[len] = ((char*)src)[len];
	return (dst);
}
