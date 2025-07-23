/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:00:27 by vrasatry          #+#    #+#             */
/*   Updated: 2025/02/07 18:29:58 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	need_size;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)&haystack[i]);
	if (len == 0)
		return (NULL);
	need_size = ft_strlen(needle);
	while (haystack[i] && i + need_size <= len)
	{
		if (ft_strncmp(&haystack[i], needle, need_size) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	*haystack;
	char	*needle;

	haystack = NULL;
	needle = "  dgr";;
	printf("%s\n", ft_strnstr(haystack, needle, 7));
	return (0);
}*/	
