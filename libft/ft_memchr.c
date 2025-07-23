/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:38:57 by vrasatry          #+#    #+#             */
/*   Updated: 2025/02/01 17:07:38 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	size_t			i;

	i = 0;
	s1 = (unsigned char *) s;
	while (i < n)
	{
		if (s1[i] == (unsigned char)c)
			return ((void *)&s1[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	*s1;
	int		c;

	s1 = "bargun";
	c = 97;
	printf("%s\n", ft_memchr(s1, c, 5));
	return (0);
}*/
