/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:16:35 by vrasatry          #+#    #+#             */
/*   Updated: 2025/02/15 15:17:54 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((char )c != *s)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

/*int	main(void)
{
	char s[100] = "poradzi gtnes 8 y";
	int	a = 'a';
	printf("%s", ft_strchr(s, a));
	return (0);
}*/
