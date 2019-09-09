/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 03:02:20 by kmills            #+#    #+#             */
/*   Updated: 2019/09/09 03:08:43 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t newsize)
{
	void	*new;

	new = ft_memalloc(newsize);
	new = ft_memcpy(new, ptr, newsize);
	free(ptr);
	return (new);
}
