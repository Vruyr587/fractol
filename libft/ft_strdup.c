/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:54:21 by vrasatry          #+#    #+#             */
/*   Updated: 2025/02/04 19:22:42 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*arr;
	size_t	i;

	i = 0;
	arr = (char *)malloc((sizeof (char)) * (ft_strlen(s1) + 1));
	if (!arr)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

/*int	main(void)
{
	char	*s1;
	s1 = "nshanakeq eli libfts please";
	printf("%s\n", ft_strdup(s1));
	return (0);
}*/
