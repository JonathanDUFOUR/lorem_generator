/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:59:55 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 06:17:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "ft_io.h"
#include "t_opt.h"
#include "t_word_lst.h"

static int	__init_stream_in(t_opt *const opt, FILE **const stream)
{
	if (opt->flagfield & (1 << 3))
		*stream = fopen(opt->infile, "r");
	if (!*stream)
	{
		perror(__func__);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	__init_stream_out(t_opt *const opt, FILE **const stream)
{
	if (opt->flagfield & (1 << 4))
		*stream = fopen(opt->outfile, "w");
	if (!*stream)
	{
		perror(__func__);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	__clear_stream(FILE *const stream)
{
	if (stream != stdin
		&& stream != stdout
		&& stream != stderr
		&& fclose(stream))
	{
		perror(__func__);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	generate(t_opt *const opt)
{
	t_word_lst	words;
	FILE		*stream_in;
	FILE		*stream_out;

	stream_in = stdin;
	stream_out = stdout;
	opt_print(opt);
	if (__init_stream_in(opt, &stream_in))
		return (EXIT_FAILURE);
	if (word_lst_get(&words, opt, stream_in))
	{
		__clear_stream(stream_in);
		return (EXIT_FAILURE);
	}
	if (__clear_stream(stream_in))
		return (EXIT_FAILURE);
	word_lst_print(&words);
	if (__init_stream_out(opt, &stream_out))
		return (EXIT_FAILURE);
	if (__clear_stream(stream_out))
		return (EXIT_FAILURE);
	word_lst_clear(&words);
	return (EXIT_SUCCESS);
}
