/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:19:54 by vrasatry          #+#    #+#             */
/*   Updated: 2025/02/01 17:57:45 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
		count++;
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*arr;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = ft_numlen(n);
	arr = (char *)malloc(sizeof(char) * (count + 1));
	if (!arr)
		return (NULL);
	arr[count--] = '\0';
	if (n < 0)
	{
		arr[0] = '-';
		n *= -1;
	}
	while (n)
	{
		arr[count--] = n % 10 + 48;
		n /= 10;
	}
	return (arr);
}

/*int	main(void)
{
	int	n = -534212475;
	printf("%s\n", ft_itoa(n));
	return (0);
}*/		
