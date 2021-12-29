/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 06:41:20 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 09:01:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_string.h"
#include "lorem_generator.h"
#include "t_word_lst.h"

int	generate(t_word_lst	*const database, t_opt *const opt, size_t const maxlen)
{
	FILE	*stream;

	stream = stdout;
	if (opt->flagfield & (1 << 4))
		stream = fopen(opt->outfile, "w");
	if (!stream)
	{
		perror(__func__);
		return (EXIT_FAILURE);
	}
	if (stream != stdout && fclose(stream))
	{
		perror(__func__);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
