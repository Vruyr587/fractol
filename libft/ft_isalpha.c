/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:25:33 by vrasatry          #+#    #+#             */
/*   Updated: 2025/02/05 20:46:04 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int alpha)
{
	if ((alpha >= 'A' && alpha <= 'Z') || (alpha >= 'a' && alpha <= 'z'))
		return (1);
	return (0);
}

/*int	main(void)
{
	char a = 'a';
	char b = '4';
	printf("%d\n", ft_isalpha(a));
	printf("%d", ft_isalpha(b));

	return (0);
}*/
