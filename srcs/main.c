/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:25:26 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 09:10:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ft_string.h"
#include "lorem_generator.h"
#include "usage.h"

static size_t	__maxlen_in_lst(t_word_lst *const words)
{
	t_word const	*curr = words->head;
	size_t			maxlen;

	maxlen = 0;
	while (curr)
	{
		if (curr->len > maxlen)
			maxlen = curr->len;
		curr = curr->next;
	}
	return (maxlen);
}

static void	__database_clear(t_word_lst *database, size_t maxlen)
{
	while (maxlen--)
		word_lst_clear(database + maxlen);
	ft_memdel(&database);
}

static int	__process(t_opt *const opt)
{
	t_word_lst	*database;
	t_word_lst	words;
	size_t		maxlen;

	memset(&words, 0, sizeof(t_word_lst));
	if (load(&words, opt))
		return (EXIT_FAILURE);
	maxlen = __maxlen_in_lst(&words);
	if (organize(&words, &database, maxlen))
	{
		word_lst_clear(&words);
		return (EXIT_FAILURE);
	}
	if (generate(database, opt, maxlen))
	{
		__database_clear(database, maxlen);
		return (EXIT_FAILURE);
	}
	__database_clear(database, maxlen);
	return (EXIT_SUCCESS);
}

int	main(int const ac __attribute__((unused)), char const **av)
{
	t_opt	opt;

	srand(time(NULL));
	opt_init(&opt);
	if (opt_get(&opt, av + 1) || opt_check(&opt))
	{
		fprintf(stderr, "Error: invalid option\n");
		return (EXIT_FAILURE);
	}
	if (opt.flagfield & (1 << 0))
		printf(USAGE_H);
	else if (__process(&opt))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
