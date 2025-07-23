/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:35:36 by vrasatry          #+#    #+#             */
/*   Updated: 2025/02/04 21:08:42 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	arr[11];

	i = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	else if (n == 0)
		write(fd, "0", 1);
	while (n != 0)
	{
		arr[i++] = n % 10 + '0';
		n /= 10;
	}
	i--;
	while (i != -1)
		write(fd, &arr[i--], 1);
}

/*int	main(void)
{
	int	nb = -2147483647;
	int	fd = 1;
	ft_putnbr_fd(nb, 1);
	return (0);
}*/
