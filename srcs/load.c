/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:59:55 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 07:34:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "ft_io.h"
#include "t_opt.h"
#include "t_word_lst.h"

int	load(t_word_lst *const words, t_opt *const opt)
{
	FILE	*stream;

	stream = stdin;
	if (opt->flagfield & (1 << 3))
		stream = fopen(opt->infile, "r");
	if (!stream)
	{
		perror(__func__);
		return (EXIT_FAILURE);
	}
	if (word_lst_get(words, opt, stream))
	{
		if (stream != stdin)
			fclose(stream);
		perror(__func__);
		return (EXIT_FAILURE);
	}
	if (stream != stdin && fclose(stream))
	{
		perror(__func__);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
