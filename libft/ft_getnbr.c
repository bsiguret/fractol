/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:50:25 by bsiguret          #+#    #+#             */
/*   Updated: 2018/01/24 14:19:24 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_getnbr(int *nbr, int size, char *str)
{
	char			**ret;
	int				count;

	count = 0;
	ret = ft_strsplit(str, ' ');
	while (count < size)
	{
		nbr[count] = ft_atoi(ret[count]);
		count++;
	}
	count = 0;
	while (ret[count])
		free(ret[count++]);
	free(ret);
}
