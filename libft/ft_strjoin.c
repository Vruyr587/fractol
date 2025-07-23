/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:51:16 by vrasatry          #+#    #+#             */
/*   Updated: 2025/01/25 22:08:30 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!join)
		return (NULL);
	while (s1[i] != '\0')
		join[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		join[len1++] = s2[i++];
	join[i + j] = '\0';
	return (join);
}

/*int	main(void)
{
	char	*s1 = NULL;
	char	s2[100] = "antananarivu";
	printf("%s", ft_strjoin(s1, s2));
	return (0);
}*/
