/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:11:40 by vrasatry          #+#    #+#             */
/*   Updated: 2025/02/05 20:55:21 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;
	size_t			i;

	tmp_src = (unsigned char *) src;
	tmp_dst = (unsigned char *) dst;
	i = -1;
	if (tmp_src == NULL && tmp_dst == NULL)
		return (NULL);
	if (tmp_src > tmp_dst || tmp_dst >= tmp_src + len)
	{
		while (++i < len)
			tmp_dst[i] = tmp_src[i];
	}
	else
	{
		while (len > 0)
		{
			len --;
			tmp_dst[len] = tmp_src[len];
		}
	}
	return (dst);
}

/*int	main(void)
{
	char	src[1000] = "barigun";
	char	dst[1000];

	printf("%p", ft_memmove(dst, src, 7)); 
	return (0);
}*/
