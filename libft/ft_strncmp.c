/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:50:53 by vrasatry          #+#    #+#             */
/*   Updated: 2025/02/04 19:15:06 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n < ft_strlen(s1) || n < ft_strlen(s2))
	{
		while (i < n)
		{
			if (s1[i] == s2[i])
				i++;
			else
				return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		}
		return (0);
	}
	else
	{
		while (s1[i] != '\0' || s2[i] != '\0')
		{
			if (s1[i] == s2[i])
				i++;
			else
				return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		}
		return (0);
	}
}

/*
int	main(void)
{
	char s1[100] = "aaaaabdkgjhd";
	char s2[100] = "aaaaabdufgsf";
	printf("%d\n", ft_strncmp(s1, s2, 9));
	return (0);
}
*/
