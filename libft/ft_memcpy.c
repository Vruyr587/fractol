/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:55:00 by vrasatry          #+#    #+#             */
/*   Updated: 2025/01/25 21:50:55 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;
	size_t			i;

	if (src == NULL && dst == NULL)
		return (dst);
	tmp_src = (unsigned char *) src;
	tmp_dst = (unsigned char *) dst;
	i = -1;
	while (++i < n)
		tmp_dst[i] = tmp_src[i];
	return (dst);
}

/*int	main(void)
{
	char *src;
	src = "barigunmaylmo";
	char dst[1000] = "(null!)";
	
	printf("%p\n", ft_memcpy(dst, src, 7));
	return (0);
}*/
