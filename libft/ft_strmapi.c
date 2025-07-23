/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:24:54 by vrasatry          #+#    #+#             */
/*   Updated: 2025/02/01 17:59:17 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*arr;
	int		len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	while (i < ft_strlen(s))
	{
		arr[i] = (*f)(i, s[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

/*static char ft_foo(unsigned int i, char ch)
{
	return (i + ch);
}

int main(void)
{
	printf("%s\n",	ft_strmapi("Hello", ft_foo));
}*/
