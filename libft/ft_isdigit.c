/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:32:48 by vrasatry          #+#    #+#             */
/*   Updated: 2025/01/17 18:50:10 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int nb)
{
	if (nb <= '9' && nb >= '0')
		return (1);
	return (0);
}

/*int	main(void)
{
	char a = '	';
	char b = '4';
	printf ("%d\n%d", ft_isdigit(a), ft_isdigit(b)); 
	   return (0);
}*/		
