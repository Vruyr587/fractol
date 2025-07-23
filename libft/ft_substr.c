/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:26:44 by vrasatry          #+#    #+#             */
/*   Updated: 2025/02/14 20:52:15 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_malloc_count(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (s[start + i] && i < len)
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	i;
	size_t	fixed_len;

	if (!s)
		return (NULL);
	if (!*s || ft_strlen(s) <= start)
		return (ft_strdup(""));
	i = 0;
	fixed_len = ft_malloc_count(s, start, len);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	s1 = (char *)malloc(sizeof(char) * (fixed_len + 1));
	if (!s1)
		return (NULL);
	while (s[start] && i < len)
	{
		s1[i] = s[start];
		i++;
		start++;
	}
	s1[i] = '\0';
	return (s1);
}

/*int	main(void)
{
	char	*s1;
	s1 = "";
	printf("%s", ft_substr(s1, 1, 1));
	return (0);
}*/
