/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:26:46 by vrasatry          #+#    #+#             */
/*   Updated: 2025/02/05 20:37:49 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	j;

	j = 0;
	src_len = ft_strlen(src);
	dst_len = 0;
	while (dst_len < dst_size && dst[dst_len] != '\0')
		dst_len++;
	if (dst_size <= dst_len)
		return (dst_size + src_len);
	while (src[j] && dst_len + j < dst_size - 1)
	{
		dst[dst_len + j] = src[j];
		j++;
	}
	dst[dst_len + j] = '\0';
	return (dst_len + src_len);
}
/*
int	main(void)
{
	char dst1[50] = "odghkfe\0dfjfksdca";
	char dst2[50] = "";
	char src[50] = "12345678";
	printf("%lu\n", ft_strlcat(dst1, src, 50));
	printf("%lu\n", strlcat(dst2, src, 50));
	return (0);
}
*/
