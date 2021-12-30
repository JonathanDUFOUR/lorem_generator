/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_byte.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:58:41 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 03:15:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "t_word_lst.h"

int	gen_byte(t_word_lst *const database, t_opt *const opt, size_t const maxlen,
	FILE *stream)
{
	size_t const	range = opt->bytemax - opt->bytemin + 1;
	size_t const	cnt = (size_t)rand() % range + opt->bytemin;
	size_t			i;

	printf("%s:\n", __func__);
	i = 0;
	while (i < cnt)
	{
		++i;
	}
	return (EXIT_SUCCESS);
}
