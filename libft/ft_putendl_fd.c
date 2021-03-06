/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:55:12 by dverbyts          #+#    #+#             */
/*   Updated: 2016/11/24 19:55:14 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int z;

	if (s)
	{
		z = 0;
		while (s[z])
		{
			write(fd, &s[z], 1);
			z++;
		}
		write(fd, "\n", 1);
	}
}
