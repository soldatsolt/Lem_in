/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_malloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:47:55 by kmills            #+#    #+#             */
/*   Updated: 2019/09/08 21:51:46 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*x_malloc(size_t size)
{
	void	*mem;
	if (!(mem = malloc(size)))
	{
		write(2, "MALLOC DOESN'T MALLOC\n", 23);
		exit(0);
	}
	ft_bzero(mem, size);
	return (mem);
}
