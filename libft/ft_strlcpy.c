/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:44:05 by vrasatry          #+#    #+#             */
/*   Updated: 2025/02/07 18:03:49 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (n != 0)
	{
		while (src[i] != 0 && i < (n - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}

/*int	main(void)
{
	char	src[50] = "barev";
	char	dst[50] = "ynngersssssss";
	int	dst_size = ft_strlen(dst);
	printf("%zu\n", ft_strlcpy(src, dst, dst_size));
	printf("%s", src);
	return (0);
}*/
