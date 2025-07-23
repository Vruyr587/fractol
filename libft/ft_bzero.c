/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:38:59 by vrasatry          #+#    #+#             */
/*   Updated: 2025/02/04 22:34:08 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	return (s);
}

/*int	main(void)
{
	char s[] = "helloman";
	printf("%s", ft_bzero(s, 1));
	return (0);
}*/
