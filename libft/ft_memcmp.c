/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:49:01 by vrasatry          #+#    #+#             */
/*   Updated: 2025/01/24 00:00:10 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_1;
	unsigned char	*s2_2;	

	s1_1 = (unsigned char *) s1;
	s2_2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if ((s1_1[i] < s2_2[i]) || (s1_1[i] > s2_2[i]))
			return (s1_1[i] - s2_2[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "barevyngers";
	s2 = "barevaxpers";
	printf("%d\n", ft_memcmp(s1, s2, 11));
	return (0);
}*/
